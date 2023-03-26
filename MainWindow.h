#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "GraphicsView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void zoomAll();
    void saveSettings();
    void restoreSettings();
    void initialized();
    void buildScene();
    QGraphicsScene *scene() { return m_scene; }
    GraphicsView *view() { return m_view; }
protected:
    void closeEvent(QCloseEvent *event) override;
 private:
    QGraphicsScene *m_scene;
    GraphicsView *m_view;
 };

#endif // MAINWINDOW_H
