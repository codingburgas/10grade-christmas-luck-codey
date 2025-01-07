#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();
    double getDepositAmount() const;

private slots:
    void onDepositButtonClicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
