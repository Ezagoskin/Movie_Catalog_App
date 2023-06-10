/********************************************************************************
** Form generated from reading UI file 'addrowdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROWDIALOG_H
#define UI_ADDROWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddRowDialog
{
public:
    QFormLayout *formLayout;
    QLabel *labelTitle;
    QLineEdit *lineEditTitle;
    QLineEdit *lineEditGenre;
    QLabel *labelYear;
    QSpinBox *spinBoxYear;
    QLabel *labelRunningTime;
    QSpinBox *spinBoxRunningTime;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QLabel *labelDescription;
    QLineEdit *lineEditDescription;
    QDialogButtonBox *buttonBox;
    QLabel *labelID;
    QLabel *labelGenre;
    QLineEdit *lineEditID;
    QCheckBox *checkBoxFavorite;

    void setupUi(QDialog *AddRowDialog)
    {
        if (AddRowDialog->objectName().isEmpty())
            AddRowDialog->setObjectName("AddRowDialog");
        AddRowDialog->resize(400, 306);
        formLayout = new QFormLayout(AddRowDialog);
        formLayout->setObjectName("formLayout");
        labelTitle = new QLabel(AddRowDialog);
        labelTitle->setObjectName("labelTitle");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTitle);

        lineEditTitle = new QLineEdit(AddRowDialog);
        lineEditTitle->setObjectName("lineEditTitle");
        lineEditTitle->setMaxLength(32767);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTitle);

        lineEditGenre = new QLineEdit(AddRowDialog);
        lineEditGenre->setObjectName("lineEditGenre");
        lineEditGenre->setMaxLength(64);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditGenre);

        labelYear = new QLabel(AddRowDialog);
        labelYear->setObjectName("labelYear");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelYear);

        spinBoxYear = new QSpinBox(AddRowDialog);
        spinBoxYear->setObjectName("spinBoxYear");
        spinBoxYear->setMinimum(0);
        spinBoxYear->setMaximum(99999);
        spinBoxYear->setValue(2023);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxYear);

        labelRunningTime = new QLabel(AddRowDialog);
        labelRunningTime->setObjectName("labelRunningTime");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelRunningTime);

        spinBoxRunningTime = new QSpinBox(AddRowDialog);
        spinBoxRunningTime->setObjectName("spinBoxRunningTime");
        spinBoxRunningTime->setMaximum(999999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxRunningTime);

        labelType = new QLabel(AddRowDialog);
        labelType->setObjectName("labelType");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelType);

        comboBoxType = new QComboBox(AddRowDialog);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxType);

        labelDescription = new QLabel(AddRowDialog);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelDescription);

        lineEditDescription = new QLineEdit(AddRowDialog);
        lineEditDescription->setObjectName("lineEditDescription");
        lineEditDescription->setMaxLength(1024);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditDescription);

        buttonBox = new QDialogButtonBox(AddRowDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(8, QFormLayout::SpanningRole, buttonBox);

        labelID = new QLabel(AddRowDialog);
        labelID->setObjectName("labelID");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelID);

        labelGenre = new QLabel(AddRowDialog);
        labelGenre->setObjectName("labelGenre");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelGenre);

        lineEditID = new QLineEdit(AddRowDialog);
        lineEditID->setObjectName("lineEditID");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditID);

        checkBoxFavorite = new QCheckBox(AddRowDialog);
        checkBoxFavorite->setObjectName("checkBoxFavorite");

        formLayout->setWidget(0, QFormLayout::LabelRole, checkBoxFavorite);


        retranslateUi(AddRowDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddRowDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddRowDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddRowDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRowDialog)
    {
        AddRowDialog->setWindowTitle(QCoreApplication::translate("AddRowDialog", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("AddRowDialog", "Title", nullptr));
        lineEditTitle->setInputMask(QString());
        labelYear->setText(QCoreApplication::translate("AddRowDialog", "Year", nullptr));
        labelRunningTime->setText(QCoreApplication::translate("AddRowDialog", "Running time", nullptr));
        labelType->setText(QCoreApplication::translate("AddRowDialog", "Type", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("AddRowDialog", "movie", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("AddRowDialog", "tv", nullptr));

        labelDescription->setText(QCoreApplication::translate("AddRowDialog", "Description", nullptr));
        labelID->setText(QCoreApplication::translate("AddRowDialog", "Hotstar ID", nullptr));
        labelGenre->setText(QCoreApplication::translate("AddRowDialog", "Genre", nullptr));
        checkBoxFavorite->setText(QCoreApplication::translate("AddRowDialog", "Favorite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRowDialog: public Ui_AddRowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROWDIALOG_H
