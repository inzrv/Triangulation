#include "triangulation.h"

using namespace triangulation;

bool triangulation::get_triangulation(const Polygon& polygon, std::vector<Segment>& result) {
    if(polygon.size() < 3) {
        std::cout << "The polygon is degenerate" << std::endl;
        return false;
    }
    if(polygon.size() == 3) {
        // The polygon is a triangle 
        return true;
    }
    if(!polygon.is_simple()) {
        std::cout << "The polygon is not simple" << std::endl;
        return false;
    }

    const auto& leftmost = polygon.left_vertex();
    const auto diagonal = get_diagonal(leftmost, polygon);

    Segment seg(*diagonal.first, *diagonal.second);
    result.push_back(seg);

    Polygon polygon_a;
    Polygon polygon_b;
    split_polygon(polygon, diagonal, polygon_a, polygon_b);

    // std::cout << "Polygon A:" << polygon_a << std::endl;
    // std::cout << "Polygon B:" << polygon_b << std::endl;
 
    auto res_a = get_triangulation(polygon_a, result);
    auto res_b = get_triangulation(polygon_b, result);
    return res_a && res_b;
}

void triangulation::split_polygon(const Polygon& polygon, const Diagonal& diagonal, Polygon& polygon_a, Polygon& polygon_b)
{
    auto v_iter = polygon.vertices_begin();
    std::vector<Point> poly_a_points;

    while(v_iter != diagonal.first && v_iter != diagonal.second) {
        poly_a_points.push_back(*v_iter);
        v_iter++;
    }
    Vertex_iterator diag_begin = (v_iter == diagonal.first) ? diagonal.first : diagonal.second;
    Vertex_iterator diag_end = (diag_begin == diagonal.first) ? diagonal.second : diagonal.first;
    poly_a_points.push_back(*diag_begin);

    std::vector<Point> poly_b_points;
    while (v_iter != diag_end) {
        poly_b_points.push_back(*v_iter);
        v_iter++;
    }
    poly_b_points.push_back(*diag_end);

    while(v_iter != polygon.vertices_end()) {
        poly_a_points.push_back(*v_iter);
        v_iter++;
    }
    polygon_a = Polygon(poly_a_points.begin(), poly_a_points.end());
    polygon_b = Polygon(poly_b_points.begin(), poly_b_points.end());
}

Diagonal triangulation::get_diagonal(Vertex_iterator leftmost, const Polygon& polygon) {

    auto next = leftmost;
    if (leftmost + 1 == polygon.vertices_end()) {
        next = polygon.vertices_begin();
    }
    else {
        next = leftmost + 1;
    }

    auto previous = leftmost;
    if (leftmost == polygon.vertices_begin()) {
        previous = polygon.vertices_end() - 1;
    }
    else {
        previous = leftmost - 1;
    }

    std::set<Vertex_iterator> inside;
    const Triangle triangle(*leftmost, *next, *previous);
    for (auto vertex = polygon.vertices_begin(); vertex != polygon.vertices_end(); ++vertex) {
        if (vertex != leftmost && vertex != next && vertex != previous) {
            if (is_point_inside_triangle(*vertex, triangle)) {
                inside.insert(vertex);
            } 
        }
    }
    if (inside.empty())
    {
        return {previous, next};
    }
    auto farthest = get_farthest_vertex(Line(*next, *previous), inside);
    return {leftmost, farthest};
}


Vertex_iterator triangulation::get_farthest_vertex(const Line& line, const std::set<Vertex_iterator>& vertices) {
    Vertex_iterator farthest_vertex = *vertices.begin();
    auto max_sq_dst = CGAL::squared_distance(*farthest_vertex, line);
    for (const auto& vertex : vertices) {
        auto sq_dst = CGAL::squared_distance(*vertex, line);
        if (sq_dst > max_sq_dst) {
            max_sq_dst = sq_dst;
            farthest_vertex = vertex;
        }
    }
    return farthest_vertex;
}

bool triangulation::is_point_inside_triangle(const Point& vertex, const Triangle& triangle) {
    return triangle.bounded_side(vertex) != CGAL::ON_UNBOUNDED_SIDE;
}