cmake_minimum_required(VERSION 3.10)
project(PRIV_fluid_solver)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

if (UNIX)

    set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
    set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

    link_directories(SFML_LIBRARY_DIR)
    include_directories(include)
    include_directories(SFML_INCLUDE_DIR)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

    if (SFML_FOUND)
        message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
        message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
        message(STATUS "SFML_VERSION: ${SFML_VERSION}")
    endif ()

    file(GLOB SOURCES src/*.cpp)
    set(SOURCES src/main.cpp ${SOURCES} include/Random.h)
    add_executable(PRIV_fluid_solver ${SOURCES})

    target_link_libraries(PRIV_fluid_solver sfml-graphics sfml-window sfml-system)

endif ()