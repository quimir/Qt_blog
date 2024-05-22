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
#include "myapplication.h"
#include "workerthread.h"
#include <QSignalSpy>
#include <QTest>

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>

/**
 * @brief TestUniqueConnection Tests Qt::UniqueConnection uniformity
 * @param worker_thread signaler
 * @param my_application Signal receiver
 */
void TestUniqueConnection(WorkerThread& worker_thread,MyApplication& my_application)
{
    QSignalSpy spy(&worker_thread,&WorkerThread::WorkUniqueConnection);

    // using Qt::UniqueConnection
    QObject::connect(&worker_thread,&WorkerThread::WorkUniqueConnection,&my_application,
                     &MyApplication::UniqueConnectionSlot,Qt::UniqueConnection);

    // using Qt::UniqueConnection
    QObject::connect(&worker_thread, &WorkerThread::WorkUniqueConnection, &my_application,
                     &MyApplication::UniqueConnectionSlot, Qt::UniqueConnection);

    worker_thread.WorkUniqueConnection();

    // Check to see if the signal was transmitted only once
    if (spy.count() == 1)
    {
        qDebug() << "Test passed: Signal emitted once.";
    }
    else
    {
        qDebug() << "Test failed: Expected signal to be emitted once, but it was emitted"
                 << spy.count() << "times.";
    };
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Qt_blog_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    WorkerThread worker_thread;
    MyApplication my_application;

    QPushButton button("click me");

    button.show();

    TestUniqueConnection(worker_thread,my_application);

    // using Qt::QueuedConnection
    QObject::connect(&worker_thread, &WorkerThread::WorkStarted, &my_application,
                     &MyApplication::QueuedConnectionSlot, Qt::QueuedConnection);

    // using Qt::DirectConnection
    QObject::connect(&worker_thread, &WorkerThread::WorkStarted, &my_application,
                     &MyApplication::DirectConnectionSlot, Qt::DirectConnection);


    // using Qt::SingleShotConnection
    QObject::connect(&worker_thread, &WorkerThread::WorkStarted, &my_application,
                     &MyApplication::SingleShotConnectionSlot, Qt::SingleShotConnection);

    // Start the worker thread when you click the button
    QObject::connect(&button, &QPushButton::clicked, &worker_thread, [&worker_thread]{
        worker_thread.start();
    });

    // MainWindow w;
    // w.show();
    return a.exec();
}
