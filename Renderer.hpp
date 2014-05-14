/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/*******************
*   RENDERER.HPP   *
********************/


#ifndef RENDERER_HPP
#define RENDERER_HPP


#include <map>
#include <vector>

namespace gol
{
    class Renderer
    {
        public:
            bool isGameRunning();
            void setSeedFileName(const std::string &fileName);
            const std::string &getSeedFileName();
            virtual bool menu() = 0;
            virtual bool render(const std::vector<std::vector<int>> &generation, const int &rows, const int &columns) = 0;
            void init();

            bool m_running;
            int m_seedChoice;

        private:
            std::string m_customSeed;
            std::map<int, std::string > m_defaultSeedFiles;
    };
}

#endif // RENDERER_HPP
