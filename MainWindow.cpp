#include "MainWindow.h"
#include <QSettings>
#include <QTimer>
#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent} {
    m_scene = new QGraphicsScene();
    m_view = new GraphicsView(m_scene);
    m_builder = new SceneBuilder(m_scene);
    restoreSettings();
    setCentralWidget(m_view);
    QTimer::singleShot(0, this, &MainWindow::initialized);
}

MainWindow::~MainWindow() {

}

void MainWindow::buildScene() {
    m_builder->build();
}

void MainWindow::initialized() {
    buildScene();
    view()->zoomAll();
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
