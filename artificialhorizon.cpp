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

// This is the size, (no scale sry !)
#define WIDGETSIZE  (200)

#define CIRCLEPENWIDTH  (4)

ArtificialHorizon::ArtificialHorizon(QWidget *parent) :
    QGraphicsView(parent),
    roll(10),
    pitch(0)
{
    this->setGeometry(0, 0, WIDGETSIZE, WIDGETSIZE);

    background      = QBrush(QColor(0x53, 0x54, 0x48));
    circlePen       = QPen(Qt::black);
    circlePen.setWidth(CIRCLEPENWIDTH);
    skyBrush        = QBrush(QColor(0x1d, 0x8e, 0xc6));
    groundBrush     = QBrush(QColor(0xb7, 0x71, 0x1c));
    linePen         = QPen(Qt::white);
    linePen.setWidth(CIRCLEPENWIDTH);
}

void ArtificialHorizon::setRoll(double roll)
{
    if(roll >= -360 && roll >= 360)
    {
        this->roll = roll;
        this->viewport()->update();
    }
}

void ArtificialHorizon::setPitch(double pitch)
{
    if(pitch >= -90 && pitch <= 90)
    {
        this->pitch = pitch;
        this->viewport()->update();
    }
}

void ArtificialHorizon::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this->viewport());
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, event);
    painter.end();
}

void ArtificialHorizon::paint(QPainter *painter, QPaintEvent *event)
{
    // Background
    painter->fillRect(event->rect(), background);
    painter->setPen(circlePen);
    painter->translate(WIDGETSIZE/2, WIDGETSIZE/2);

    // Sky
    painter->setBrush(skyBrush);
    QRectF rect (-(WIDGETSIZE/2-CIRCLEPENWIDTH), -(WIDGETSIZE/2-CIRCLEPENWIDTH),
                (WIDGETSIZE/2-CIRCLEPENWIDTH)*2, (WIDGETSIZE/2-CIRCLEPENWIDTH)*2);
    painter->drawChord(rect,180*16,-180*16);
    // Ground
    painter->setBrush(groundBrush);
    painter->drawChord(rect,180*16,180*16);
    // Horizon line
    painter->setPen(linePen);
    painter->drawLine(-(WIDGETSIZE/2-CIRCLEPENWIDTH*2), 0,
                      (WIDGETSIZE/2-CIRCLEPENWIDTH*2), 0);

    painter->save();
    // Roll
    painter->rotate(roll);
    // Sky
    painter->setPen(circlePen);
    QRectF rectIn (-(WIDGETSIZE/2-CIRCLEPENWIDTH)+20, -(WIDGETSIZE/2-CIRCLEPENWIDTH)+20,
                   (WIDGETSIZE/2-CIRCLEPENWIDTH-20)*2, (WIDGETSIZE/2-CIRCLEPENWIDTH-20)*2);
    painter->setBrush(skyBrush);
    painter->drawChord(rectIn,180*16,-180*16);
    // Ground
    painter->setBrush(groundBrush);
    painter->drawChord(rectIn,180*16,180*16);
    // Horizon line
    painter->setPen(linePen);
    painter->drawLine(-(WIDGETSIZE/2-(CIRCLEPENWIDTH+10)*2), 0,
                      (WIDGETSIZE/2-(CIRCLEPENWIDTH+10)*2), 0);
    painter->restore();
}
