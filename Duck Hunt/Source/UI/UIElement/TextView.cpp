#include "../../Header/UI/UIElement/TextView.h"
#include "../../Header/Global/Config.h"


namespace UI 
{
	namespace UIElement 
	{
		using namespace Global;

		sf::Font TextView::milkyVantage;


		void TextView::LoadFont()
		{
			milkyVantage.loadFromFile(Config::milkyVantageFontPath);
		}

		void TextView::SetFont(FontType fontType)
		{
			switch (fontType)
			{
			case UI::UIElement::FontType::MILKY_VANTAGE:
				text.setFont(milkyVantage);
				break;
			default:
				break;
			}
		}

		void TextView::SetFontSize(int fontSize)
		{
			text.setCharacterSize(fontSize);
		}

		void TextView::SetTextPosition(sf::Vector2f position)
		{
			text.setPosition(position);
		}

		void TextView::SetTextColor(sf::Color color)
		{
			text.setFillColor(color);
		}

		TextView::TextView()
		{

		}

		TextView::~TextView()
		{

		}

		void TextView::InitializeTextView()
		{
			LoadFont();
		}

		void TextView::Initialize(sf::String textValue, sf::Vector2f position, 
								  FontType fontType, int fontSize, sf::Color color)
		{
			UIView::Initialize();

			SetText(textValue);
			SetTextPosition(position);
			SetFont(fontType);
			SetFontSize(fontSize);
			SetTextColor(color);
		}

		void TextView::Update()
		{
			UIView::Update();
		}

		void TextView::Render()
		{
			UIView::Render();

			if (uiState == UIState::VISIBLE) 
			{
				gameWindow->draw(text);
			}
		}

		void TextView::SetText(sf::String textValue)
		{
			text.setString(textValue);
		}

		void TextView::SetTextCentreAligned()
		{
			float xPosition = (gameWindow->getSize().x - text.getLocalBounds().width) / 2;
			float yPosition = text.getGlobalBounds().getPosition().y;

			text.setPosition(sf::Vector2f(xPosition, yPosition));
		}
	}
}










