#include "mybutton.h"


MyButton::MyButton(QWidget *parent):QPushButton(parent)
{
    // Connect the built-in clicked() signal to the custom emitMyClicked() slot
    connect(this, SIGNAL(clicked()), this, SLOT(emitMyClicked()));
}

void MyButton::emitMyClicked()
{
    // Emit both versions of the myClicked() signal
    emit myClicked();
    emit myClicked(text());
}
