cmake_minimum_required(VERSION 3.8)

project("GAW-Engine")
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
include(FindOpenGL)

FetchContent_Declare(
  OOGL
  GIT_REPOSITORY https://github.com/jetblacksalvation/OOGL-Cmake.git
  GIT_TAG        master  
)
FetchContent_GetProperties(OOGL)

add_executable(GAW-EngineExe "src/GAW_RenderMain/GAW-Engine.cpp")
add_library(GAW-EngineLib "src/GAW_RenderMain/GAW-Engine.cpp")

if(NOT OOGL_POPULATED)
  FetchContent_Populate(dependency1)

    target_include_directories(GAW-EngineLib PUBLIC "${OOGL_SOURCE_DIR}/include")
    target_include_directories(GAW-EngineLib PUBLIC "${OOGL_SOURCE_DIR}/src/GL")

    target_include_directories(GAW-EngineExe PUBLIC "${OOGL_SOURCE_DIR}/include")
    target_include_directories(GAW-EngineExe PUBLIC "${OOGL_SOURCE_DIR}/src/GL")
endif()



message(STATUS "OOGL_SOURCE_DIR: ${OOGL_SOURCE_DIR}")
message(STATUS "OOGL_SOURCE_DIR: ${OOGL_SOURCE_DIR}/src/GL")
FetchContent_MakeAvailable(OOGL)

add_definitions(-DSCRIPTS="${CMAKE_SOURCE_DIR}/glsl_scripts")



add_subdirectory("${OOGL_SOURCE_DIR}/src/GL")



add_subdirectory("src")
add_subdirectory("includes")

target_include_directories(GAW-EngineLib PUBLIC  "includes")
target_include_directories(GAW-EngineLib PUBLIC  "src")

target_include_directories(GAW-EngineExe PUBLIC  "includes")
target_include_directories(GAW-EngineExe PUBLIC  "src")

find_package(OpenGL REQUIRED)
#target_link_libraries(GAW-EngineLib OpenGL::GL)
find_library(OOGL oogl)

target_link_libraries(GAW-EngineExe oogl)
#target_link_libraries(GAW-EngineExe PUBLIC  OOGL OpenGL::GL)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    #install and link x11 
    message(STATUS "Configuring for Linux platform")
    set(OOGL_PLATFORM_LINUX ON)
    # Find X11
    find_package(X11 REQUIRED)

    # Link X11 to your target
    target_link_libraries(GAW-EngineLib PRIVATE X11::X11)

endif()

#OOOGL EXE SECTION


target_include_directories(GAW-EngineExe PRIVATE "include")




