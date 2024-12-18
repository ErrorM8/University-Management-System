#ifndef ADDBOX_H
#define ADDBOX_H

#include <QDialog>

namespace Ui {
class addBox;
}

class addBox : public QDialog
{
    Q_OBJECT

public:
    explicit addBox(QWidget *parent = nullptr);
    ~addBox();
signals:
    void enterInfo(const QString &rn, const QString &n, const QString &s);
private slots:
    void getVal();

private:
    Ui::addBox *ui;
};

#endif // ADDBOX_H
