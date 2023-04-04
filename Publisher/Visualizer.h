#ifndef __VISUALIZER_H__
#define __VISUALIZER_H__

#include <list>
#include <memory>

#include "Object.h"

class Visualizer {
public:
    Visualizer() { }
    void draw();
    std::shared_ptr<Log> addLog(const std::string &message); 
    std::shared_ptr<Marker> addMarker(const Points &points, const Color &color = Color(), scalar size = 5);
    std::shared_ptr<Marker> addMarker(const Point &point, const Color &color = Color(), scalar size = 5);
    std::shared_ptr<Line> addLine(const Points &points, const Color &color = Color(), scalar size = 1); 
    std::shared_ptr<Line> addLine(const Point &point1, const Point &point2, const Color &color = Color(), scalar size = 1);
    std::shared_ptr<Label> addLabel(const std::string &text, const Point &position, scalar angle = 0, const Color &color = Color(), scalar size = 5);
    std::shared_ptr<Box> addBox(scalar width, scalar height, const Point &position, scalar angle = 0, const Color &color = Color());
private:
    std::list<std::shared_ptr<Object>> m_objects;
};

#endif