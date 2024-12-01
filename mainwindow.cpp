#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    setCentralWidget(view);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(1000 / 33);

    Pacman *pacman = new Pacman(scene);
    scene->addItem(pacman);
    pacman->setPos(20, 15);


    Ghost *ghost1 = new Ghost(scene, pacman);
    Ghost *ghost2 = new Ghost(scene, pacman);
    Ghost *ghost3 = new Ghost(scene,pacman);
    scene->addItem(ghost1);
    scene->addItem(ghost2);
    scene->addItem(ghost3);

    ghost1->setPos(510, 200);
    ghost2->setPos(30,300);
    ghost3->setPos(220,10);

    scene->addRect(0, 0, 570, 10);
    scene->addRect(0, 470, 570, 10);
    scene->addRect(0, 0, 10,200);
    scene->addRect(0, 250,10,220);
    scene->addRect(560, 0, 10,220);
    scene->addRect(560, 260, 10,210);


    scene->addRect(60,140,10, 80);

    scene->addRect(60,140,140,10);
    scene->addRect(200,150,10,-90);
    scene->addRect(320,60,60,10);
    scene->addRect(440,60,60,10);
    scene->addRect(260,60,10,200);
    scene->addRect(320,60,10,200);
    scene->addRect(380,60,10,200);
    scene->addRect(440,60,10,200);
    scene->addRect(500,60,10,200);
    scene->addRect(500,260,60,10);
    scene->addRect(270,260,-200,10);
    scene->addRect(60,260,10,60);
    scene->addRect(60,320,200,10);
    scene->addRect(260,320,10,60);
    scene->addRect(270,380,-200,10);
    scene->addRect(60,380,10,50);


    QList<QGraphicsItem *> items = scene->items();
    for (auto *item : items) {
        if (item->type() == QGraphicsRectItem::Type) {
            QGraphicsRectItem *rect = dynamic_cast<QGraphicsRectItem *>(item);
            rect->setBrush(Qt::blue);
        }
    }

    scene->setSceneRect(0, 0, 640, 480);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete timer;
}



