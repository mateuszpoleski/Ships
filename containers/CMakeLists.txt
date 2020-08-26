add_library(
    container
    Container.hpp
    Container.cpp
)

target_include_directories(container PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
    small_container
    SmallContainer.hpp
    SmallContainer.cpp
)

target_include_directories(small_container PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
    big_container
    BigContainer.hpp
    BigContainer.cpp
)

target_include_directories(big_container PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
