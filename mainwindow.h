#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsView>
#include <QTimer>
#include "pacman.h"
#include "ghost.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    Pacman *pacman;
    QList<Ghost*> ghosts;
};

#endif // MAINWINDOW_H
