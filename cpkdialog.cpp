#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>

#include "cpkdialog.h"
#include "ui_cpkdialog.h"

#include "progressdialog.h"

#include "debug.h"

CpkDialog::CpkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CpkDialog)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    set_debug_level(2);

    QDir::setCurrent(qApp->applicationDirPath());
    config.Load();

    ui->cpkInputEdit->setText(Utils::StdStringToQString(config.cpk_input));
    ui->extractDirEdit->setText(Utils::StdStringToQString(config.folder_output));

    if (qApp->arguments().size() >= 2)
    {
        bool success = true;

        for (int i = 1; i < qApp->arguments().size(); i++)
        {
            QString path = qApp->arguments()[i];
            std::string std_path = Utils::QStringToStdString(path);

            if (Utils::FileExists(std_path))
            {
                int ext_pos = path.lastIndexOf('.');

                if (ext_pos != -1)
                {
                    QString dir_path = path.left(ext_pos);

                    //DPRINTF("Now doing %s\n", path.toStdString().c_str());

                    if (!ExtractFile(path, dir_path, true))
                    {
                        success = false;
                        break;
                    }
                }
            }
            else
            {
                DPRINTF("Doesn't exist: \"%s\"\n", std_path.c_str());
            }
        }

        exit((success) ? 0 : -1);
    }
}

CpkDialog::~CpkDialog()
{
    delete ui;
}

bool CpkDialog::ExtractFile(const QString &file, const QString &dir,  bool param_mode)
{
    std::string file_std = Utils::QStringToStdString(file);
    std::string dir_std = Utils::QStringToStdString(dir);

    if (!param_mode && Utils::DirExists(dir_std) && !Utils::IsDirectoryEmpty(dir_std, false))
    {
        if (QMessageBox::question(this, "Use this directory?", "That directory is not empty.\nDo you want to extract the files there?",
                                  QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No), QMessageBox::No) == QMessageBox::No)
        {
            return false;
        }
    }

    CpkFile cpk;

    if (!cpk.LoadFromFile(file_std))
        return false;

    if (cpk.GetNumFiles() == 0)
    {
        UPRINTF("That cpk file is empty. Nothing to extract.");
        return true;
    }

    ProgressDialog dialog((param_mode) ? nullptr : this);
    dialog.SetExtractParams(cpk, dir_std);

    if (param_mode)
    {
        const QRect screen = QApplication::desktop()->screenGeometry();
        dialog.move(screen.center() - this->rect().center());

        dialog.setWindowTitle("Extracting " + Utils::StdStringToQString(Utils::GetFileNameString(file_std)));
    }

    int troolean = dialog.exec();
    if (troolean > 0)
    {
        if (!param_mode)
            UPRINTF("File extracted succesfully.");
    }
    else if (troolean == 0)
    {
        DPRINTF("Extract cancelled by user.");
        return false;
    }
    else
    {
        DPRINTF("Error extracting cpk file.");
        return false;
    }

    return true;
}

void CpkDialog::on_cpkInputButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Select .cpk file", ui->cpkInputEdit->text(), "CPK files (*.cpk)");

    if (!file.isNull())
        ui->cpkInputEdit->setText(file);
}

void CpkDialog::on_extractDirButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select output directory", ui->extractDirEdit->text());

    if (!dir.isNull())
        ui->extractDirEdit->setText(dir);
}

void CpkDialog::on_extractButton_clicked()
{
    QString file = ui->cpkInputEdit->text();
    QString dir = ui->extractDirEdit->text();

    if (file.length() == 0)
    {
        DPRINTF("CPK File field is empty.");
        return;
    }

    if (dir.length() == 0)
    {
        DPRINTF("Save path field is empty.");
        return;
    }

    ExtractFile(file, dir);
}

void CpkDialog::ProcessShutdown()
{
    config.cpk_input = Utils::QStringToStdString(ui->cpkInputEdit->text());
    config.folder_output = Utils::QStringToStdString(ui->extractDirEdit->text());
    config.Save();
}

void CpkDialog::closeEvent(QCloseEvent *event)
{
    ProcessShutdown();
    event->accept();
}
