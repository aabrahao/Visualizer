#include "MainWindow.h"
#include <QSettings>
#include <QTimer>
#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QDebug>

#include <Eigen/Dense>

using Vector = Eigen::Array<qreal, Eigen::Dynamic, 1>;

QGraphicsItem *set(QGraphicsItem *item) {
    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setFlag(QGraphicsItem::ItemIsSelectable, true);
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    return item;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    m_scene = new QGraphicsScene();
    m_view = new GraphicsView(m_scene);
    restoreSettings();
    setCentralWidget(m_view);
    QTimer::singleShot(0, this, &MainWindow::initialized);
}

MainWindow::~MainWindow() {

}

void MainWindow::buildScene() {
    auto item = set( m_scene->addSimpleText("Hello World!\nOk") );
    item->setPos(-100, -100);
    item->setRotation(45);

    QPen pen(QColor(0,255,0));
    pen.setCosmetic(true);

    pen.setColor(QColor(95,95,95));
    m_scene->addLine(-50, 0, 50, 0, pen);
    m_scene->addLine(0, -50, 0, 50, pen);

    pen.setColor(QColor(0,0,255));

    auto x = Vector::LinSpaced(100, 0, 100) - 50;
    auto y = 90*sin(2*M_PI/100*x);

    QPainterPath path;
    path.moveTo(x[0],y[0]);
    for(int i = 1; i < x.size(); ++i)
        path.lineTo(x[i] ,y[i]);
    m_scene->addPath(path);
    m_view->zoomAll();
}

void MainWindow::initialized() {
    buildScene();
}

void MainWindow::saveSettings() {
    QSettings settings("FIU-ARC", "RobotView");
    settings.beginGroup("MainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.endGroup();
}

void MainWindow::restoreSettings() {
    QSettings settings("FIU-ARC", "RobotView");
    settings.beginGroup("MainWindow");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    saveSettings();
    QMainWindow::closeEvent(event);
}
