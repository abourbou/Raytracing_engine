cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(RaytracingEngine
        LANGUAGES CXX
        VERSION 1.0)

#-------------------------
#  CMake parameters
#-------------------------

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard")
message(STATUS "Building {CMAKE_PROJECT_NAME} with C++${CMAKE_CXX_STANDARD} standard")

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "RelWithDebInfo" "Release")
endif()

#-------------------------
#  Find dependencies
#-------------------------

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(Eigen3 3.4 REQUIRED)


#-------------------------
#  Build and install
#-------------------------

set(APP_SOURCES
    AppRenderer.cpp
    ImageHandler.cpp)
list(TRANSFORM APP_SOURCES PREPEND src/app/)


set(ENGINE_SOURCES
    Camera.cpp)
list(TRANSFORM ENGINE_SOURCES PREPEND src/engine/)

message(INFO ${ENGINE_SOURCES})

add_executable(RaytracingEngine
                src/main.cpp
                ${APP_SOURCES}
                ${ENGINE_SOURCES}
                )

target_include_directories(RaytracingEngine
                            PUBLIC  include
                                    include/app
                                    include/engine
                                    )

target_link_libraries(RaytracingEngine
                        ${SDL2_LIBRARIES}
                        Eigen3::Eigen)