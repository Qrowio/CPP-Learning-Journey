#include "gui.hpp"

int main()
{
    sf::RenderWindow window;
    GUI::Init(&window, sf::VideoMode(600, 600), "Covid 19 Stats");
    std::string country = "United Kingdom";

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            GUI::PollEvent(event);

            GUI::TextBox(country, 50, 50, 300, 70, 24, sf::Color(51, 51, 51), sf::Color::White);

            if (GUI::Button(50, 250, 200, 70, sf::Color(51, 51, 51), "Discord", sf::Color::White, true)) {
                std::cout << "This will send to discord" << std::endl;
            }

            if (GUI::Button(350, 250, 200, 70, sf::Color(51, 51, 51), "Save", sf::Color::White, true)) {
                std::cout << "This will save to a file" << std::endl;
            }

        }

        window.clear(sf::Color(10, 10, 10));
        GUI::Render();
        window.display();
    }
    return 0;
}