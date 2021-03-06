/****************************************************************************
** Copyright (C) 2016 Olaf Japp
**
** This file is part of AnimationMaker.
**
**  AnimationMaker is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  AnimationMaker is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef COLORRECT_H
#define COLORRECT_H

#include <QWidget>

class ColorRect : public QWidget
{
    Q_OBJECT
public:
    ColorRect();

    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);

    inline void setColor(QColor color) {m_color = color; update();}

signals:
    void mouseClicked();

private:
    QColor m_color;
};

#endif // COLORRECT_H
