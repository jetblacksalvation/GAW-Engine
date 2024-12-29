cmake_minimum_required(VERSION 3.8)

project("GAW-Engine")

add_executable(GAW-Engine "GAW-Engine.cpp" "GAW-Engine.h")

include(FetchContent)

FetchContent_Declare(
  OOGL
  GIT_REPOSITORY https://github.com/jetblacksalvation/OOGL-Cmake.git
  GIT_TAG        master  
)
add_definitions(-DSCRIPTS="${CMAKE_SOURCE_DIR}/glsl_scripts")

FetchContent_MakeAvailable(OOGL)

message(STATUS "OOGL_SOURCE_DIR: ${OOGL_SOURCE_DIR}")
message(STATUS "OOGL_SOURCE_DIR: ${OOGL_SOURCE_DIR}/src/GL")

add_subdirectory(${OOGL_SOURCE_DIR}/src/GL)

target_include_directories(GAW-Engine
    PRIVATE
        ${OOGL_SOURCE_DIR}/include
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GAW-Engine PROPERTY CXX_STANDARD 20)
endif()
