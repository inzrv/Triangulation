#include "drawing.h"


void drawPoly(cv::Mat& img, const Polygon& poly, double scale, const cv::Scalar& color, int thickness)
{
    std::vector<cv::Point> cv_points;
    cv_points.reserve(poly.size());
    for (const auto& vertex : poly.vertices()) {
        cv_points.emplace_back((int)(vertex.x() * scale), (int)(vertex.y() * scale));
    }
    cv::polylines(img, cv_points, true, color, thickness);
    for (const auto& point : cv_points) {
        cv::circle(img, point, thickness * 2, color, -1);
    }
}

void drawSegment(cv::Mat& img, const Segment& segment, double scale, const cv::Scalar& color, int thickness)
{
    const auto& source = segment.source();
    const auto& target = segment.target();
    cv::Point begin((int)(source.x() * scale), (int)(source.y() * scale));
    cv::Point end((int)(target.x() * scale), (int)(target.y() * scale));
    cv::line(img, begin, end, color, thickness);
}