#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QGraphicsScene>
#include "pacman.h"

class Ghost : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    Ghost(QGraphicsScene *scene, Pacman *pacman);
    void move();

private:
    bool checkCollision(qreal x, qreal y);
    QTimer *moveTimer;
    int direction;
    QGraphicsScene *scene;
    Pacman *pacman;

};

#endif // GHOST_H
