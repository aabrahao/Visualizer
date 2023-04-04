#include "Point.h"

std::ostream &operator<<(std::ostream &o, const Point &p) {
     o << p.m_x << " " << p.m_y; 
     return o; 
}
