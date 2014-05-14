/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/*******************
*   RENDERER.CPP   *
********************/


#include "Renderer.hpp"
#include "Config.hpp"


void gol::Renderer::init()
{
    m_defaultSeedFiles[1] = FOLDER + "BlinkerSeed.txt";
    m_defaultSeedFiles[2] = FOLDER + "ToadSeed.txt";
    m_defaultSeedFiles[3] = FOLDER + "BeaconSeed.txt";
    m_defaultSeedFiles[4] = FOLDER + "PulsarSeed.txt";
    m_defaultSeedFiles[5] = FOLDER + "GliderSeed.txt";
    m_defaultSeedFiles[6] = FOLDER + "LWSSSeed.txt";
    m_defaultSeedFiles[7] = FOLDER + "GosperGliderSeed.txt";
    m_defaultSeedFiles[8] = FOLDER + "RPentominoSeed.txt";
    m_defaultSeedFiles[9] = FOLDER + "DieHardSeed.txt";
    m_defaultSeedFiles[10] = FOLDER + "AcornSeed.txt";

    m_running = true;
}

const std::string &gol::Renderer::getSeedFileName()
{
    return m_defaultSeedFiles.at(m_seedChoice);
}

void gol::Renderer::setSeedFileName(const std::string &fileName)
{
    m_defaultSeedFiles[11] = fileName;
}

bool gol::Renderer::isGameRunning()
{
    return m_running;
}
