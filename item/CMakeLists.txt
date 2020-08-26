add_library(
    item
    Item.hpp
    Item.cpp
)

target_include_directories(item PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")