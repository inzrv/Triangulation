#pragma once
#include "types.h"

namespace triangulation {
    bool get_triangulation(const Polygon& polygon, std::vector<Segment>& result);
    void split_polygon(const Polygon& polygon, const Diagonal& diagonal, Polygon& polygon_a, Polygon& polygon_b);
    Diagonal get_diagonal(Vertex_iterator leftmost, const Polygon& polygon);
    Vertex_iterator get_farthest_vertex(const Line& line, const std::set<Vertex_iterator>& vertices);
    bool is_point_inside_triangle(const Point& vertex, const Triangle& triangle);
};
