cmake_minimum_required(VERSION 3.26)

project(CppServiceExample LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${TARGET_SPECIFIC_DEBUG_OPTIONS}>")
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:RELEASE>:${TARGET_SPECIFIC_RELEASE_OPTIONS}>")

target_link_libraries(${PROJECT_NAME}
  PRIVATE 
  CppService::CppService
  spdlog::spdlog
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
