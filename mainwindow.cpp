#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,addbox(new addBox(this))
    ,findbox(new findBox(this))
    ,updatebox(new updateBox(this))
{
    ui->setupUi(this);
    connect(ui->pushButton,QPushButton::clicked,this, &MainWindow::addFun);
    connect(addbox,&addBox::enterInfo,this,&MainWindow::getInfo);
    connect(ui->pushButton_2,&QPushButton::clicked,this, &MainWindow::searchFun);
    connect(findbox, &findBox::onSearch,this,&MainWindow::onFind);
    connect(ui->pushButton_3,&QPushButton::clicked,this, &MainWindow::updateFun);
    connect(updatebox, &updateBox::newSub,this,&MainWindow::onUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addbox;
    delete findbox;
    delete updatebox;
}

QStringList rollNoList;
QStringList nameList;
QStringList subList;
bool found=false;

void MainWindow::addFun()
{
    addbox->show();
}

void MainWindow::getInfo(const QString &rn, const QString &n, const QString &s){
    rollNoList.append(rn);
    nameList.append(n);
    subList.append(s);
    QMessageBox::information(this,"Success",
                             "Student Added Successfully!");
}



void MainWindow::searchFun()
{
    findbox->show();
}

void MainWindow::onFind(const QString &rn){
    for(int i=0; i<rollNoList.length() ; i++){
        if(rn==rollNoList[i]){
            found=true;
            QMessageBox::information(this,"Success",
                            "RollNo: "+rollNoList[i]+ "\n"
                            "Name of Student: "+nameList[i]+"\n"
                            "Subject of Student: "+subList[i]);
            break;
        }
    }
    if(!found){
        QMessageBox::information(this,"Error",
                            "Sorry inviled roll number!");
    }
}


void MainWindow::updateFun()
{
    updatebox->show();
}

void MainWindow::onUpdate(const QString &rn, const QString &s){
    for(int i=0; i<rollNoList.length(); i++){
        if(rn==rollNoList[i]){
            found=true;
            subList[i]=s;
            QMessageBox::information(this,"Success",
                       "Subject of Student: "+subList[i]);
            break;
        }
    }
    if(!found){
        QMessageBox::information(this,"Error",
                                 "Sorry inviled roll number!");
    }
}
