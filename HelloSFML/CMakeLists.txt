cmake_minimum_required(VERSION 3.23)
project(HelloSFML)

set(CMAKE_CXX_STANDARD 23)

add_executable(HelloSFML main.cpp "Source Files/Game.cpp" "Source Files/Game.h")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR F:/Data/C++/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(F:/Data/C++/SFML/include)
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

