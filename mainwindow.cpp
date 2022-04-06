#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)   // Constructeur
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/mamri/Downloads/Qt/smartlockers");            //un instance qui a comme argument l'emplacement de notre image sur interface
    int w = ui->label_img->width();                                     //On a cree ces deux variable pour avoir le largeur et l'hauteur du label_img
    int h = ui->label_img->height();
    ui->label_img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));      // placer image sur le label_img

}

MainWindow::~MainWindow()    //deconstructeur
{
    delete ui;
}


void MainWindow::on_pushButton_connexion_clicked()
{
    QString ident = ui->lineEdit_IDENT->text();                       // Identifiant est de type string, et cette ligne de code est pour pouvoir saisir l'identifiant
    QString mdp = ui->lineEdit_MDP->text();                           // Mot de passe est de type string, et cette ligne de code est pour pouvoir saisir mot de passe

    if(ident == "test" && mdp == "test123") // On a mis cette une condition si identifiant et le mot de passe sont correct
    {
       QMessageBox::information(this, "login", "Identifiant et Mot de passe sont corrects");   // si la condition est juste ça va m'afficher que idenfiant et le mot de passe sont corrects
       hide();                                             // ces trois ligne pour acces a une page d'acceuille "   WELCOME TO SMARTLOCKERS  " et la page d'identification va disparaitre
       dialog = new Dialog(this);
       dialog->show();

    }
    else{
        QMessageBox::warning(this, "login", "Identifiant ou le Mot de passe est incorrect");    //si la condition est faux, ça va m'affiche un message de Warning
                                                                                                  //en disant que Identifiant ou le mot de passe est incorrect
    }

}
