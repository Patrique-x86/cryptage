#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QString cryptage_decrytage(QString Text);
    void next();
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QFileDialog *dialog ;
    QString const Text_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letterPosition = 0 ;
    int indexKey = 0 ;
    int zIndex = 0 ;
    int pMarge = 0;
};
#endif // WIDGET_H
