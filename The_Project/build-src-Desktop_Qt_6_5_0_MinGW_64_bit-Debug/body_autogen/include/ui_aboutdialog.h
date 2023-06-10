/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelAbout;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        AboutDialog->resize(800, 601);
        AboutDialog->setMinimumSize(QSize(800, 400));
        AboutDialog->setMaximumSize(QSize(800, 601));
        gridLayout = new QGridLayout(AboutDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        labelAbout = new QLabel(AboutDialog);
        labelAbout->setObjectName("labelAbout");
        labelAbout->setMinimumSize(QSize(250, 0));
        labelAbout->setMaximumSize(QSize(250, 16777215));
        labelAbout->setWordWrap(true);

        gridLayout->addWidget(labelAbout, 1, 0, 1, 1);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "Dialog", nullptr));
        labelAbout->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Database Project</span></p><p>This is a project for managing Disney + Hotstar Tv and Movie Catalog. It allows to view, add, edit, remove and download data. Various types of sorting and filtering are available too.</p><p><br/></p><p>Shortcuts</p><p>Ctrl + S: Save</p><p>Ctrl + I: Information</p><p>Ctrl + A: Add record</p><p>Ctrl + E: Edit record</p><p>Ctrl + R: Remove record</p><p>Ctrl + F: To favorites</p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/><br/></p><p>Author: Student#1661<br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
