#ifndef PACMAN_H
#define PACMAN_H
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class Pacman : public QGraphicsEllipseItem
{
public:
    Pacman(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);
    bool checkCollision(qreal x, qreal y);
    void loseLife();
    int getLives() const { return lives; }

private:
    int lives;
    QGraphicsScene *scene;
};

#endif // PACMAN_H



