/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/***************************
*   RENDERERTERMINAL.HPP   *
***************************/


#ifndef RENDERERTERMINAL_HPP
#define RENDERERTERMINAL_HPP


#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include "Renderer.hpp"

namespace gol
{
    class RendererTerminal : public Renderer
    {
        public:
            bool render(const std::vector<std::vector<int>> &generation, const int &rows, const int &columns);
            bool menu();

        private:
            void clearScreen();

            int m_generationCounter;
            int m_NoOfGenerations;
    };
}

#endif // RENDERERTERMINAL_HPP
