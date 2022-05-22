#ifndef CPKDIALOG_H
#define CPKDIALOG_H

#include <QDialog>
#include "IniFile.h"
#include "CpkFile.h"

namespace Ui {
class CpkDialog;
}

class CpkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CpkDialog(QWidget *parent = 0);
    ~CpkDialog();

private slots:
    void on_cpkInputButton_clicked();

    void on_extractDirButton_clicked();

    void on_extractButton_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::CpkDialog *ui;

    bool ExtractFile(const QString &file, const QString &dir, bool param_mode=false);
    void ProcessShutdown();

    struct Config
    {
        std::string cpk_input;
        std::string folder_output;

        void Load()
        {
            IniFile ini;

            // Ignore errors (default values returned)
            ini.LoadFromFile("yace_config.ini", false);

            ini.GetStringValue("General", "cpk_input", cpk_input);
            ini.GetStringValue("General", "folder_output", folder_output);
        }

        void Save()
        {
            IniFile ini;

            ini.LoadFromFile("yace_config.ini", false);

            ini.SetStringValue("General", "cpk_input", cpk_input);
            ini.SetStringValue("General", "folder_output", folder_output);

            ini.SaveToFile("yace_config.ini");
        }

    } config;
};

#endif // CPKDIALOG_H
