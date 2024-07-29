#pragma once
#include "../../Header/UI/UIElement/UIView.h"


namespace UI 
{
	namespace UIElement 
	{
		class ImageView : public UIView 
		{
		protected:
			sf::Texture texture;
			sf::Sprite sprite;

		public:
			ImageView();
			virtual ~ImageView() override;

			virtual void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion);
			virtual void Update() override;
			virtual void Render() override;

			virtual bool SetTexture(sf::String texturePath);
			virtual void SetTextureRect(sf::IntRect textureRect);

			virtual void SetScale(float xScale, float yScale);
			virtual void SetScale(float width, float height, float tileWidth, float tileHeight);

			virtual void SetPosition(sf::Vector2f position);

			virtual void SetRotation(float angle);

			virtual void SetOriginAtCentre();

			virtual void SetImageAlpha(float alpha);

			virtual void SetCentreAlinged(bool y);

			virtual void SetColor(sf::Color color);

			const virtual sf::Sprite& GetSprite();
		};
	}
}
