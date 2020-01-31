cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGETNAME expressions)

add_subdirectory(googletest)
add_executable(${TARGETNAME} test.cpp)
target_link_libraries(${TARGETNAME} gtest gtest_main pthread)

add_custom_command(
  TARGET ${TARGETNAME}
  POST_BUILD
  COMMAND ${TARGETNAME}
)
