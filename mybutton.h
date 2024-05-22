#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);

signals:
    void myClicked(); // Signal version without parameters
    void myClicked(const QString &text); // Signal version with a QString parameter

private slots:
    void emitMyClicked();
};

#endif // MYBUTTON_H
