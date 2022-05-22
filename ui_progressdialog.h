/********************************************************************************
** Form generated from reading UI file 'progressdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QLabel *progressLabel;
    QProgressBar *progressBar;
    QPushButton *cancelButton;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QStringLiteral("ProgressDialog"));
        ProgressDialog->resize(433, 144);
        progressLabel = new QLabel(ProgressDialog);
        progressLabel->setObjectName(QStringLiteral("progressLabel"));
        progressLabel->setGeometry(QRect(30, 25, 351, 16));
        progressBar = new QProgressBar(ProgressDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 50, 391, 23));
        progressBar->setValue(0);
        cancelButton = new QPushButton(ProgressDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(170, 100, 75, 23));

        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "YACE", 0));
        progressLabel->setText(QApplication::translate("ProgressDialog", "TextLabel", 0));
        cancelButton->setText(QApplication::translate("ProgressDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
