#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

    bool loginUser(const QString &username, const QString &password, QString &role);

    QString getUsername() const;
    QString getPassword() const;

private slots:
    void on_loginButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::AuthWindow *ui;
    QString username;
    QString password;
};

#endif // AUTHWINDOW_H
