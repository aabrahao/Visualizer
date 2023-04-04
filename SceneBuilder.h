#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QJsonObject>

class SceneBuilder : public QObject {
    Q_OBJECT
public:
    explicit SceneBuilder(QGraphicsScene *scene, QObject *parent = nullptr);
    QGraphicsScene *scene() { return m_scene; }
    void build();
    void read(const QString &filename);
    void read(const QJsonObject &object);
    QString filename() const { return "/home/bilac/Projects/Visualizer/scene.json"; }
private:
    QGraphicsScene *m_scene;
};

#endif // SCENEBUILDER_H
