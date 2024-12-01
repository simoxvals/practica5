#include "pacman.h"
#include <QBrush>
#include <QPen>
#include <QGraphicsItem>
#include <QGraphicsScene>

Pacman::Pacman(QGraphicsScene *scene) : QGraphicsEllipseItem(0, 0, 30, 30)
{
    this->scene = scene;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QBrush brush(Qt::yellow);
    setBrush(brush);
    QPen pen(Qt::black);
    setPen(pen);
}

bool Pacman::checkCollision(qreal x, qreal y)
{
    QList<QGraphicsItem *> collidingItems = scene->items(QRectF(x, y, 30, 30));
    for (QGraphicsItem *item : collidingItems) {
        if (item->type() == QGraphicsRectItem::Type) {
            return true;
        }
    }
    return false;
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    qreal newX = x();
    qreal newY = y();

    switch (event->key())
    {
    case Qt::Key_A:
        newX -= 10;
        break;
    case Qt::Key_D:
        newX += 10;
        break;
    case Qt::Key_S:
        newY += 10;
        break;
    case Qt::Key_W:
        newY -= 10;
        break;
    }

    if (!checkCollision(newX, newY)) {
        setPos(newX, newY);
    }
}
