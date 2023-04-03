#ifndef JSON_H
#define JSON_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QColor>
#include <QPointF>

#include "Logger.h"

constexpr bool even(int x) { return (x & 1) == 0; }
constexpr bool odd(int x) { return (x & 1) != 0; }

// Template helpers
template<typename T> bool contains(const QJsonObject &o, const QString &property) { return o.contains(property); }
template<> bool contains<bool>(const QJsonObject &o, const QString &property);
template<> bool contains<int>(const QJsonObject &o, const QString &property);
template<> bool contains<float>(const QJsonObject &o, const QString &property);
template<> bool contains<double>(const QJsonObject &o, const QString &property);
template<> bool contains<QString>(const QJsonObject &o, const QString &property);

template<typename T> T to(const QJsonValue &v) { return T(); }
template<> bool to<bool>(const QJsonValue &v);
template<> int to<int>(const QJsonValue &v);
template<> float to<float>(const QJsonValue &v);
template<> double to<double>(const QJsonValue &v);
template<> QString to<QString>(const QJsonValue &v);

template<typename O>
O &operator<<(O &o, const QColor &color) {
    o << "[" << color.red() << "," << color.green() << "," << color.blue() << "," << color.alpha() << "]";
    return o;
}

template<typename O>
O &operator<<(O &o, const QPointF &point) {
    o << "[" << point.x() << "," << point.y() << "]";
    return o;
}

template<typename O, typename T>
O &operator<<(O &o, const QList<T> &v) {
    o << "[";
    for (auto i = v.begin(); i != v.end(); ++i) {
        o << *i;
        if (i != --(v.end()))
            o << ",";
    }
    o << "]";
    return o;
}

template<typename T>
T value(const QJsonObject &object, const QString &property) {
    if ( !contains<T>(object, property) ) {
        logger() << "Ops, json does not contain '" << property << "'!" << Qt::endl;
        return T();
    }
    return to<T>(object[property]);
}

template<typename T>
QList<T> values(const QJsonObject &object, const QString & property) {
    if (!object.contains(property)) {
        logger() << "Ops, jason does not contain '" << property << "'!" << Qt::endl;
        return QList<T>();
    }
    QList<T> list;
    if (object[property].isArray()) {
        auto array = object[property].toArray();
        auto n = array.size();
        list.resize(n);
        for (int i = 0; i < n; ++i)
            list[i] = to<T>(array[i]);
    }
    else {
        auto value = to<T>(object[property]);
        list.resize(1);
        list[0] = value;
    }
    return list;
}

QColor color(const QJsonObject &object);
QString ident(int n);

#endif // JSON_H
