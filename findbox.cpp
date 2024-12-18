#include "findbox.h"
#include "ui_findbox.h"

findBox::findBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findBox)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this, &searchStd);
}

findBox::~findBox()
{
    delete ui;
}

void findBox::searchStd()
{
    QString stdRollNo=ui->lineEdit->text();
    emit onSearch(stdRollNo);
}

