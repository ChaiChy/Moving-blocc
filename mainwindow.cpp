#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randomwaypoint.h"
#include "QGraphicsRectItem"
#include "QTimer"
#include <iostream>
#include "randomwaypoint.h"
#include "QMediaPlayer"
#include "QAudioOutput"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMediaPlayer *music = new QMediaPlayer;
    QAudioOutput *output = new QAudioOutput;
    music->setSource(QUrl("qrc:/take_on_me.mp3"));
    music->setAudioOutput(output);
    music->setLoops(2);
    music->play();



    QGraphicsScene* qgs_Spielfeld = new QGraphicsScene(0,0,440, 440, ui->graphicsView_main_box);
    QGraphicsRectItem* block = new QGraphicsRectItem (0, 0,40, 40);
    block->setBrush(Qt::yellow);
    block->setPen(QPen(Qt::black));
    qgs_Spielfeld->addItem(block);
    ui->graphicsView_main_box->setScene(qgs_Spielfeld);

    RandomWaypoint *rp = new RandomWaypoint(10.1, 10.1);

    auto proceed = [=] () {
        rp->proceed();
        block->setPos(rp->getX(), rp->getY());
        ui->lcdNumber->display(rp->getX());
        ui->lcdNumber_2->display(rp->getY());
        qgs_Spielfeld->update();
    };

    QTimer* qtimer_ptr = new QTimer(this);
    connect(qtimer_ptr, &QTimer::timeout, proceed);
    qtimer_ptr->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


