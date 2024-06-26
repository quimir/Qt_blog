/**
 ** This file is part of the Qt_blog project.
 ** Copyright 2024 QuiMir <2546670299@qq.com>.
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 ** http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mybutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void PrintSlot();

public slots:
    //int TextSlots();
private slots:
    void onMyButtonClicked(); // Slot for the signal without parameters
    void onMyButtonClicked(const QString &text); // Slot for the signal with a QString parameter

signals:
    void signalsAdd(int i);

private:
    Ui::MainWindow *ui;
    MyButton* my_button_;
};
#endif // MAINWINDOW_H
