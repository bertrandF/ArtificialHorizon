/*
 *  This file is part of the ArtificialHorizon project
 *  Copyright (C) 04/05/2014 -- artificialhorizon.cpp -- bertrand
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

#include "artificialhorizon.h"

ArtificialHorizon::ArtificialHorizon(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setScene(&(this->scene));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Background
    this->back.setPixmap(QPixmap(":/images/background.png")\
                .scaled(QSize(200,200)));
    this->scene.addItem(&(this->back));

    // Inside
    this->inside.setPixmap(QPixmap(":/images/inside.png")\
                           .scaled(QSize(500/3,500/3)));
    this->inside.setPos(100-500/6,100-500/6);
    this->inside.setTransformOriginPoint(500/6,500/6);
    this->inside.setRotation(0);
    this->scene.addItem(&(this->inside));

    // Foreground
    this->foreground.setPixmap(QPixmap(":/images/foreground.png")\
                               .scaled(QSize(500/3,500/3)));
    this->foreground.setPos(100-500/6,100-500/6);
    this->scene.addItem(&(this->foreground));
}

void ArtificialHorizon::setRoll(double roll)
{
    this->inside.setRotation(roll);
}
