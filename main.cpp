/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
*********************************************************************
*                                                                   *
*     A C++ implementation of the famous Conay's Game of Life       *
*     (http://en.wikipedia.org/wiki/Conway's_Game_of_Life).         *
*     Special thanks to texus(http://github.com/texus) as usual     *
*     for his infinite patience.                                    *
*                                                                   *
*********************************************************************
*                                                                   *
*    To compile the terminal version (without graphics), just       *
*    compile as it is. Or if you want graphics, then add the        *
*    preprocessor definition RENDERER_SFML and you can compile      *
*    the graphical version if you have SFML installed on your       *
*    machine.                                                       *
*                                                                   *
********************************************************************/

/***************
*   MAIN.CPP   *
***************/


#include <iostream>
#include <stdexcept>
#include "Config.hpp"
#include "GenerationManager.hpp"

int main()
{
    try{
        gol::GenerationManager m_generationManager;
        RENDERER m_renderer;
        m_renderer.init();

        while(m_renderer.isGameRunning())
        {
            if(!m_renderer.menu())
                return 0;
            m_generationManager.reset(m_renderer.getSeedFileName());

            while(m_renderer.render(m_generationManager.getCurrentGeneration(), m_generationManager.getRows(), m_generationManager.getColumns()))
            {
                m_generationManager.createNextGeneration();
                SLEEP(SLEEP_TIME);
            }
        }
    } catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}
