/*
 *  This file is part of the ArtificialHorizon project
 *  Copyright (C) 04/05/2014 -- mainwindow.cpp -- bertrand
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * */

#include <cmath>

#include <QThread>
#include <QMouseEvent>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "artificialhorizon.h"

#define TIMEOUT (500)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    state(0),
    roll(0),
    pitch(0)
{
    ui->setupUi(this);
    this->h = new ArtificialHorizon(this->ui->centralWidget);
    h->show();

    connect(&(this->timer), SIGNAL(timeout()), this, SLOT(timedOut()));
    timer.setInterval(TIMEOUT);
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timedOut()
{
    switch(state)
    {
    case 0:
        pitch += 5;
        break;
    case 1:
        pitch -= 5;
        break;
    case 2:
        pitch += 10;
        break;
    default:
        timer.stop();
        break;
    }

    if(state==0 && pitch>90)
    {
        state++;
        roll = 180-roll;
        pitch = 180 - pitch;
    }
    else if(state==1 && pitch < -90)
    {
        roll = 180-roll;
        pitch = -180-pitch;
        state++;
    }
    else if(state==2 && pitch > 10)
    {
        state++;
    }

    qDebug() << roll << "," << pitch;
    h->setRollPitch(roll,pitch);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
//    int pitch = event->pos().y();
//    int roll = event->pos().x();

//    if(pitch>90)
//    {
//        roll = 180-roll;
//        pitch = -180+pitch;
//    }
//    else if(pitch<-90)
//    {
//        roll = 180-roll;
//        pitch = 180+pitch;
//    }

//    qDebug() << event->pos().x() << "," << event->pos().y() <<  " : " << roll << "," << pitch;

//    this->h->setRollPitch(roll, pitch);
    QMainWindow::mouseMoveEvent(event);
}
