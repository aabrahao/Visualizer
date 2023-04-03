#include "Json.h"

template<> bool contains<bool>(const QJsonObject &o, const QString &property) { return o.contains(property) && o[property].isBool(); }
template<> bool contains<int>(const QJsonObject &o, const QString &property) { return o.contains(property) && o[property].isDouble(); }
template<> bool contains<float>(const QJsonObject &o, const QString &property) { return o.contains(property) && o[property].isDouble();  }
template<> bool contains<double>(const QJsonObject &o, const QString &property) { return o.contains(property) && o[property].isDouble();  }
template<> bool contains<QString>(const QJsonObject &o, const QString &property)  { return o.contains(property) && o[property].isString();  }

template<> bool to<bool>(const QJsonValue &v) { return v.toBool(); }
template<> int to<int>(const QJsonValue &v) { return v.toInteger(); }
template<> float to<float>(const QJsonValue &v) { return (float)v.toDouble(); }
template<> double to<double>(const QJsonValue &v) { return v.toDouble(); }
template<> QString to<QString>(const QJsonValue &v) { return v.toString(); }

QString ident(int n) {
    QString s;
    while(n--)
        s += "   ";
    return s;
}

QColor color(const QJsonObject &object) {
    QColor c;
    auto v = values<float>(object, "color");
    auto n = v.size();
    if (n < 3)
        logger() << "Ops, json color less them tree elements" << Qt::endl;
    else if (n == 3)
        c = QColor(v[0]*255, v[1]*255, v[2]*255, 0.5*255);
    else
        c = QColor(v[0]*255, v[1]*255, v[2]*255, v[3]*255);
    logger() << "Color: " << c << Qt::endl;
    return c;
}
