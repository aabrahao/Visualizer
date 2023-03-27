#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>

#include "Types"

class Point {
public:
    Point() : m_x(0), m_y(0) { }
    Point(scalar x, scalar y) : m_x(x), m_y(y) { }
    // Member
    scalar x() const { return m_x; }
    scalar y() const { return m_y; }
    void setX(scalar x) { m_x = x; }
    void setY(scalar y) { m_y = y; }
    // Operator
    scalar &operator[](std::size_t i) { return i==0?m_x:m_y; }
    const scalar &operator[](std::size_t i) const { return i==0?m_x:m_y; }
    // Arithmetics
    Point &operator*=(scalar s) { m_x *= s; m_y *= s; return *this; }
    Point &operator/=(scalar s) { m_x /= s; m_y /= s; return *this; }

    Point &operator+=(const Point &p) { m_x += p.m_x; m_y += p.m_y; return *this; }
    Point &operator-=(const Point &p) { m_x -= p.m_x; m_y -= p.m_y; return *this; }

    friend bool null(const Point &p)  { return equal(p.m_x, 0.0) and equal(p.m_y, 0.0); }
    friend scalar abs(const Point &p) { return std::sqrt(p.m_x*p.m_x + p.m_y*p.m_y); }
    friend scalar dot(const Point &p1, const Point &p2) { return p1.m_x*p2.m_x + p1.m_y*p2.m_y; }
    friend Point unit(const Point &p) { return p/abs(p); }

    friend Point operator+(const Point &p) { return p; }
    friend Point operator-(const Point &p) { return Point(-p.m_x, -p.m_y); }

    friend bool operator!=(const Point &p1, const Point &p2) { return !equal(p1.m_x, p2.m_x) or !equal(p1.m_y, p2.m_y); }
    friend bool operator==(const Point &p1, const Point &p2) { return equal(p1.m_x, p2.m_x) and equal(p1.m_y, p2.m_y); }

    friend Point operator*(const Point &p, scalar s) { return Point(p.m_x*s, p.m_y*s); }
    friend Point operator*(scalar s, const Point &p) { return Point(p.m_x*s, p.m_y*s); }
    friend Point operator/(const Point &p, scalar s) { return Point(p.m_x/s, p.m_y/s); }

    friend Point operator+(const Point &p1, const Point &p2) { return Point(p1.m_x+p2.m_x, p1.m_y+p2.m_y); }
    friend Point operator-(const Point &p1, const Point &p2) { return Point(p1.m_x-p2.m_x, p1.m_y-p2.m_y); }
    // IO
    template<typename O> friend O &operator<<(O &o, const Point &p) { o << p.m_x << " " << p.m_y; return o; }
    template<typename I> friend I &operator>>(I &i, Point &p) { i >> p.m_x >> p.m_y; return i; }

private:
    scalar m_x;
    scalar m_y;
};

#endif
