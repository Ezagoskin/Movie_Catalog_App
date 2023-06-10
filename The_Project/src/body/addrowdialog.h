#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>

namespace Ui {
    class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(QWidget* parent = nullptr);

    ~AddRowDialog();

    QList <QVariant> getDataRow();

private:
    Ui::AddRowDialog* ui;
};

#endif // ADDROWDIALOG_H
