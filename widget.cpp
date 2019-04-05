#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_image_clicked()
{
    filename = QFileDialog::getOpenFileName(this, tr("Open Directory"),"/home","Image(*.png)");
    imageSelected=true;
    QString status="File selected:";
    status.append(filename);
    ui->status->setText(status);
}

void Widget::on_calculate_clicked()
{
    if(imageSelected)
    {
        QImage image(filename);

        int whiteCount=0,blackCount=0,otherCount=0;
        int totalCount;

         for(int i=0; i<image.height(); i++)
         {
            QRgb *pixel =reinterpret_cast<QRgb *>(image.scanLine(i));
            QRgb *end   =pixel+image.width();

            while(pixel!=end)
            {
                if(qRed(*pixel)==255 && qGreen(*pixel)==255 && qBlue(*pixel)==255)
                {
                    whiteCount++;
                }

                if(qRed(*pixel)==0 && qGreen(*pixel)==0 && qBlue(*pixel)==0)
                {
                    blackCount++;
                }
                else
                {
                    otherCount++;
                }
                pixel++;
            }

         }
         totalCount=whiteCount+blackCount+otherCount;
         ui->noOfWhitePixels->setNum(whiteCount);
         ui->noOfBlackPixels->setNum(blackCount);
         ui->noOfOtherPixels->setNum(otherCount);
         ui->totalPixels->setNum(totalCount);

      }
    else
    {
     QMessageBox msgBox;
     msgBox.setText("Please select a file first");
     msgBox.exec();
    }
}





