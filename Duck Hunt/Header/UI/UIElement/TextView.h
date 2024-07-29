#pragma once
#include "../../Header/UI/UIElement/UIView.h"


namespace UI 
{
	namespace UIElement 
	{
		enum class FontType
		{
			MILKY_VANTAGE
		};


		class TextView : public UIView
		{
		private:
			static const int defaultFontSize = 55;

			static sf::Font milkyVantage;

			sf::Text text;

			static void LoadFont();

			void SetFont(FontType fontType);
			void SetFontSize(int fontSize);
			void SetTextPosition(sf::Vector2f position);
			void SetTextColor(sf::Color color);

		public:
			TextView();
			virtual ~TextView();

			static void InitializeTextView();

			virtual void Initialize(sf::String textValue, sf::Vector2f position,
				FontType fontType = FontType::MILKY_VANTAGE, int fontSize = defaultFontSize,
				sf::Color color = sf::Color::White);

			virtual void Update() override;
			virtual void Render() override;

			void SetText(sf::String textValue);
			void SetTextCentreAligned();
		};
	}
}







