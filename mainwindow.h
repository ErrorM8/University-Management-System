#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addbox.h"
#include "findbox.h"
#include <updatebox.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addFun();
    void getInfo(const QString &rn, const QString &n, const QString &s);

    void searchFun();
    void onFind(const QString &rn);

    void updateFun();
    void onUpdate(const QString &rn, const QString &s);

private:
    Ui::MainWindow *ui;
    addBox *addbox;
    findBox *findbox;
    updateBox *updatebox;
};
#endif // MAINWINDOW_H
