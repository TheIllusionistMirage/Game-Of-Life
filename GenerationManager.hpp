/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/****************************
*   GENERATIONMANAGER.HPP   *
****************************/


#ifndef GENERATIONMANAGER_HPP
#define GENERATIONMANAGER_HPP


#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

namespace gol
{
    class GenerationManager
    {
        public:
            int getColumns();
            int getRows();
            std::vector<std::vector<int>> getNextGeneration();
            std::vector<std::vector<int>> getCurrentGeneration();
            void createNextGeneration();
            void printSeed();
            void reset(const std::string &seedFileName);

        private:
            void createUniverse();

            unsigned m_columns;
            unsigned m_rows;
            std::vector<std::vector<int>> m_childrenGeneration;
            std::vector<std::vector<int>> m_parentGeneration;
            std::ifstream m_seedFile;
            std::string m_seedFileName;
    };
}

#endif // GENERATIONMANAGER_HPP
