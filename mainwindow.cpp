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

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMetaObject>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->my_button_=new MyButton(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(my_button_);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect both versions of the myClicked() signal to their respective slots
    connect(my_button_, SIGNAL(myClicked()), this, SLOT(onMyButtonClicked()));
    connect(my_button_, SIGNAL(myClicked(const QString&)), this,
            SLOT(onMyButtonClicked(const QString&)));
    connect(ui->slot_button,&QPushButton::clicked,this,&MainWindow::PrintSlot,Qt::DirectConnection);
}

void MainWindow::onMyButtonClicked()
{
    qDebug() << "MyButton was clicked!";
}

void MainWindow::onMyButtonClicked(const QString &text)
{
    qDebug() << "MyButton was clicked with text:" << text;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintSlot()
{
    qDebug()<<"print no slot \n";
}
