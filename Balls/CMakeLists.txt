cmake_minimum_required(VERSION 3.23)
project(Balls)

set(CMAKE_CXX_STANDARD 23)

add_executable(Balls main.cpp "Source Files/Game.cpp" "Header Files/Game.h" "Source Files/Player.cpp" "Header Files/Player.h" "Source Files/SwagBall.cpp" "Header Files/SwagBall.h")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR F:/Data/C++/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(F:/Data/C++/SFML/include)
target_link_libraries(Balls sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


