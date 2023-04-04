#ifndef __COLOR_H__
#define __COLOR_H__

#include "Point.h"

class Color {
public:
    Color() : Color(0, 0, 0, 0.5) { }
    Color(scalar red, scalar green, scalar blue, scalar alpha = 0.5) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) { }
    void setColor(scalar red, scalar green, scalar blue, scalar alpha);
    scalar red() const { return m_red; }
    scalar green() const { return m_green; }
    scalar blue() const { return m_blue; }
    scalar alpha() const { return m_alpha; }
private:
    scalar m_red, m_green, m_blue, m_alpha;
};

#endif
