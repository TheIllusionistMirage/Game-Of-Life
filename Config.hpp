/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/*****************
*   CONFIG.HPP   *
*****************/


#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#if defined (RENDERER_SFML)
    #include "RendererSFML.hpp"
    #define RENDERER gol::RendererSFML
    const std::string FOLDER = "Seeds/Graphical/";

#else
    #include "RendererTerminal.hpp"
    #define RENDERER gol::RendererTerminal
    const std::string FOLDER = "Seeds/Terminal/";
#endif

#if defined(_WIN32)
    #include <windows.h>
    #define SLEEP Sleep
    #define SLEEP_TIME 200
    #define CLEAR_SCREEN system("cls")

#else
    #include <unistd.h>
    #define SLEEP usleep
    #define SLEEP_TIME 200 * 1000
    #define CLEAR_SCREEN system("clear")
#endif

#endif // CONFIG_HPP_INCLUDED
