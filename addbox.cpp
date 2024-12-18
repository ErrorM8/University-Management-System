#include "addbox.h"
#include "ui_addbox.h"

addBox::addBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addBox)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&addBox::getVal);
}

addBox::~addBox()
{
    delete ui;
}

void addBox::getVal()
{
    QString rollNo=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    QString subject=ui->lineEdit_3->text();
    emit enterInfo(rollNo,name,subject);
}

