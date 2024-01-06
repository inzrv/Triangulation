#include "random_poly.h"

Polygon randomPoly(int size) {
    Polygon polygon;
    std::list<Point> point_set;
    CGAL::copy_n_unique(Point_generator(0.5), size, std::back_inserter(point_set));
    for (auto& point : point_set) {
        point += Vector(0.5, 0.5);
    }
    CGAL::random_polygon_2(point_set.size(), std::back_inserter(polygon), point_set.begin());
    return polygon;
}