cmake_minimum_required(VERSION 3.26)

project(CppService VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/cppservice/Service.hpp
    Service.cpp
    ServiceImpl.hpp
    ServiceImpl.cpp
)

file(WRITE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.hpp.in "
#pragma once

#define ${PROJECT_NAME}_VERSION_MAJOR @${PROJECT_NAME}_VERSION_MAJOR@
#define ${PROJECT_NAME}_VERSION_MINOR @${PROJECT_NAME}_VERSION_MINOR@
#define ${PROJECT_NAME}_VERSION_PATCH @${PROJECT_NAME}_VERSION_PATCH@
")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${TARGET_SPECIFIC_DEBUG_OPTIONS}>")
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:RELEASE>:${TARGET_SPECIFIC_RELEASE_OPTIONS}>")

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}
   PRIVATE
   spdlog::spdlog
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

configure_file("${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.hpp.in" ${PROJECT_NAME}Config.hpp)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/cppservice
        DESTINATION include
        COMPONENT Devel
)

if (BUILD_PACKAGE)
    set(package_files ./ ./include)
    message(STATUS "package_files ${package_files}")
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip
        COMMAND ${CMAKE_COMMAND} -E tar c ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip --format=zip -- ${package_files}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${package_files})
    add_custom_target(${PROJECT_NAME}Package DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-src.zip)
endif(BUILD_PACKAGE)
