#include "Visualizer.h"

void Visualizer::draw() {
    for (const auto &object : m_objects)
        object->draw();
}

std::shared_ptr<Log> Visualizer::addLog(const std::string &message) {
    auto object = std::make_shared<Log>(message);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Marker> Visualizer::addMarker(const Points &points, const Color &color, scalar size) {
    auto object = std::make_shared<Marker>(points, color, size);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Marker> Visualizer::addMarker(const Point &point, const Color &color, scalar size)  {
    Points points = {point};
    auto object = std::make_shared<Marker>(points, color, size);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Line> Visualizer::addLine(const Points &points, const Color &color, scalar size) {
    auto object = std::make_shared<Line>(points, color, size);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Line> Visualizer::addLine(const Point &point1, const Point &point2, const Color &color, scalar size) {
    Points points = {point1, point2};
    auto object = std::make_shared<Line>( points, color, size);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Label> Visualizer::addLabel(const std::string &text, const Point &position, scalar angle, const Color &color, scalar size) {
    auto object = std::make_shared<Label>(text, position, angle, color, size);
    m_objects.push_back(object);
    return object;
}

std::shared_ptr<Box> Visualizer::addBox(scalar width, scalar height, const Point &position, scalar angle, const Color &color) {
    auto object = std::make_shared<Box>(width, height, position, angle, color);
    m_objects.push_back(object);
    return object;
}
