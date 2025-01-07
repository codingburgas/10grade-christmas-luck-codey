#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>

namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();
    double getWithdrawAmount() const;
    void onWithdrawButtonClicked();

private:
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
