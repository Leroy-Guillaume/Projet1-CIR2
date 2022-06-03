cmake_minimum_required (VERSION 3.20)

project(Project1-CIR2)


set(SRCS threads/plane.hpp threads/airport.hpp source.cpp tools/coordinatesXY.hpp tools/trajectory.h++ threads/planeThreadFunction.hpp)

add_executable (Project1-CIR2 ${SRCS})

find_package (Threads)

target_compile_features(Project1-CIR2 PUBLIC cxx_std_17)
target_link_libraries (Project1-CIR2 Threads::Threads)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Project1-CIR2 sfml-system sfml-window sfml-graphics sfml-audio)