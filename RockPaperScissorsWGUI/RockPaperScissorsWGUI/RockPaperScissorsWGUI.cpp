#include "gui.hpp"

int randomNumber()
{
    return rand() % 3;
}

int main()
{
    sf::RenderWindow window;
    srand((unsigned)time(0));
    int playerScore = 0;
    int botScore = 0;
    int random = randomNumber();
    std::string botChoice;
    GUI::Init(&window, sf::VideoMode(610, 600), "Rock Paper Scissors - GUI - Library");

    while (window.isOpen())
    {
        sf::Event event;
        GUI::TextPanel(20, 50, 200, 60, sf::Color(51, 51, 51), std::to_string(playerScore), sf::Color::White);
        GUI::TextPanel(390, 50, 200, 60, sf::Color(51, 51, 51), std::to_string(botScore), sf::Color::White);
        GUI::TextPanel(100, 250, 400, 60, sf::Color(51, 51, 51), "Bot Chose: " + botChoice, sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            GUI::PollEvent(event);

            if (GUI::Button(20, 350, 170, 150, sf::Color(51, 51, 51), "Rock", sf::Color::White, true))
            {
                random = randomNumber() + 1;

                if (random == 1)
                {
                    playerScore++;
                    botScore++;
                    botChoice = "Rock";
                }
                else if (random == 2)
                {
                    botScore++;
                    botChoice = "Paper";
                }
                else if (random == 3)
                {
                    playerScore++;
                    botChoice = "Scissors";
                }
            }
            
            if (GUI::Button(220, 350, 170, 150, sf::Color(51, 51, 51), "Paper", sf::Color::White, true)) {
                random = randomNumber() + 1;

                if (random == 1) {
                    playerScore++;
                    botChoice = "Rock";
                }
                else if (random == 2) {
                    botScore++;
                    playerScore++;
                    botChoice = "Paper";
                }
                else if (random == 3) {
                    botScore++;
                    botChoice = "Scissors";
                }
            }

            if (GUI::Button(420, 350, 170, 150, sf::Color(51, 51, 51), "Scissors", sf::Color::White, true)) {
                random = randomNumber() + 1;

                if (random == 1) {
                    botScore++;
                    botChoice = "Rock";
                }
                else if (random == 2) {
                    playerScore++;
                    botChoice = "Paper";
                }
                else if (random == 3) {
                    botScore++;
                    playerScore++;
                    botChoice = "Scissors";
                }
            }

        }

        window.clear(sf::Color(31, 31, 31));
        GUI::Render();
        window.display();
    }
    return 0;
}