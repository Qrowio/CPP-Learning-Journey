#include <iostream>
#include <SFML/Graphics.hpp>
#include "json.hpp"
#include "cpr/cpr.h"
#include <vector>

using namespace nlohmann;

void replace(std::string& str, const std::string& original, const std::string& changed) {
    size_t s = str.find(original);
    if (s == std::string::npos)
        return;
    str.replace(s, original.length(), changed);
}

sf::String wrapText(sf::String string, unsigned width, const sf::Font& font, unsigned charicterSize, bool bold = false) {
    unsigned currentOffset = 0;
    bool firstWord = true;
    std::size_t wordBegining = 0;

    for (std::size_t pos(0); pos < string.getSize(); ++pos) {
        auto currentChar = string[pos];
        if (currentChar == '\n') {
            currentOffset = 0;
            firstWord = true;
            continue;
        }
        else if (currentChar == ' ') {
            wordBegining = pos;
            firstWord = false;
        }

        auto glyph = font.getGlyph(currentChar, charicterSize, bold);
        currentOffset += glyph.advance;

        if (!firstWord && currentOffset > width) {
            pos = wordBegining;
            string[pos] = '\n';
            firstWord = true;
            currentOffset = 0;
        }
    }

    return string;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Grab anime info.");
    sf::RectangleShape button(sf::Vector2f(200, 60));
    sf::RectangleShape inputBox(sf::Vector2f(500, 50));
    sf::Texture texture;
    sf::Sprite ImageSprite;
    sf::RectangleShape textBox;
    sf::RectangleShape startDate;
    sf::String playerInput;
    sf::Text playerText;
    sf::Text text;
    sf::Font font;
    sf::Text titleGenerated;
    sf::Text startdateGenerated;
    sf::RectangleShape endDate;
    sf::Text endGenerated;
    sf::RectangleShape desc;
    sf::Text descGenerated;

    button.setFillColor(sf::Color(51, 51, 51));
    button.setOutlineColor(sf::Color(96, 96, 96));
    button.setOutlineThickness(3);
    button.setPosition(200, 500);

    font.loadFromFile("arial.ttf");

    text.setFont(font);
    text.setString("Generate");
    text.setPosition(230, 508);
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(32);

    inputBox.setFillColor(sf::Color(51, 51, 51));
    inputBox.setPosition(50, 50);
    inputBox.setOutlineColor(sf::Color(96, 96, 96));
    inputBox.setOutlineThickness(3);

    playerText.setFont(font);
    playerText.setFillColor(sf::Color::White);
    playerText.setPosition(60, 55);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && button.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                std::string anime = playerInput.toAnsiString();
                replace(anime, " ", "%20");
                std::string getAPI = cpr::Get(cpr::Url("https://kitsu.io/api/edge/anime?filter[text]=" + anime)).text;
                auto parsegetAPI = json::parse(getAPI);

                auto animeTitle = parsegetAPI["data"][0]["attributes"]["titles"]["en_jp"];
                auto animeStartDate = parsegetAPI["data"][0]["attributes"]["startDate"];
                auto animeEndDate = parsegetAPI["data"][0]["attributes"]["endDate"];
                auto animeSynopsis = parsegetAPI["data"][0]["attributes"]["description"];
                auto animeEpisodes = parsegetAPI["data"][0]["attributes"]["episodeCount"];
                std::string animeCover = parsegetAPI["data"][0]["attributes"]["coverImage"]["original"];
                replace(animeCover, "\"", "");
                std::cout << animeTitle << std::endl;;
                std::cout << animeStartDate << std::endl;
                std::cout << animeEndDate << std::endl;
                std::cout << animeSynopsis << std::endl;
                std::cout << animeEpisodes << std::endl;
                std::cout << animeCover << std::endl;
                std::string ImageBuffer = cpr::Get(cpr::Url(animeCover)).text;
                sf::Image CoverImage;
                std::cout << ImageBuffer.size() << std::endl;
                CoverImage.loadFromMemory(ImageBuffer.c_str(), ImageBuffer.size());
                texture.loadFromImage(CoverImage);

                ImageSprite.setTexture(texture);
                ImageSprite.setPosition(50, 130);
                ImageSprite.setScale(0.18, 0.23);

                textBox.setSize(sf::Vector2f(220, 50));
                textBox.setPosition(330, 130);
                textBox.setFillColor(sf::Color(51, 51, 51));
                textBox.setOutlineColor(sf::Color(96, 96, 96));
                textBox.setOutlineThickness(3);
                titleGenerated.setFont(font);
                titleGenerated.setString(animeTitle);
                titleGenerated.setPosition(340, 140);
                titleGenerated.setCharacterSize(22);
                titleGenerated.setFillColor(sf::Color::White);
                titleGenerated.setStyle(sf::Text::Bold);

                startDate.setSize(sf::Vector2f(220, 50));
                startDate.setPosition(330, 200);
                startDate.setFillColor(sf::Color(51,51,51));
                startDate.setOutlineColor(sf::Color(96, 96, 96));
                startDate.setOutlineThickness(3);
                startdateGenerated.setFont(font);
                startdateGenerated.setString(animeStartDate);
                startdateGenerated.setPosition(340, 210);
                startdateGenerated.setCharacterSize(22);
                startdateGenerated.setFillColor(sf::Color::White);
                startdateGenerated.setStyle(sf::Text::Bold);

                endDate.setSize(sf::Vector2f(220, 50));
                endDate.setPosition(330, 270);
                endDate.setFillColor(sf::Color(51, 51, 51));
                endDate.setOutlineColor(sf::Color(96, 96, 96));
                endDate.setOutlineThickness(3);
                endGenerated.setFont(font);
                endGenerated.setString(animeStartDate);
                endGenerated.setPosition(340, 280);
                endGenerated.setCharacterSize(22);
                endGenerated.setFillColor(sf::Color::White);
                endGenerated.setStyle(sf::Text::Bold);

                desc.setSize(sf::Vector2f(500, 150));
                desc.setPosition(50, 330);
                desc.setFillColor(sf::Color(51, 51, 51));
                desc.setOutlineColor(sf::Color(96, 96, 96));
                desc.setOutlineThickness(3);
                descGenerated.setFont(font);
                animeSynopsis = wrapText(animeSynopsis, 490, font, 14, true);
                descGenerated.setString(animeSynopsis);
                descGenerated.setPosition(55, 335);
                descGenerated.setCharacterSize(14);
                descGenerated.setFillColor(sf::Color::White);
                descGenerated.setStyle(sf::Text::Bold);

                Sleep(1000);
                playerInput = "";
                playerText.setString("");
            }

                if (event.type == sf::Event::TextEntered)
                {
                    playerInput += event.text.unicode;
                    playerText.setString(playerInput);
                }
        }

        window.clear(sf::Color(31, 31, 31));
        window.draw(button);
        window.draw(inputBox);
        window.draw(ImageSprite);
        window.draw(text);
        window.draw(textBox);
        window.draw(playerText);
        window.draw(startDate);
        window.draw(startdateGenerated);
        window.draw(titleGenerated);
        window.draw(endDate);
        window.draw(endGenerated);
        window.draw(desc);
        window.draw(descGenerated);
        window.display();
    }
    return 0;
}