#include "ghost.h"
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <cmath>
#include <cstdlib>

Ghost::Ghost(QGraphicsScene *scene, Pacman *pacman)
    : scene(scene), pacman(pacman)
{
    setRect(0, 0, 30, 30);
    QBrush brush(Qt::red);
    setBrush(brush);

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Ghost::move);
    moveTimer->start(100);
    direction = rand() % 4;
}

bool Ghost::checkCollision(qreal x, qreal y)
{
    QList<QGraphicsItem *> collidingItems = scene->items(QRectF(x, y, 30, 30));
    for (QGraphicsItem *item : collidingItems) {
        if (item->type() == QGraphicsRectItem::Type) {
            return true;
        }
    }
    return false;
}

void Ghost::move()
{

    qreal ghostX = x();
    qreal ghostY = y();

    qreal newGhostX = ghostX;
    qreal newGhostY = ghostY;
    qreal stepSize = 8;


    switch (direction)
    {
    case 0:
        newGhostX = ghostX - stepSize;
        break;
    case 1:
        newGhostX = ghostX + stepSize;
        break;
    case 2:
        newGhostY = ghostY - stepSize;
        break;
    case 3:
        newGhostY = ghostY + stepSize;
        break;
    }

    if (checkCollision(newGhostX, newGhostY))
    {
        direction = rand() % 4;
    }
    else {
        setPos(newGhostX, newGhostY);
    }
}
