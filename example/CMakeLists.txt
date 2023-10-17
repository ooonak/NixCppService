cmake_minimum_required(VERSION 3.26)

project(CppServiceExample LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE 
  CppService::CppService
  spdlog::spdlog
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
