#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
    ui->lineEditID->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), ui->lineEditID));
    ui->lineEditTitle->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditTitle));
    ui->lineEditDescription->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditDescription));
    ui->lineEditGenre->setValidator(new QRegularExpressionValidator(QRegularExpression("^[^;\"]*$"), ui->lineEditGenre));
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}


QList<QVariant> AddRowDialog::getDataRow()
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
