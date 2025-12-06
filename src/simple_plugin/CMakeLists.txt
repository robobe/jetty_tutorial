cmake_minimum_required(VERSION 3.10)
project(SimpleParamReader)

find_package(gz-sim REQUIRED)
find_package(gz-plugin REQUIRED)

add_library(ListLinksAndJointsPlugin SHARED simple.cpp)

target_link_libraries(ListLinksAndJointsPlugin
  gz-sim::gz-sim
  gz-plugin::gz-plugin
)

install(TARGETS ListLinksAndJointsPlugin
  LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/bin)
