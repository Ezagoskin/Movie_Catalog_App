#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QPainter>


namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget* parent = nullptr);

    ~AboutDialog();

private:
    Ui::AboutDialog* ui;

protected:
    void paintEvent(QPaintEvent *e);
};

#endif// ABOUTDIALOG_H
