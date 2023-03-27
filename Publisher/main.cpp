#include <iostream>
#include <string>

#include "Point.h"
#include "Vector"

int main ( int argc, char *argv[] ) {
    Point p1;
    Point p2(2,3);

    std::cout << "p1 " << p1 << std::endl;
    std::cout << "p2 " << p2 << std::endl;

    std::cout << "p2*2 " << p2*2 << std::endl;
    std::cout << "3*p2 " << 3*p2 << std::endl;

    std::cout << "|p2| " << unit(p2) << std::endl;
    std::cout << "|p2| " << abs(unit(p2)) << std::endl;

    std::cout << "a + b " << Point(3,4) + Point(20,11) << std::endl;
    std::cout << "a - b " << Point(3,4) - Point(20,11) << std::endl;

    std::cout << "+a " << +Point(3,4) << std::endl;
    std::cout << "-a " << -Point(3,4) << std::endl;

    auto p3 = p2;
    std::cout << "p3 " << p3 << std::endl;

    Vector<Point> v1;
    Vector<Point> v2({ {1,2}, {2,3}, {3,4}, {4,5} ,{5,6} });
    Vector<Point> v3 = v2;

    std::cout << "v1 " << v1 << std::endl;
    std::cout << "v2 " << v2 << std::endl;
    std::cout << "v3 " << v3 << std::endl;

    v2 *= 2;
    std::cout << "v2 " << v2 << std::endl;
    v2 /= 2;
    std::cout << "v2 " << v2 << std::endl;

    v3 += v3;
    std::cout << "v3 " << v3 << std::endl;

    std::cout <<"null " << null(v1) << std::endl;
    std::cout <<"null " << null(v2) << std::endl;

    std::cout <<"abs " << abs(v2) << std::endl;
    std::cout <<"u " << unit(v2) << std::endl;
    std::cout <<"abs(u) " << abs(unit(v2)) << std::endl;

    auto v4 = 3*v2 + v3/4 - v2;

    std::cout <<"v4 " << v4  << std::endl;

    return 0;
}
