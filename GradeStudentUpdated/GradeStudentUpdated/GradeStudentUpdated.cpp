#include "gui.hpp"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

int main()
{
    sf::RenderWindow window;
    GUI::Init(&window, sf::VideoMode(600, 600), "Wassup");
    std::string username = "Michael";
    std::string password = "Password";
    std::string gradesText;
    std::ifstream getGrades("grades.txt");
    int spacing = 0;

    GUI::Text("Login", 50, 50, sf::Color::White, 36);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            GUI::PollEvent(event);

            GUI::TextBox(username, 50, 150, 200, 70, 24, sf::Color(51, 51, 51), sf::Color::White);
            GUI::TextBox(password, 50, 300, 200, 70, 24, sf::Color(51, 51, 51), sf::Color::White);

            if (GUI::Button(50, 450, 200, 80, sf::Color(51, 51, 51), "Submit", sf::Color::White, true))
            {
                sf::RenderWindow grades;
                GUI::ClearRenderables();
                GUI::Init(&grades, sf::VideoMode(600, 600), "Wassup");

                while (grades.isOpen()) {
                    sf::Event gradesEvent;

                    while (grades.pollEvent(gradesEvent))
                    {
                        if (gradesEvent.type == sf::Event::Closed)
                            grades.close();

                        GUI::TextPanel(50, 50, 200, 70, 36, sf::Color(51, 51, 51), username, sf::Color::White);
                        GUI::TextPanel(350, 50, 200, 70, 16, sf::Color(51, 51, 51), GUI::GetDateTime(), sf::Color::White);
                        
                        while (std::getline(getGrades, gradesText)) {
                            GUI::TextPanel(100, 200 + spacing, 400, 70, 36, sf::Color(51, 51, 51), gradesText, sf::Color::White);
                            spacing += 100;
                            std::cout << gradesText;
                        }
                    }
                    grades.clear(sf::Color(31, 31, 31));
                    GUI::Render();
                    grades.display();
                }
            }
        }

        window.clear(sf::Color(31, 31, 31));
        GUI::Render();
        window.display();
    }
    return 0;
}