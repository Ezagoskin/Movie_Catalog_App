#ifndef EDITROWDIALOG_H
#define EDITROWDIALOG_H

#include <QDialog>

namespace Ui {
    class EditRowDialog;
}

class EditRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditRowDialog(QList <QVariant>& dataRow, QWidget* parent = nullptr);

    ~EditRowDialog();

    QList <QVariant> getDataRow();

private:
    Ui::EditRowDialog* ui;
};

#endif // EDITROWDIALOG_H
