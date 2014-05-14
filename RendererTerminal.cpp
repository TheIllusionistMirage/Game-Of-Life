/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/***************************
*   RENDERERTERMINAL.CPP   *
***************************/


#include "RendererTerminal.hpp"
#include "Config.hpp"


bool gol::RendererTerminal::menu()
{
    clearScreen();

    std::cout << "-----------------------------" << std::endl;
    std::cout << "|   CONWAY'S GAME OF LIFE   |" << std::endl;
    std::cout << "-----------------------------" << std::endl << std::endl;
    std::cout << "SELECT THE SEED FOR THE PROGRAM :-" << std::endl;
    std::cout << " 1.  Blinker Seed" << std::endl;
    std::cout << " 2.  Toad Seed" << std::endl;
    std::cout << " 3.  Beacon Seed" << std::endl;
    std::cout << " 4.  Pulsar Seed" << std::endl;
    std::cout << " 5.  Glider Seed" << std::endl;
    std::cout << " 6.  Lightweight spaceship (LWSS) Seed" << std::endl;
    std::cout << " 7.  Gosper Glider Gun Seed" << std::endl;
    std::cout << " 8.  The R-pentomino Seed" << std::endl;
    std::cout << " 9.  Diehard Seed" << std::endl;
    std::cout << " 10. Acorn Seed" << std::endl;
    std::cout << " 11. Specify your own seed" << std::endl;
    std::cout << " 12. EXIT" << std::endl << std::endl;

    std::cout << "YOUR CHOICE : ";
    std::cin >> m_seedChoice;
    std::cout << std::endl;

    if(m_seedChoice == 11)
    {
        std::string customSeedFile;
        std::cout << "Enter the seed file name : ";
        std::cin >> customSeedFile;

        setSeedFileName(customSeedFile);
    }

    if(m_seedChoice == 12)
        return false;

    std::cout << "Enter the number of generations upto which you'd want to play the \"Game of Life\"? : ";
    std::cin >> m_NoOfGenerations;
    std::cin.ignore();
    m_generationCounter = 0;

    return true;
}

bool gol::RendererTerminal::render(const std::vector<std::vector<int>> &generation, const int &rows, const int &columns)
{
    if(m_generationCounter > m_NoOfGenerations)
    {
        std::cout << std::endl << "Press ENTER to continue.";
        std::cin.get();
        return false;
    }

    clearScreen();

    std::cout << "Current generation : " << m_generationCounter << std::endl;

    for(int I = 0; I < columns + 4; I++)
        std::cout << "-";
    std::cout << std::endl << "|";

    for(int I = 0; I < columns + 2; I++)
        std::cout << " ";
    std::cout << "|" << std::endl;

    for(int I = 0; I < rows; I++)
    {
        std::cout << "| ";

        for(int J = 0; J < columns; J++)
        {
            if(generation[I][J] == 1)
                std::cout << "*";

            else
                std::cout << " ";
        }
        std::cout << " |" << std::endl;
    }

    std::cout << "|";

    for(int I = 0; I < columns + 2; I++)
        std::cout << " ";
    std::cout << "|" << std::endl;

    for(int I = 0; I < columns + 4; I++)
        std::cout << "-";

    m_generationCounter++;

    return true;
}

void gol::RendererTerminal::clearScreen()
{
    CLEAR_SCREEN;
}

