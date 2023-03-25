cmake_minimum_required(VERSION 3.15)
project(finalProjectBuild)

# set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_FLAGS -o)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# # configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
# execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#         RESULT_VARIABLE result
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
# if (result)
#     message(FATAL_ERROR "CMake step for googletest failed: ${result}")
# endif ()
# execute_process(COMMAND ${CMAKE_COMMAND} --build .
#         RESULT_VARIABLE result
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
# if (result)
#     message(FATAL_ERROR "Build step for googletest failed: ${result}")
# endif ()

# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
#         ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
#         EXCLUDE_FROM_ALL)

# if (CMAKE_VERSION VERSION_LESS 2.8.11)
#     include_directories("${gtest_SOURCE_DIR}/include")
# endif ()

# add_compile_options(-o, -O0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

ADD_EXECUTABLE(BuildV1.0.0
    source/main.cpp
    source/player.cpp
    source/character.cpp
    source/combat.cpp
    source/enemy.cpp
    source/inventory.cpp
    source/game.cpp
    source/stage.cpp
)

TARGET_LINK_LIBRARIES(BuildV1.0.0)