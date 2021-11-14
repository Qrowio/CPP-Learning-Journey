#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <windows.h>
#include <cpr/cpr.h>


class GUI
{
public:
	static void Init(sf::RenderWindow* Window, sf::VideoMode VideoMode, std::string Title)
	{
		Window->create(VideoMode, Title);
		m_Window = Window;
		m_Font = new sf::Font;
		m_Font->loadFromFile("C:\\windows\\fonts\\arial.ttf");
	}
	static void Init(sf::RenderWindow* Window, sf::VideoMode VideoMode, std::string Title, std::string Font)
	{
		Window->create(VideoMode, Title);
		m_Window = Window;
		m_Font = new sf::Font;
		m_Font->loadFromFile(Font);
	}
	static void Render()
	{
		static bool Init = false;
		if (!Init)
		{
			INPUT ip;
			ip.type = INPUT_KEYBOARD;
			ip.ki.wVk = 'a';
			ip.ki.wScan = 0;
			ip.ki.dwFlags = 0;
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.wVk = '\b';
			ip.ki.wScan = 0;
			ip.ki.dwFlags = 0;
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;
			SendInput(1, &ip, sizeof(INPUT));
			Init = true;
		}
		for (unsigned int i = 0; i < m_Renderables.size(); i++)
		{
			m_Window->draw(m_Renderables[i]);
		}
	}
	static void Panel(float xPosition, float yPosition, float pWidth, float pHeight, sf::Color pColor)
	{
		static bool Init = false;
		if (!Init)
		{
			sf::RectangleShape* Panel = new sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
			Panel->setFillColor(pColor);
			Panel->setPosition(xPosition, yPosition);
			m_Renderables.push_back(*Panel);
		}
	}
	static void TextPanel(float xPosition, float yPosition, float pWidth, float pHeight, unsigned int pCharacterSize, sf::Color pColor, std::string pText, sf::Color pTextColor)
	{
		static bool Init = false;
		if (!Init)
		{
			sf::RectangleShape* Panel = new sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
			Panel->setFillColor(pColor);
			Panel->setPosition(xPosition, yPosition);
			m_Renderables.push_back(*Panel);
			sf::Text* ButtonText = new sf::Text;
			ButtonText->setFont(*m_Font);
			ButtonText->setString(pText);
			ButtonText->setCharacterSize(pCharacterSize);
			ButtonText->setFillColor(pTextColor);
			ButtonText->setStyle(sf::Text::Bold);

			sf::FloatRect rectBounds = Panel->getGlobalBounds();
			sf::FloatRect textBounds = ButtonText->getGlobalBounds();

			ButtonText->setPosition(
				rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
				rectBounds.top + (rectBounds.height / 2) - textBounds.height
			);
			m_Renderables.push_back(*ButtonText);
		}
	}
	static void Text(std::string tText, float xPosition, float yPosition, sf::Color pColor, float pCharacterSize)
	{
		sf::Text* Text = new sf::Text;
		Text->setFont(*m_Font);
		Text->setFillColor(pColor);
		Text->setCharacterSize(pCharacterSize);
		Text->setPosition(xPosition, yPosition);
		Text->setString(tText);
		m_Renderables.push_back(*Text);
	}
	static void Panel(float xPosition, float yPosition, float pWidth, float pHeight, sf::Color pColor, float pOutlineThickness, sf::Color pOutlineColor)
	{
		static bool Init = false;
		if (!Init)
		{
			sf::RectangleShape* Panel = new sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
			Panel->setFillColor(pColor);
			Panel->setPosition(xPosition, yPosition);
			Panel->setOutlineColor(pOutlineColor);
			Panel->setOutlineThickness(pOutlineThickness);
			m_Renderables.push_back(*Panel);
		}
	}
	static void PollEvent(sf::Event& pEvent)
	{
		m_Event = &pEvent;
	}
	static void TextBox(std::string& tString, float xPosition, float yPosition, float tWidth, float tHeight, unsigned int tCharacterSize, sf::Color tColor, sf::Color tTextColor)
	{
		sf::Text* TextBoxText = new sf::Text;
		sf::RectangleShape* TextBox = new sf::RectangleShape(sf::Vector2f(tWidth, tHeight));
		TextBox->setPosition(xPosition, yPosition);
		TextBox->setFillColor(tColor);

		TextBoxText->setFont(*m_Font);
		TextBoxText->setCharacterSize(tCharacterSize);
		TextBoxText->setPosition(TextBox->getGlobalBounds().left + 10, TextBox->getGlobalBounds().top + 20);
		m_Renderables.push_back(*TextBox);

		TextBoxText->setString(tString + "_");

		if (m_Event->type == sf::Event::TextEntered)
		{
			if (m_Event->text.unicode < 128)
			{
				if (m_Event->text.unicode != 8)
				{
					tString += m_Event->text.unicode;
				}
				else
				{
					if (!tString.empty()) {
						tString.erase(std::prev(tString.end()));
					}
				}
			}
		}

		m_Renderables.push_back(*TextBoxText);
	}
	static void ClearRenderables()
	{
		m_Renderables.clear();
	}
	static bool Button(float xPosition, float yPosition, float bWidth, float bHeight, sf::Color bColor, std::string bText, sf::Color bTextColor, bool bBold = false)
	{
		sf::RectangleShape* Button = new sf::RectangleShape(sf::Vector2f(bWidth, bHeight));

		Button->setFillColor(bColor);
		Button->setPosition(xPosition, yPosition);
		sf::Text* ButtonText = new sf::Text;
		ButtonText->setFont(*m_Font);
		ButtonText->setString(bText);
		ButtonText->setCharacterSize(36);
		ButtonText->setFillColor(bTextColor);
		if (bBold)
		{
			ButtonText->setStyle(sf::Text::Bold);
		}
		sf::FloatRect rectBounds = Button->getGlobalBounds();
		sf::FloatRect textBounds = ButtonText->getGlobalBounds();

		ButtonText->setPosition(
			rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
			rectBounds.top + (rectBounds.height / 2) - textBounds.height
		);


		m_Renderables.push_back(*Button);
		m_Renderables.push_back(*ButtonText);

		if (Button->getGlobalBounds().contains(m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_Window))))
		{
			Button->setFillColor(sf::Color(Button->getFillColor().r + 10, Button->getFillColor().g + 10, Button->getFillColor().b + 10));
			if (m_Event->type == sf::Event::MouseButtonReleased && m_Event->mouseButton.button == sf::Mouse::Left)
			{
				return true;
			}
		}
		else
		{
			Button->setFillColor(bColor);
		}

		return false;
	}
private:
	inline static sf::Font* m_Font = new sf::Font;
	inline static sf::RenderWindow* m_Window = new sf::RenderWindow;
	inline static sf::Event* m_Event = new sf::Event;
	inline static std::vector <std::reference_wrapper< sf::Drawable> > m_Renderables;
};