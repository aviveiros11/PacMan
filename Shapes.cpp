//
// Created by Lisa Dion on 2/15/18.
//

#include "graphics.h"
#include "shapes.h"
#include <cmath>

/******************** point struct ********************/

point::point() : x(0), y(0) { }

point::point(int xIn, int yIn) : x(xIn), y(yIn) { }

/******************** Shape class ********************/

Shape::Shape() : area(0), perimeter(0), center({0, 0}),
                 fill({0, 0, 0}) {
    // color defaults to black
}

Shape::Shape(point c, color b, color f) : area(0), perimeter(0),
                                          center(c),
                                          border(b), fill(f) { }

Shape::Shape(int xIn, int yIn,
             double rb, double gb, double bb,
             double rf, double gf, double bf) : area(0),
                                                perimeter(0),
                                                center({xIn, yIn}),
                                                border({rb, gb, bb}),
                                                fill({rf, gf, bf}) { }

point Shape::getCenter() const {
    return center;
}

color Shape::getBorderColor() const {
    return border;
}

color Shape::getFillColor() const {
    return fill;
}

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}

void Shape::setCenter(point c) {
    center = c;
}

void Shape::setCenter(int xIn, int yIn) {
    center = {xIn, yIn};
}

void Shape::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Shape::setBorderColor(color b) {
    border = b;
}

void Shape::setBorderColor(double r, double g, double b) {
    border = {r, g, b};
}

void Shape::setFillColor(color f) {
    fill = f;
}

void Shape::setFillColor(double r, double g, double b) {
    fill = {r, g, b};
}

/******************** Circle class ********************/

void Circle::calculateArea() {
    area = PI * radius * radius;
}

void Circle::calculatePerimeter() {
    perimeter = 2.0 * PI * radius;
}

Circle::Circle() : Shape(), radius(0) { }

Circle::Circle(double rad) : Shape() {
    setRadius(rad);
}

Circle::Circle(color b, color f) : Shape({0, 0}, b, f), radius(0) { }

Circle::Circle(double rb, double gb, double bb,
               double rf, double gf, double bf) :
        Shape(0, 0, rb, gb, bb, rf, gf, bf), radius(0) {}

Circle::Circle(double rad, color b, color f)  {
    // example without initializer list
    setCenter({0, 0});
    setBorderColor(b);
    setFillColor(f);
    setRadius(rad);
    calculateArea();
    calculatePerimeter();
}

Circle::Circle(double rad,
               double rb, double gb, double bb,
               double rf, double gf, double bf) :
        Shape(0, 0, rb, gb, bb, rf, gf, bf) {
    setRadius(rad);
}

Circle::Circle(double rad, point c) :
        Shape(c, {0, 0, 0}, {0, 0, 0}) {
    setRadius(rad);
}

Circle::Circle(double rad, int xIn, int yIn) :
        Shape(xIn, yIn, 0, 0, 0, 0, 0, 0) {
    setRadius(rad);
}

Circle::Circle(double rad, color b, color f, point c) :
        Shape(c, b, f) {
    setRadius(rad);
}

Circle::Circle(double rad,
               double rb, double gb, double bb,
               double rf, double gf, double bf,
               int xIn, int yIn) :
        Shape(xIn, yIn, rb, gb, bb, rf, gf, bf) {
    setRadius(rad);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double rad) {
    // do not want to accept negative values for radius
    radius = (rad < 0) ? 0 : rad;
    calculateArea();
    calculatePerimeter();
}

void Circle::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(center.x, center.y);
    glColor3f(border.red, border.green, border.blue);
    for (double i = 0; i < 2.0*PI+0.05; i += 2.0*PI/360.0) {
        glVertex2i(center.x + radius * cos(i),
                   center.y + radius * sin(i));
    }
    glEnd();
}

/******************** Tangle class ********************/

void Tangle::calculateArea() {
    area = length * width;
}

void Tangle::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * width;
}

Tangle::Tangle() : Shape(), length(0), width(0) { }

Tangle::Tangle(double l, double w) : Shape() {
    setDimensions(l, w);
}

double Tangle::getLength() const {
    return length;
}

double Tangle::getWidth() const {
    return width;
}

void Tangle::setDimensions(double l, double w) {
    // we don't want to accept negative values for length and width
    length = (l < 0) ? 0 : l;
    width = (w < 0) ? 0 : w;
    // update area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Tangle::draw() const {
    // draw fill
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(length/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(length/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(length/2.0));
    glEnd();

//    glLineWidth((GLfloat)5.0);
//    // draw border
//    glColor3f(border.red, border.green, border.blue);
//    glBegin(GL_LINE_STRIP);
//    // top left
//    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
//    // top right
//    glVertex2i(center.x+(width/2.0), center.y-(length/2.0));
//    // bottom right
//    glVertex2i(center.x+(width/2.0), center.y+(length/2.0));
//    // bottom left
//    glVertex2i(center.x-(width/2.0), center.y+(length/2.0));
//    // top left
//    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    //glEnd();
}