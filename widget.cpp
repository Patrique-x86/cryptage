#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QFile>
#include <QTextStream>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);




}

QString Widget::cryptage_decrytage(QString Text)
{
    QString text_Origin = ui->textEdit->toPlainText ();
    QString result  = text_Origin ;
    int l=0;
    int v = 0;

    ui->textEdit_2->setReadOnly (true);
    const QString key = ui->lineEdit->text ();
    this->pMarge = Text_.indexOf (key.at (indexKey).toUpper ());
    this->zIndex = (25 -  this->pMarge ) ;
    this->letterPosition = Text_.indexOf (key.at (0).toUpper ());
    if (key.length () >= 1){
        for (int i = 0; i < text_Origin.trimmed ().length (); i++) {
            if (text_Origin.at (i).isLetter ()) {

                 l = Text_.indexOf (text_Origin.at (i).toUpper ());
                 v =  Text_.indexOf (Text_.at(this->letterPosition).toUpper ());
                 int lv = l+v ;
                if (lv > 25) lv = lv-26 ;
                if(ui->radioButton_2->isChecked ()){
                    if(Text_.indexOf (text_Origin.at (i).toUpper ()) >= Text_.indexOf (key.at (indexKey).toUpper ()) ){
                       lv =  Text_.indexOf (text_Origin.at (i).toUpper ()) - this->pMarge ;
                    }else {
                        lv  = 1 + this->zIndex + Text_.indexOf (text_Origin.at (i).toUpper ());
                    }
                }
              result = result.replace (i,1,QChar(Text_.at(lv)));
             this->next ();
            }

        }
    }
    ui->textEdit_2->setReadOnly (false);
    return result ;
}

void Widget::next()
{
    QString key = ui->lineEdit->text ();
    indexKey++ ;
    if (indexKey > key.length ()-1) {
        indexKey = 0 ;
    }
    if ( key.length () == 1) {
        indexKey = 0 ;
    }
    this->pMarge = Text_.indexOf (key.at (indexKey).toUpper ());
    this->zIndex = (25 -  this->pMarge ) ;
    this->letterPosition = Text_.indexOf (key.at (indexKey).toUpper ());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName (this,"Choose file");
    ui->lineEdit_2->setText (fileName);


    if (fileName != ""){
        QFile file(fileName);
        if (file.open (QIODevice::ReadOnly | QIODevice::Text)){
           // file.rename ("new-doc");
            QTextStream in(&file);
            QString fileContent = in.readAll () ;
           // fileContent = "oopoopopoopoop";

            ui->textEdit->setText (fileContent);
            file.close ();
        }else {
            ui->lineEdit_2->setStyleSheet ("background-color: red");
        }
    }else {
        ui->lineEdit_2->setStyleSheet ("background-color: green");
    }


//ui->textEdit_2->setText (QString::number (ui->textEdit->toPlainText ().length ()));

}
void Widget::on_pushButton_3_clicked()
{
    ui->textEdit_2->setText (this->cryptage_decrytage (ui->lineEdit_2->text ()));
    this->letterPosition = 0 ;
    this->indexKey = 0 ;
    this->zIndex = 0 ;
    this->pMarge = 0 ;
}
void Widget::on_pushButton_2_clicked()
{
  QString dir = QFileDialog::getExistingDirectory (this,"Enregistrer le fichier");


      QFile file(dir +"/fichier-decrypter.txt");
      file.open (QIODevice::WriteOnly);
      QTextStream out(&file);
      out << ui->textEdit_2->toPlainText ();
      file.close ();
}


