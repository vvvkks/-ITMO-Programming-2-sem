//
// Created by Вика on 18.03.2022.
//

#ifndef LAB1_FIGURES_H
#define LAB1_FIGURES_H

#include <iostream>
#include <vector>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point();

    Point(double x, double y);

    Point(const Point &point);

    double getX() const;

    double getY() const;

};


class PolyLine {

protected:
    std::vector<Point> points;

    static double distance(const Point &a, const Point &b);


public:
    explicit PolyLine(Point *listP = nullptr, int size = 0);

    PolyLine(const PolyLine &polyline);

    PolyLine &operator=(const PolyLine &polyLine) = default;

    double Perimeter() const;

    void print();
};

class ClosePolyLine : public PolyLine {

public:
    ClosePolyLine(Point arr[], int size);

    ClosePolyLine() = default;

    ClosePolyLine(const ClosePolyLine &cpolyline);

    ClosePolyLine &operator=(const ClosePolyLine &cpolyLine) = default;

    double ClosedPerimeter() const;

};

class Polygon : public ClosePolyLine {

protected:
    std::vector<double> edges;

public:

    Polygon() = default;

    Polygon(Point arr[], int size);

    Polygon(const Polygon &cpolygon);

    Polygon &operator=(const Polygon &cpolygon) = default;

    void Edges();

    bool convex();

    double area();

    std::vector<double> getEdges();
};

class Triangle : public Polygon {

public:

    Triangle(Point arr[], int size);

    Triangle(const Triangle &ctriangle);

    Triangle &operator=(const Triangle &ctriangle) = default;


    explicit Triangle(Point *listP = nullptr);

    void Info();

};

class Trapezoid : public Polygon {
private:
    bool check();


public:
    explicit Trapezoid(Point *listP = nullptr);

    Trapezoid(Point arr[], int size);

    Trapezoid(const Trapezoid &ctrapezoid);

    Trapezoid &operator=(const Trapezoid &ctrapezoid) = default;


};

class RegularPolygon : public Polygon {
private:
    bool check();

public:

    RegularPolygon(Point arr[], int size);

    RegularPolygon(const RegularPolygon &cRegularPolygon);

    RegularPolygon &operator=(const RegularPolygon &cRegularPolygon) = default;

};

#endif //LAB1_FIGURES_H
