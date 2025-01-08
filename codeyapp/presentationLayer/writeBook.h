#ifndef WRITEBOOK_H
#define WRITEBOOK_H

#include <QDialog>

namespace Ui {
class writeBook;
}

class writeBook : public QDialog
{
    Q_OBJECT

public:
    explicit writeBook(const QString &author, const QString &role, QWidget *parent = nullptr);
    ~writeBook();

signals:
    void bookAdded(const QString &title, const QString &author, const QString &genre, const QString &status);

private slots:
    void on_cancelButton_clicked();
    void on_writeButton_clicked();

private:
    Ui::writeBook *ui;
    QString currentAuthor;
    QString currentRole;
};

#endif
