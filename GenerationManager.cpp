/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/****************************
*   GENERATIONMANAGER.CPP   *
****************************/


#include "GenerationManager.hpp"

void gol::GenerationManager::reset(const std::string &seedFileName)
{
    m_seedFileName = seedFileName;
    m_seedFile.open(m_seedFileName, std::ios::in);

    if(!m_seedFile.is_open())
        throw std::runtime_error("ERROR :: Couldn't open the seed file '" + m_seedFileName + "'!\a");

    createUniverse();
    m_seedFile.close();
    m_childrenGeneration = m_parentGeneration;
}

void gol::GenerationManager::createUniverse()
{
    m_rows = 1;
    m_columns = 0;
    int seedValue;
    char inputChar;
    m_parentGeneration.clear();
    m_parentGeneration.push_back(std::vector<int>());

    while(m_seedFile.get(inputChar))
    {
        if(inputChar == '0' || inputChar == '1')
        {
            seedValue = inputChar - '0';
            m_parentGeneration.back().push_back(seedValue);
        }

        else if(inputChar == '\n')
        {
            m_parentGeneration.push_back(std::vector<int>());
        }
    }

    m_rows = m_parentGeneration.size();
    m_columns = m_parentGeneration[0].size();

    if(m_rows > 0)
    {
        int noOfColumns = m_parentGeneration[0].size();

        for(int I = 1; I < m_rows; I++)
        {
            if(noOfColumns != m_parentGeneration[I].size())
                throw std::runtime_error("ERROR :: The input seed contains non-mtaching no. of rows and columns!");
        }
    }
}

void gol::GenerationManager::printSeed()
{
    for(int I = 0; I < m_rows; I++)
    {
        for(int J = 0; J < m_columns; J++)
            std::cout << m_parentGeneration[I][J] << " ";

        std::cout << std::endl;
    }
}

void gol::GenerationManager::createNextGeneration()
{
    for(int I = 0; I < m_rows; I++)
    {
        for(int J = 0; J < m_columns; J++)
        {
            int aliveNeighbors = 0;

            for(int K = I - 1; K <= I + 1; K++)
            {
                int tempK = K;

                if(tempK < 0)
                    tempK = m_rows - 1;

                else if(tempK == m_rows)
                    tempK = 0;

                for(int L = J - 1; L <= J + 1; L++)
                {
                    int tempL = L;

                    if(tempL < 0)
                        tempL = m_columns - 1;

                    else if(tempL == m_columns)
                        tempL = 0;

                    if(I != tempK || J != tempL)
                    {
                        if(m_parentGeneration[tempK][tempL] == 1)
                        {
                            aliveNeighbors++;
                        }
                    }
                }
            }

            if(m_parentGeneration[I][J] == 0)
            {
                if(aliveNeighbors == 3)
                    m_childrenGeneration[I][J] = 1;
            }

            else
            {
                if(aliveNeighbors < 2)
                    m_childrenGeneration[I][J] = 0;
                if(aliveNeighbors == 2 || aliveNeighbors == 3)
                    m_childrenGeneration[I][J] = 1;
                if(aliveNeighbors > 3)
                    m_childrenGeneration[I][J] = 0;
            }
        }
    }
    m_parentGeneration = m_childrenGeneration;
}

std::vector<std::vector<int>> gol::GenerationManager::getCurrentGeneration()
{
    return m_parentGeneration;
}

std::vector<std::vector<int>> gol::GenerationManager::getNextGeneration()
{
    createNextGeneration();
    return m_childrenGeneration;
}

int gol::GenerationManager::getColumns()
{
    return m_columns;
}

int gol::GenerationManager::getRows()
{
    return m_rows;
}
