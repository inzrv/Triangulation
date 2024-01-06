cmake_minimum_required(VERSION 3.24)
project(Triangulation)

set(CMAKE_CXX_STANDARD 17)
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
# include_directories("/usr/local/Cellar/opencv/4.6.0_1/include/opencv4/opencv2/")

find_package(CGAL)

add_executable(Triangulation 
               code/main.cpp
               code/random_poly.cpp
               code/drawing.cpp
               code/triangulation.cpp)

target_link_libraries(Triangulation CGAL::CGAL)
target_link_libraries(Triangulation ${OpenCV_LIBS})