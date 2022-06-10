
#include "figures.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point &point) {
    this->x = point.x;
    this->y = point.y;
}

double Point::getX() const { return this->x; }

double Point::getY() const { return this->y; }

double PolyLine::distance(const Point &a, const Point &b) {
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}

PolyLine::PolyLine(Point *listP, int size) {
    for (int i = 0; i < size; ++i) { points.push_back(listP[i]); }
}

PolyLine::PolyLine(const PolyLine &polyline) {
    int size = (int) polyline.points.size();
    for (int i = 0; i < size; ++i) { points[i] = polyline.points[i]; }
}

double PolyLine::Perimeter() const {
    double len = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        len += distance(points[i], points[i + 1]);
    }
    return len;
}

void PolyLine::print() {
    std::cout << "PolyLine" << points.size() << std::endl;
    for (int i = 0; i < points.size(); i++) {
        std::cout << "x" << i << points[i].getX() << "y" << i << points[i].getY() << std::endl;
    }
}

ClosePolyLine::ClosePolyLine(Point *arr, int size) : PolyLine(arr, size) {}

ClosePolyLine::ClosePolyLine(const ClosePolyLine &cpolyline) : PolyLine(cpolyline) {
    int size = (int) cpolyline.points.size();
    for (int i = 0; i < size; ++i) { points[i] = cpolyline.points[i]; }
}

double ClosePolyLine::ClosedPerimeter() const {

    double len = PolyLine::Perimeter();
    len += distance(points[0], points[points.size() - 1]);
    return len;
}

Polygon::Polygon(Point *arr, int size) : ClosePolyLine(arr, size) {}

Polygon::Polygon(const Polygon &cpolygon) : ClosePolyLine(cpolygon) {
    int size = (int) cpolygon.points.size();
    for (int i = 0; i < size; ++i) { points[i] = cpolygon.points[i]; }
}

void Polygon::Edges() {
    double t;
    for (int i = 0; i < points.size() - 1; i++) {
        t = distance(points[i], points[i + 1]);
        edges.push_back(t);
    }
    t = distance(points[points.size() - 1], points[0]);
    edges.push_back(t);
}

bool Polygon::convex() {

    int sum = 0;
    for (auto &n: edges)
        sum += n;
    if (sum > 180 * (points.size() - 2))
        return false;
    else
        return true;
}

double Polygon::area() {
    int size = points.size() - 1;
    double area{0};
    if (convex()) {


        for (int i = 0; i < size; ++i) { area += points[i].getX() * points[i + 1].getY(); }
        area += points[size].getX() * points[0].getY();

        for (int i = 0; i < size; ++i) { area -= points[i + 1].getX() * points[i].getY(); }
        area -= points[0].getX() * points[size].getY();

        return (0.5) * abs(area);
    } else {

        return 0.0;
    }
}

std::vector<double> Polygon::getEdges() { return edges; }

Triangle::Triangle(Point *arr, int size) : Polygon(arr, size) {}

Triangle::Triangle(const Triangle &ctriangle) : Polygon(ctriangle) {
    int size = ctriangle.points.size();
    for (int i = 0; i < size; ++i) { points[i] = ctriangle.points[i]; }
    for (auto &n: getEdges()) {
        if (n == 180 or n == 0) {
            exit(1);
        }
    }
}

Triangle::Triangle(Point *listP) : Polygon(listP, 3) {
    for (auto &n: getEdges()) {
        if (n == 180 or n == 0) {
            exit(1);
        }
    }
}

void Triangle::Info() {
    std::cout << "Square = " << area() << "Perimeter = " << ClosedPerimeter();
}

bool Trapezoid::check() {
    if ((((points[0].getY()) == (points[3].getY())) && ((points[1].getY()) == (points[2].getY()))) ||
        ((((points[0].getY()) == (points[1].getY())) && ((points[2].getY()) == (points[3].getY()))))) {

        return true;
    } else {
        return false;
    }

}

Trapezoid::Trapezoid(Point *listP) : Polygon(listP, 4) {

    if (!check()) {
        exit(1);
    }
}

Trapezoid::Trapezoid(const Trapezoid &ctrapezoid) : Polygon(ctrapezoid) {
    int size = ctrapezoid.points.size();
    for (int i = 0; i < size; ++i) { points[i] = ctrapezoid.points[i]; }
}

Trapezoid::Trapezoid(Point *arr, int size) : Polygon(arr, size) {}

bool RegularPolygon::check() {
    for (auto &n: edges) {
        if (n != edges[0])
            return false;
    }
    double edge = distance(points[0], points[1]);
    int size = points.size();
    for (int i = 1; i < size; ++i) {
        if (distance(points[i], points[i - 1]) != edge)
            return false;
    }
    if (distance(points[size], points[0]) != edge)
        return false;
    return true;
}

RegularPolygon::RegularPolygon(Point *arr, int size) : Polygon(arr, size) {
    if (!check()) {
        exit(1);
    }

}

RegularPolygon::RegularPolygon(const RegularPolygon &cRegularPolygon) : Polygon(cRegularPolygon) {
    int size = cRegularPolygon.points.size();
    for (int i = 0; i < size; ++i) { points[i] = cRegularPolygon.points[i]; }
}
