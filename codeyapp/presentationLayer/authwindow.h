#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

class AuthWindow : public QDialog {  // Change QWidget to QDialog
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

    bool loginUser(const QString &username, const QString &password, QString &role);
};



#endif // AUTHWINDOW_H
