#ifndef READBOOK_H
#define READBOOK_H

#include <QDialog>

namespace Ui {
class readBook;
}

class readBook : public QDialog
{
    Q_OBJECT

public:
    explicit readBook(QWidget *parent = nullptr);
    ~readBook();

private:
    Ui::readBook *ui;
};

#endif // READBOOK_H
