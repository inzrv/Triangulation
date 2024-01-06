#include <iostream>
#include "types.h"

#include "drawing.h"
#include "random_poly.h"
#include "triangulation.h"

int main() {
    auto poly = randomPoly(7);
    std::vector<Segment> diagonals;
    auto res = triangulation::get_triangulation(poly, diagonals);
    if (res) {
        cv::Mat img(500, 500, CV_8UC3);
        drawPoly(img, poly, 500, {255, 255, 255}, 2);

        for(const auto& diagonal : diagonals) {
            drawSegment(img, diagonal, 500, {255, 0, 0});
        }

        cv::imshow("triangulation", img);
        cv::waitKey();
    } else {
        std::cout << "This polygon can't be triangulated\n";
    }
}
