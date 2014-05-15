cmake_minimum_required(VERSION 2.8)

PROJECT(GameOfLife)

macro(set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

set_option(RENDERER_SFML FALSE BOOL "TRUE to use SFML to render the scene, FALSE to just output to the terminal")

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(EXECUTABLE_NAME GameOfLife)

set(SRC
    main.cpp
    GenerationManager.cpp
    Renderer.cpp)

if (RENDERER_SFML)
    set(RENDERER_SRC RendererSFML.cpp)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DRENDERER_SFML")
else()
    set(RENDERER_SRC RendererTerminal.cpp)
endif()

add_executable(${EXECUTABLE_NAME} ${SRC} ${RENDERER_SRC})

if (RENDERER_SFML)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules CACHE STRING "The path to the cmake modules. This path must contain the FindSFML.cmake file." FORCE)

    if (SFML_OS_WINDOWS AND SFML_COMPILER_MSVC)
        find_package( SFML 2 COMPONENTS main graphics window system )
    else()
        find_package( SFML 2 COMPONENTS graphics window system )
    endif()

    if( NOT SFML_FOUND )
        set( SFML_ROOT "" CACHE PATH "SFML root directory" )
        message( FATAL_ERROR "CMake couldn't find SFML. Set the SFML_ROOT entry to SFML's root directory (containing \"include\" and \"lib\" directories)." )
    endif()
    
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${PROJECT_SOURCE_DIR})
