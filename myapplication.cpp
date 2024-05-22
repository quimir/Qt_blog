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

#include "myapplication.h"

MyApplication::MyApplication(QObject *parent)
    : QObject{parent}
{}

void MyApplication::AutoConnectionSlot()
{
    qDebug() << "AutoConnection slot called";
}

void MyApplication::DirectConnectionSlot()
{
    qDebug() << "DirectConnection slot called";
}

void MyApplication::QueuedConnectionSlot()
{
    qDebug() << "QueuedConnection slot called";
}

void MyApplication::BlockingConnectionSlot()
{
    qDebug() << "BlockingConnection slot called";
}

void MyApplication::UniqueConnectionSlot()
{
    qDebug() << "UniqueConnection slot called";
}

void MyApplication::SingleShotConnectionSlot()
{
    qDebug() << "SingleShotConnection slot called";
}
