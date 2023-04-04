#include "SceneBuilder.h"

#include <QDebug>
#include <QFile>
#include <QList>
#include <QPointF>
#include <QFont>
#include <QDir>

#include "Json.h"
#include "Logger.h"

QGraphicsItem *set(QGraphicsItem *item) {
    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setFlag(QGraphicsItem::ItemIsSelectable, true);
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    return item;
}

SceneBuilder::SceneBuilder(QGraphicsScene *scene, QObject *parent)
    : m_scene{scene},
      QObject{parent} {

}

void SceneBuilder::read(const QString &filename) {
    // Parse json
    QFile file( filename );
    if (!file.open(QIODevice::ReadOnly)) {
        logger() << "Ops, couldn't open '" << filename << "' file!" << Qt::endl;
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument json = QJsonDocument::fromJson(data);
    // Read grahics
    auto body = json.object();
    if (!body.contains("objects")  && !body["objects"].isArray()) {
        logger() << "Ops, json objects not available!" << Qt::endl;
        return;
    }
    // Build ...
    auto objects = body["objects"].toArray();
    for (const auto &object : objects)
        read( object.toObject() );
}

void SceneBuilder::read(const QJsonObject &object) {
    if (!object.contains("object")) {
        logger() << "Ops, json graphics undefined object!" << Qt::endl;
        return;
    }
    auto type = object["object"].toString();
    if (type == "log")
        logger() << value<QString>(object, "message") << Qt::endl;
    else if (type == "line") {
        auto x = values<float>(object,"x");
        auto y = values<float>(object,"y");
        auto c = color(object);
        auto t = value<int>(object,"thickness");
        auto n = x.size();
        if (n < 2)
            logger() << "Ops, json line has to have at least two points" << Qt::endl;
        if (n == 2)
            scene()->addLine(x[0], y[0], x[1], y[1], QPen(c, t));
        else {
            QPainterPath path;
            auto ix = x.begin();
            auto iy = y.begin();
            path.moveTo(*iy, *iy);
            for( ++ix, ++iy; ix != x.end() && iy != y.end(); ++ix, ++iy)
                path.lineTo(*ix, *iy);
            auto lines = scene()->addPath(path);
            lines->setPen(QPen(c,t));
        }
    }
    else if (type == "point") {
        auto x = values<float>(object,"x");
        auto y = values<float>(object,"y");
        auto c = color(object);
        auto s = value<float>(object, "size");
        auto ix = x.begin();
        auto iy = y.begin();
        for ( ; ix != x.end() && iy != y.end(); ++ix, ++iy)
            scene()->addEllipse((*ix) - 0.5*s, (*iy) - 0.5*s, s , s, Qt::NoPen, QBrush(c));
    }
    else if (type == "box") {
        auto x = value<float>(object,"x");
        auto y = value<float>(object,"y");
        auto c = color(object);
        auto a = value<float>(object, "angle");
        auto w = value<float>(object, "width");
        auto h = value<float>(object, "heigth");
        auto box = scene()->addRect(-0.5*w, -0.5*h, w, h, Qt::NoPen, QBrush(c));
        box->setPos(x, y);
        box->setRotation(a);
    }
    else if (type == "text") {
        auto x = value<float>(object,"x");
        auto y = value<float>(object,"y");
        auto c = color(object);
        auto a = value<float>(object, "angle");
        auto s = value<float>(object, "size");
        auto t = value<QString>(object, "content");
        auto text = scene()->addSimpleText(t, QFont("Arial", s));
        text->setPos(x, y);
        text->setRotation(a);
        text->setPen(Qt::NoPen);
        text->setBrush(QColor(c));
    }
}

void SceneBuilder::build() {
    read( filename() );
}
