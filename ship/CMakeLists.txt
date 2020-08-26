add_library(
    ship
    Ship.hpp
    Ship.cpp
)

target_include_directories(ship PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")