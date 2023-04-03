#include "Logger.h"

QString Logger::s_buffer;

Logger &logger() {
    static Logger logger;
    return logger;
}

Logger::Logger()
    : QTextStream(&s_buffer) {

}
