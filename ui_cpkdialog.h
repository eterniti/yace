/********************************************************************************
** Form generated from reading UI file 'cpkdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPKDIALOG_H
#define UI_CPKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CpkDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cpkInputEdit;
    QLineEdit *extractDirEdit;
    QPushButton *cpkInputButton;
    QPushButton *extractDirButton;
    QPushButton *extractButton;

    void setupUi(QDialog *CpkDialog)
    {
        if (CpkDialog->objectName().isEmpty())
            CpkDialog->setObjectName(QStringLiteral("CpkDialog"));
        CpkDialog->resize(414, 175);
        label = new QLabel(CpkDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(31, 30, 47, 13));
        label_2 = new QLabel(CpkDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 16));
        cpkInputEdit = new QLineEdit(CpkDialog);
        cpkInputEdit->setObjectName(QStringLiteral("cpkInputEdit"));
        cpkInputEdit->setGeometry(QRect(80, 26, 221, 20));
        extractDirEdit = new QLineEdit(CpkDialog);
        extractDirEdit->setObjectName(QStringLiteral("extractDirEdit"));
        extractDirEdit->setGeometry(QRect(80, 66, 221, 20));
        cpkInputButton = new QPushButton(CpkDialog);
        cpkInputButton->setObjectName(QStringLiteral("cpkInputButton"));
        cpkInputButton->setGeometry(QRect(310, 25, 68, 23));
        extractDirButton = new QPushButton(CpkDialog);
        extractDirButton->setObjectName(QStringLiteral("extractDirButton"));
        extractDirButton->setGeometry(QRect(310, 65, 68, 23));
        extractButton = new QPushButton(CpkDialog);
        extractButton->setObjectName(QStringLiteral("extractButton"));
        extractButton->setGeometry(QRect(170, 120, 75, 23));

        retranslateUi(CpkDialog);

        QMetaObject::connectSlotsByName(CpkDialog);
    } // setupUi

    void retranslateUi(QDialog *CpkDialog)
    {
        CpkDialog->setWindowTitle(QApplication::translate("CpkDialog", "YACE", 0));
        label->setText(QApplication::translate("CpkDialog", "CPK File:", 0));
        label_2->setText(QApplication::translate("CpkDialog", "Save path:", 0));
        cpkInputButton->setText(QApplication::translate("CpkDialog", "Browse", 0));
        extractDirButton->setText(QApplication::translate("CpkDialog", "Browse", 0));
        extractButton->setText(QApplication::translate("CpkDialog", "Extract", 0));
    } // retranslateUi

};

namespace Ui {
    class CpkDialog: public Ui_CpkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPKDIALOG_H
