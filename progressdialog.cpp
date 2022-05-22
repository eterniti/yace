#include "progressdialog.h"
#include "ui_progressdialog.h"


ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::SetExtractParams(const CpkFile &cpk, const std::string &extract_path)
{
    extract_cpk = &cpk;
    this->extract_path = extract_path;

    uint64_t total_size = cpk.GetContentSize();
    if (total_size > 0x7FFFFFFF)
    {
        total_size /= 1024;
        use_kb = true;
    }
    else
    {
        use_kb = false;
    }

    ui->progressBar->setMaximum(total_size);
    num_files = 0;
    ui->progressLabel->setText("Extracting file " + QString("%1/%2").arg(num_files).arg(cpk.GetNumFiles()));
    setWindowTitle("Extracting...");
}

int ProgressDialog::exec()
{
    ExtractJob *job = new ExtractJob(extract_cpk, extract_path, use_kb);

    connect(job, SIGNAL(progressChanged(int)), this, SLOT(onProgressChanged(int)));
    connect(job, SIGNAL(errorSignal()), this, SLOT(onError()));
    connect(job, SIGNAL(jobDone()), this, SLOT(onJobDone()));
    connect(this, SIGNAL(cancelSignal()), job, SLOT(onCancel()));

    QThreadPool::globalInstance()->start(job);

    return QDialog::exec();
}

void ProgressDialog::onProgressChanged(int value)
{
    ui->progressBar->setValue(ui->progressBar->value()+value);
    num_files++;

    ui->progressLabel->setText("Extracting file " + QString("%1/%2").arg(num_files).arg(extract_cpk->GetNumFiles()));
}

void ProgressDialog::reject()
{
    ui->progressLabel->setText("Cancelling...");
    emit cancelSignal();

    QThreadPool::globalInstance()->waitForDone();
    done(0);
}

void ProgressDialog::onError()
{
    QThreadPool::globalInstance()->waitForDone();
    done(-1);
}

void ProgressDialog::onJobDone()
{
    QThreadPool::globalInstance()->waitForDone();
    done(1);
}

void ProgressDialog::on_cancelButton_clicked()
{
    reject();
}

void ExtractJob::run()
{
    const CpkFile &cpk = *extract_cpk;

    for (uint32_t i = 0; i < cpk.GetNumFiles(); i++)
    {
        if (cancel)
            return;

        if (!cpk.ExtractFile(i, extract_path, true))
        {
            emit errorSignal();
            return;
        }

        uint64_t size;

        if (cpk.GetFileSize(i, &size))
        {
            if (use_kb)
                size /= 1024;

            emit progressChanged(size);
        }
    }

    emit jobDone();
}

void ExtractJob::onCancel()
{
    cancel = true;
}


