#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

void AboutDialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen penBlack(Qt::black, 5);
    QPen penRed(Qt::red, 5);
    QPen penGreen(Qt::green, 25);
    QPen penBlue(Qt::blue, 5);

    int x0 = 350;
    int y0 = 150;
    int width = 300;
    int height = 300;
    QRect rect(x0, y0, width, height);
    int xCenter = x0 + width/2;
    int yCenter = y0 + height/2;

    painter.setPen(penBlack);
    painter.drawRect(rect);

    painter.translate(xCenter, yCenter);
    painter.rotate(45);
    painter.translate(-xCenter, -yCenter);
    painter.setPen(penRed);
    painter.drawRect(rect);
    painter.drawPoint(xCenter, yCenter);

    painter.translate(xCenter, yCenter);
    painter.scale(0.5,0.5);
    painter.translate(-xCenter, -yCenter);
    painter.drawRect(rect);

    painter.resetTransform();
    painter.setPen(penGreen);
    painter.drawEllipse(x0 + width/4, y0 + height/4, 150, 150);
    painter.translate(xCenter, yCenter);
    painter.shear(0.5, 0.5);
    painter.translate(-xCenter, -yCenter);
    painter.setPen(penBlue);
    painter.drawRect(rect);

    painter.resetTransform();
    painter.translate(xCenter, yCenter);
    painter.rotate(45);
    painter.translate(-xCenter, -yCenter);
    painter.drawEllipse(x0 + width/4, y0 + height/4, 150, 150);

    painter.resetTransform();
    painter.translate(xCenter, yCenter);
    painter.shear(-0.5, -0.5);
    painter.translate(-xCenter, -yCenter);
    painter.drawRect(rect);
}

AboutDialog::~AboutDialog()
{
     delete ui;
}


