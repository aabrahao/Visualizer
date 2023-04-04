#include <iostream>
#include <string>

// Clang
// sudo apt install libstdc++-12-dev

#include "Visualizer.h"

int main ( int argc, char *argv[] ) {
    
    Visualizer visualizer;
    visualizer.addLog("Staring...");
    visualizer.addMarker(Point(0,0));
    visualizer.addLine(Point(0,0), Point(1,1));
    visualizer.addLabel("Anthonyh Abrahao", Point(-10, -10));
    visualizer.addBox(100, 50, Point(10, 10));
    visualizer.addLog("end!");
    visualizer.draw();

    return 0;
}
