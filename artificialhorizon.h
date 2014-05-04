/*
 *  This file is part of the ArtificialHorizon project
 *  Copyright (C) 04/05/2014 -- artificialhorizon.h -- bertrand
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

#ifndef ARTIFICIALHORIZON_H
#define ARTIFICIALHORIZON_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class ArtificialHorizon : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ArtificialHorizon(QWidget *parent = 0);

signals:

public slots:
    void    setRoll(double roll);

private:
    QGraphicsScene scene;
    QGraphicsPixmapItem back;
    QGraphicsPixmapItem inside;
    QGraphicsPixmapItem foreground;
};

#endif // ARTIFICIALHORIZON_H
