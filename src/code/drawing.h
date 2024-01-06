#pragma once

#include "opencv2/opencv.hpp"
#include "types.h"

void drawPoly(cv::Mat& img,
              const Polygon& poly,
              double scale = 1,
              const cv::Scalar& color = {255, 255, 255},
              int thickness = 1);

void drawSegment(cv::Mat& img,
                 const Segment& segment,
                 double scale = 1,
                 const cv::Scalar& color = {255, 255, 255},
                 int thickness = 1);