#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QFileDialog>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_image_clicked();

    void on_calculate_clicked();

private:
    Ui::Widget *ui;
    bool imageSelected=false;
    QString filename;
};

#endif // WIDGET_H
