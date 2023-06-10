#include "editrowdialog.h"
#include "ui_editrowdialog.h"

EditRowDialog::EditRowDialog(QList<QVariant>& dataRow, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::EditRowDialog)
{
    ui->setupUi(this);
    ui->lineEditID->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), ui->lineEditID));
    ui->lineEditTitle->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditTitle));
    ui->lineEditDescription->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditDescription));
    ui->lineEditGenre->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditGenre));

    ui->lineEditID->setText(dataRow[0].toString());
    ui->lineEditTitle->setText(dataRow[1].toString());
    ui->lineEditDescription->setText(dataRow[2].toString());
    ui->lineEditGenre->setText(dataRow[3].toString());
    ui->spinBoxYear->setValue(dataRow[4].toInt());
    ui->spinBoxRunningTime->setValue(dataRow[5].toInt());
    ui->comboBoxType->setCurrentIndex(dataRow[6] == "tv");
    if (dataRow[7].toBool())
    {
        ui->checkBoxFavorite->setCheckState(Qt::Checked);
    }
}

EditRowDialog::~EditRowDialog()
{
    delete ui;
}


QList<QVariant> EditRowDialog::getDataRow()
{
    QList<QVariant> dataRow;
    dataRow.append(ui->lineEditID->text().toULongLong());
    dataRow.append(ui->lineEditTitle->text());
    dataRow.append(ui->lineEditDescription->text());
    dataRow.append(ui->lineEditGenre->text());
    dataRow.append(ui->spinBoxYear->value());
    dataRow.append(ui->spinBoxRunningTime->value());
    dataRow.append(ui->comboBoxType->currentText());
    dataRow.append(ui->checkBoxFavorite->isChecked());

    return dataRow;
}
