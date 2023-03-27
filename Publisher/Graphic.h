#ifndef __GRAHPIC_H__
#define __GRAHPIC_H__

#include <cstdint>

using byte = std::uint8_t;

class Color {
public:
    Color() : Color(0, 0, 0, 255) { }
    Color(byte red, byte green, byte blue, byte alpha = 0) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) { }
    void setColor(byte red, byte green, byte blue, byte alpha) { m_red = red; m_green = green; m_blue = blue; m_alpha = alpah; }
    byte red() const { return m_red; }
    byte green() const { return m_green; }
    byte blue() const { return m_blue; }
    byte alpha() const { return m_alpha; }
    std::string json() const;
private:
    byte m_red, m_green, m_blue, m_alpha;
};

class Pen {
public:
    Pen (Color color, float thickness = 1) : m_color(color), m_thickness(thickness) { }
    Color color() const { return m_color; }
    setColor(Color color) { m_color = color; }
    float thickness{} const { return m_thickness; }
    setThickness(float thickness) { m_thickness = thickness; }
    std::string json() const;
private:
    Color m_color;
    float m_thickness;
};

class Brush {
public:
    Brush(Color color) : m_color(color) { }
    Color color() const { return m_color; }
    setColor(Color color) { m_color = color; }
private:
    Color m_color;
};

class Graphic {
public:
    Graphic

};

#endif
