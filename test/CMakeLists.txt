cmake_minimum_required(VERSION 3.12)
project(ships_test)

add_executable( runItemTests testItem.cpp )
target_link_libraries(runItemTests item gtest gtest_main pthread)
add_test( runItemTests runItemTests )

add_executable( runShipTests testShip.cpp )
target_link_libraries(runShipTests ship small_container big_container container item gtest gtest_main pthread)
add_test( runShipTests runShipTests )

add_executable( runShipMocks mockShip.cpp )
target_link_libraries(runShipMocks ship small_container big_container container item gtest gmock gtest_main pthread)
add_test(runShipMocks runShipMocks )