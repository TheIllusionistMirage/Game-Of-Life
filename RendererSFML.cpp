/********************************************************************
*                   CONWAY's GAME OF LIFE                           *
*                                                                   *
*   Written by Koushtav Chakrabarty a.k.a. The Illusionist Mirage   *
*                                                                   *
********************************************************************/

/***********************
*   RENDERERSFML.CPP   *
************************/


#include "RendererSFML.hpp"


gol::RendererSFML::RendererSFML()
{
    m_window.create(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, sf::Style::Close);
    m_cell.setSize(sf::Vector2f(8.f, 8.f));
    m_cell.setFillColor(CELL_COLOR);
    m_globalFontFile = "Seeds/Graphical/DejaVuSans.ttf";

    if(!m_golbalFont.loadFromFile(m_globalFontFile))
        throw std::runtime_error("ERROR :: Unable to open font file '" + m_globalFontFile + "' !");
}

bool gol::RendererSFML::menu()
{
    m_seedChoice = 0;

    float fontSize = 20.f;
    sf::Vector2f textPosition = sf::Vector2f(20.f, 20.f);

    sf::Text title("CONWAY'S GAME OF LIFE", m_golbalFont, fontSize + 30.f);
    title.setColor(sf::Color::Green);
    title.setPosition(sf::Vector2f(textPosition.x, textPosition.y));

    sf::Text options("SELECT YOUR CHOICE :-", m_golbalFont, fontSize + 10.f);
    options.setColor(sf::Color::Red);
    options.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 70.f));

    sf::Text option1("1.   Blinker Seed", m_golbalFont, fontSize);
    option1.setColor(sf::Color::White);
    option1.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 120.f));

    sf::Text option2("2.   Toad Seed", m_golbalFont, fontSize);
    option2.setColor(sf::Color::White);
    option2.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 145.f));

    sf::Text option3("3.   Beacon Seed", m_golbalFont, fontSize);
    option3.setColor(sf::Color::White);
    option3.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 170.f));

    sf::Text option4("4.   Pulsar Seed", m_golbalFont, fontSize);
    option4.setColor(sf::Color::White);
    option4.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 195.f));

    sf::Text option5("5.   Glider Seed", m_golbalFont, fontSize);
    option5.setColor(sf::Color::White);
    option5.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 220.f));

    sf::Text option6("6.   Lightweight spaceship (LWSS) Seed", m_golbalFont, fontSize);
    option6.setColor(sf::Color::White);
    option6.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 245.f));

    sf::Text option7("7.   Gosper Glider Gun Seed", m_golbalFont, fontSize);
    option7.setColor(sf::Color::White);
    option7.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 270.f));

    sf::Text option8("8.   R-pentomino Seed", m_golbalFont, fontSize);
    option8.setColor(sf::Color::White);
    option8.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 295.f));

    sf::Text option9("9.   Diehard Seed", m_golbalFont, fontSize);
    option9.setColor(sf::Color::White);
    option9.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 325.f));

    sf::Text option10("10. Acorn Seed", m_golbalFont, fontSize);
    option10.setColor(sf::Color::White);
    option10.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 350.f));

    sf::Text option11("11. SPECIFY YOUR OWN SEED", m_golbalFont, fontSize);
    option11.setColor(sf::Color::White);
    option11.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 375.f));

    sf::Text option12("12. EXIT", m_golbalFont, fontSize);
    option12.setColor(sf::Color::White);
    option12.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 400.f));

    sf::Text choiceLabel("YOUR CHOICE : ", m_golbalFont, fontSize);
    choiceLabel.setColor(sf::Color::White);
    choiceLabel.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 455.f));

    sf::Text choiceText("", m_golbalFont, fontSize);
    choiceText.setColor(sf::Color::Cyan);
    choiceText.setPosition(sf::Vector2f(textPosition.x + 170.f, textPosition.y + 455.f));
    sf::String choiceString;

    sf::Text userSeedLabel("ENTER THE SEED FILE NAME : ", m_golbalFont, fontSize);
    userSeedLabel.setColor(sf::Color::Green);
    userSeedLabel.setPosition(sf::Vector2f(textPosition.x, textPosition.y + 500.f));

    sf::Text userSeedText("", m_golbalFont, fontSize);
    userSeedText.setColor(sf::Color::Cyan);
    userSeedText.setPosition(sf::Vector2f(textPosition.x + 320.f, textPosition.y + 500.f));

    sf::String userSeedString;
    std::string customSeedFile;

    bool isInMainMenu = true;

    while(m_window.isOpen())
    {
        sf::Event event;

        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_window.close();
                return false;
            }

            if(event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                if(m_seedChoice != 0)
                {
                    if(m_seedChoice == 12)
                        return false;
                }

                else if(m_seedChoice == 11)
                    isInMainMenu = false;

                else
                    return true;
            }

            if(event.type == sf::Event::TextEntered && isInMainMenu)
            {
                if(event.text.unicode >= 48 && event.text.unicode <= 57)
                    choiceString += (char)event.text.unicode;
                else if(event.text.unicode == 8 && choiceString.getSize() > 0)
					choiceString.erase(choiceString.getSize() - 1, choiceString.getSize());
                choiceText.setString(choiceString);
                std::string str = choiceString.toAnsiString();
                m_seedChoice = std::atoi(str.c_str());
            }

            if(m_seedChoice == 11 && !isInMainMenu)
            {
                if(event.type == sf::Event::TextEntered)
                {
                    if((event.text.unicode >= 32  && event.text.unicode <= 57)
                       || (event.text.unicode >= 64  && event.text.unicode <= 126))

                        userSeedString += (char)event.text.unicode;

                    else if(event.text.unicode == 8 && userSeedString.getSize() > 0)
                        userSeedString.erase(userSeedString.getSize() - 1, userSeedString.getSize());

                    userSeedText.setString(userSeedString);
                }

                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                {
                    customSeedFile = userSeedString.toAnsiString();
                    setSeedFileName(customSeedFile);

                    return true;
                }
            }
        }

        m_window.clear(sf::Color::Black);

        m_window.draw(title);
        m_window.draw(options);
        m_window.draw(option1);
        m_window.draw(option2);
        m_window.draw(option3);
        m_window.draw(option4);
        m_window.draw(option5);
        m_window.draw(option6);
        m_window.draw(option7);
        m_window.draw(option8);
        m_window.draw(option9);
        m_window.draw(option10);
        m_window.draw(option11);
        m_window.draw(option12);
        m_window.draw(choiceLabel);
        m_window.draw(choiceText);

        if(!isInMainMenu)
        {
            m_window.draw(userSeedLabel);
            m_window.draw(userSeedText);
        }

        m_window.display();
    }
}

bool gol::RendererSFML::render(const std::vector<std::vector<int>> &generation, const int &rows, const int &columns)
{
    sf::Text escapePlan("PRESS ESC TO GO BACK TO MAIN MENU", m_golbalFont, 12.f);
    escapePlan.setColor(sf::Color::Green);
    escapePlan.setPosition(sf::Vector2f(gol::WIDTH - 250.f, gol::HEIGHT - 20.f));

    if(m_window.isOpen())
    {
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_window.close();
                return false;
            }

            if(event.type == sf::Event::KeyPressed)
                if(event.key.code == sf::Keyboard::Escape)
                    return false;
        }

        m_window.clear(sf::Color::Black);

        for(int I = 0; I < rows; I++)
        {
            for(int J = 0; J < columns; J++)
            {
                if(generation[I][J] == 1)
                {
                    m_cell.setPosition(sf::Vector2f(J * 10 + 10, I * 10 + 10));
                    m_window.draw(m_cell);
                }
            }
        }

        m_window.draw(escapePlan);
        m_window.display();

        return true;
    }

    return false;
}
