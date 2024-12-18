#ifndef FINDBOX_H
#define FINDBOX_H

#include <QDialog>

namespace Ui {
class findBox;
}

class findBox : public QDialog
{
    Q_OBJECT
signals:
    void onSearch(const QString &rn);

public:
    explicit findBox(QWidget *parent = nullptr);
    ~findBox();

private slots:
    void searchStd();

private:
    Ui::findBox *ui;
};

#endif // FINDBOX_H
