cmake_minimum_required(VERSION 3.26)

project(CppServiceTests LANGUAGES CXX)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    ServiceTests.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  CppService::CppService
  spdlog::spdlog
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
