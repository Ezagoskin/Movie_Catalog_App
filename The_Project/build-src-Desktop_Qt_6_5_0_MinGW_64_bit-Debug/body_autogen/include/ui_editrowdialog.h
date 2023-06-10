/********************************************************************************
** Form generated from reading UI file 'editrowdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROWDIALOG_H
#define UI_EDITROWDIALOG_H

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

class Ui_EditRowDialog
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

    void setupUi(QDialog *EditRowDialog)
    {
        if (EditRowDialog->objectName().isEmpty())
            EditRowDialog->setObjectName("EditRowDialog");
        EditRowDialog->resize(400, 306);
        formLayout = new QFormLayout(EditRowDialog);
        formLayout->setObjectName("formLayout");
        labelTitle = new QLabel(EditRowDialog);
        labelTitle->setObjectName("labelTitle");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTitle);

        lineEditTitle = new QLineEdit(EditRowDialog);
        lineEditTitle->setObjectName("lineEditTitle");
        lineEditTitle->setMaxLength(32767);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTitle);

        lineEditGenre = new QLineEdit(EditRowDialog);
        lineEditGenre->setObjectName("lineEditGenre");
        lineEditGenre->setMaxLength(64);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditGenre);

        labelYear = new QLabel(EditRowDialog);
        labelYear->setObjectName("labelYear");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelYear);

        spinBoxYear = new QSpinBox(EditRowDialog);
        spinBoxYear->setObjectName("spinBoxYear");
        spinBoxYear->setMinimum(1500);
        spinBoxYear->setMaximum(3000);
        spinBoxYear->setValue(2023);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxYear);

        labelRunningTime = new QLabel(EditRowDialog);
        labelRunningTime->setObjectName("labelRunningTime");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelRunningTime);

        spinBoxRunningTime = new QSpinBox(EditRowDialog);
        spinBoxRunningTime->setObjectName("spinBoxRunningTime");
        spinBoxRunningTime->setMaximum(262144);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxRunningTime);

        labelType = new QLabel(EditRowDialog);
        labelType->setObjectName("labelType");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelType);

        comboBoxType = new QComboBox(EditRowDialog);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxType);

        labelDescription = new QLabel(EditRowDialog);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelDescription);

        lineEditDescription = new QLineEdit(EditRowDialog);
        lineEditDescription->setObjectName("lineEditDescription");
        lineEditDescription->setMaxLength(1024);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditDescription);

        buttonBox = new QDialogButtonBox(EditRowDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(8, QFormLayout::SpanningRole, buttonBox);

        labelID = new QLabel(EditRowDialog);
        labelID->setObjectName("labelID");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelID);

        labelGenre = new QLabel(EditRowDialog);
        labelGenre->setObjectName("labelGenre");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelGenre);

        lineEditID = new QLineEdit(EditRowDialog);
        lineEditID->setObjectName("lineEditID");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditID);

        checkBoxFavorite = new QCheckBox(EditRowDialog);
        checkBoxFavorite->setObjectName("checkBoxFavorite");

        formLayout->setWidget(0, QFormLayout::LabelRole, checkBoxFavorite);


        retranslateUi(EditRowDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditRowDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditRowDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditRowDialog);
    } // setupUi

    void retranslateUi(QDialog *EditRowDialog)
    {
        EditRowDialog->setWindowTitle(QCoreApplication::translate("EditRowDialog", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("EditRowDialog", "Title", nullptr));
        lineEditTitle->setInputMask(QString());
        labelYear->setText(QCoreApplication::translate("EditRowDialog", "Year", nullptr));
        labelRunningTime->setText(QCoreApplication::translate("EditRowDialog", "Running time", nullptr));
        labelType->setText(QCoreApplication::translate("EditRowDialog", "Type", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("EditRowDialog", "movie", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("EditRowDialog", "tv", nullptr));

        labelDescription->setText(QCoreApplication::translate("EditRowDialog", "Description", nullptr));
        labelID->setText(QCoreApplication::translate("EditRowDialog", "Hotstar ID", nullptr));
        labelGenre->setText(QCoreApplication::translate("EditRowDialog", "Genre", nullptr));
        checkBoxFavorite->setText(QCoreApplication::translate("EditRowDialog", "Favorite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRowDialog: public Ui_EditRowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROWDIALOG_H
