/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/***********************
*   RENDERERSFML.HPP   *
************************/


#ifndef RENDERERSFML_HPP
#define RENDERERSFML_HPP


#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Renderer.hpp"

namespace gol
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const int BPP = 32;
    const std::string TITLE = "Conway's Game of Life (written by Koushtav Chakrabarty)";

    const sf::Color CELL_COLOR = sf::Color::Red;

    class RendererSFML : public Renderer
    {
        public:
            bool render(const std::vector<std::vector<int>> &generation, const int &rows, const int &columns);
            bool menu();

            RendererSFML();

        private:
            std::string m_globalFontFile;
            sf::Font m_golbalFont;
            sf::RenderWindow m_window;
            sf::RectangleShape m_cell;
    };
}

#endif // RENDERERSFML_HPP
