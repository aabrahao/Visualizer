#include "Object.h"
#include <iostream>

void Log::draw() { 
    std::cout << "log" << std::endl; 
}

void Marker::draw() { 
    std::cout << "point" << std::endl; 
}

void Line::draw() {
    std::cout << "line" << std::endl; 
}

void Label::draw() { 
    std::cout << "text" << std::endl; 
}

void Box::draw() { 
    std::cout << "Box" << std::endl; 
}
