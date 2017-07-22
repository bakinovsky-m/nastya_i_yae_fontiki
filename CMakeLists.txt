cmake_minimum_required(VERSION 3.5)

project(fonts)

add_compile_options(-Wall -std=c++11)

if("${SFML_INSTALL_DIR}" STREQUAL "")
    message(FATAL_ERROR "sfml install dir is not set. set it by cmake -DSFML_INSTALL_DIR=<path> <path_to_this_CMakeLists.txt> .")
ENDIF("${SFML_INSTALL_DIR}" STREQUAL "")

message("sfml install dir: ${SFML_INSTALL_DIR}")

include_directories(${SFML_INSTALL_DIR}/include/)
link_directories(${SFML_INSTALL_DIR}/build/lib)
link_directories(${SFML_INSTALL_DIR}/lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

unset(SFML_INSTALL_DIR CACHE)