#ifndef LOGGER_H
#define LOGGER_H

#include <QTextStream>
#include <QString>

class Logger;

Logger &logger();

class Logger : public QTextStream {
public:
    Logger();
    const QString &messages() { return s_buffer; }
private:
    static QString s_buffer;
};

#endif // CONSOLE_H
