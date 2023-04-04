#ifndef __Object_H__
#define __Object_H__

#include "Properties"

class Visualizer;

class Object {
public:
    virtual void draw() = 0;
};

class Log : public Object, 
            public TextProperty {
public:
    void draw() override;
    Log(const std::string &message) 
        : TextProperty(message) { }
};

class Marker : public Object, 
               public PointsProperty, 
               public ColorProperty, 
               public SizeProperty  {
public:
    void draw() override;
    Marker(const Points &points, const Color &color, scalar size) 
        : PointsProperty(points), 
          ColorProperty(color), 
          SizeProperty(size) { }
    friend class Visualizer;
};

class Line : public Object, 
             public PointsProperty, 
             public ColorProperty, 
             public SizeProperty  {
public:
    void draw() override;
    Line(const Points &points, const Color &color, scalar size) 
        : PointsProperty(points), 
          ColorProperty(color), 
          SizeProperty(size) { }
};

class Label : public Object,
              public TextProperty,
              public PositionProperty,
              public ColorProperty, 
              public SizeProperty  {
public:
    void draw() override;
    Label(const std::string &text, const Point &position, scalar angle, const Color &color, scalar size) 
        : TextProperty(text),
          PositionProperty(position, angle),
          ColorProperty(color), 
          SizeProperty(size) { }
};

class Box : public Object,
            public BoxProperty, 
            public PositionProperty, 
            public ColorProperty {
public:
    void draw() override;
    Box(scalar width, scalar height, const Point &position, scalar angle, const Color &color) 
        : BoxProperty(width, height),
          PositionProperty(position, angle),
          ColorProperty(color) { }
};

#endif