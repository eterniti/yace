#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QThreadPool>
#include "CpkFile.h"

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = 0);
    ~ProgressDialog();

    int exec() override;
    void SetExtractParams(const CpkFile &cpk, const std::string &extract_path);

public slots:

    void onProgressChanged(int value);
    void reject() override;
    void onError();
    void onJobDone();

signals:

    void cancelSignal();


private slots:
    void on_cancelButton_clicked();

private:
    Ui::ProgressDialog *ui;

    const CpkFile *extract_cpk;
    std::string extract_path;
    bool use_kb;

    int num_files;
};

class ExtractJob : public QObject, public QRunnable
{
    Q_OBJECT

public:

    ExtractJob(const CpkFile *cpk, const std::string &extract_path, bool use_kb) : QRunnable(), extract_cpk(cpk), extract_path(extract_path), use_kb(use_kb) { }

    void run();

public slots:

    void onCancel();

signals:

    void progressChanged(int value);
    void errorSignal();
    void jobDone();

private:

    const CpkFile *extract_cpk;
    std::string extract_path;
    bool use_kb;

    bool cancel = false;
};

#endif // PROGRESSDIALOG_H
