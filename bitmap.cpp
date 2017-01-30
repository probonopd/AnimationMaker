#include "bitmap.h"

#include <QtTest/QTest>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>

Bitmap::Bitmap(QString filename)
    : ResizeableItem()
{
    m_image.load(filename);
    setRect(0, 0, m_image.width(), m_image.height());
}

int Bitmap::type() const
{
    return Bitmap::Type;
}

void Bitmap::paint( QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    paint->drawImage(0, 0, m_image.scaled(rect().width(), rect().height()));

    if (option->state & QStyle::State_Selected)
        drawHighlightSelected(paint, option);
}
