#pragma once

#include <iostream>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/Vector_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/enum.h>
#include <CGAL/Random.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/random_polygon_2.h>
#include "opencv2/opencv.hpp"
#include <vector>


typedef CGAL::Cartesian<double> Rep_class;
typedef CGAL::Point_2<Rep_class> Point;
typedef CGAL::Vector_2<Rep_class> Vector;
typedef CGAL::Segment_2<Rep_class> Segment;
typedef CGAL::Line_2<Rep_class> Line;
typedef CGAL::Polygon_2<Rep_class> Polygon;
typedef CGAL::Triangle_2<Rep_class> Triangle;
typedef CGAL::Origin Origin;
typedef CGAL::Creator_uniform_2<double, Point> Creator;
typedef CGAL::Random_points_in_square_2<Point, Creator> Point_generator;
typedef Polygon::Vertex_const_circulator Vertex_circulator;
typedef Polygon::Vertex_const_iterator Vertex_iterator;
typedef std::pair<Vertex_iterator, Vertex_iterator> Diagonal;