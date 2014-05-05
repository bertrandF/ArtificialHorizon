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

#define WIDGETSIZE  (200)

ArtificialHorizon::ArtificialHorizon(QWidget *parent) :
    QGraphicsView(parent),
    roll(0),
    pitch(0)
{
    double scale;

    // Set Geometry, init configuration
    this->setGeometry(0, 0, WIDGETSIZE, WIDGETSIZE);
    this->setScene(new QGraphicsScene(this));
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Open images, get scale factor
    QPixmap foreground = QPixmap(":/images/foreground.png");
    scale = foreground.size().width() / WIDGETSIZE;
    QPixmap background = QPixmap(":/images/background.png");
    this->backSize = background.size();

    // Setup Graphics view items
    this->back.setPixmap(background);
    this->back.setTransformOriginPoint(background.width()/2, background.height()/2);
    this->foreground.setPixmap(foreground.scaled(QSize(WIDGETSIZE,WIDGETSIZE)));
}

void ArtificialHorizon::setRoll(double roll)
{
    this->roll = roll;
    this->scene()->invalidate();
}

void ArtificialHorizon::setPitch(double pitch)
{
    if(pitch < this->backSize.height()/2-WIDGETSIZE)
    {
        this->pitch = pitch;
        this->scene()->invalidate();
    }
}

void ArtificialHorizon::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->rotate(this->roll);
    painter->translate(QPointF(0, this->pitch));
    painter->drawPixmap(
                QPoint(-this->backSize.width()/2, -this->backSize.height()/2),
                this->back.pixmap());
}

void ArtificialHorizon::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(-100,-100, this->foreground.pixmap());
    QGraphicsView::drawForeground(painter, rect);
}
