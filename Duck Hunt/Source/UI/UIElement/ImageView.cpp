#include "../../Header/UI/UIElement/ImageView.h"


namespace UI 
{
	namespace UIElement 
	{
		ImageView::ImageView()
		{

		}

		ImageView::~ImageView()
		{

		}

		void ImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion)
		{
			UIView::Initialize();
			
			if (SetTexture(texturePath)) 
			{
				SetScale(imageWidth, imageHeight);
				SetPosition(postion);
			}
		}

		void ImageView::Update()
		{
			UIView::Update();
		}

		void ImageView::Render()
		{
			UIView::Render();

			if (uiState == UIState::VISIBLE) 
			{
				gameWindow->draw(sprite);
			}
		}

		bool ImageView::SetTexture(sf::String texturePath)
		{
			if (texture.loadFromFile(texturePath)) 
			{
				sprite.setTexture(texture);
				return true;
			}
			else 
			{
				return false;
			}
		}

		void ImageView::SetTextureRect(sf::IntRect textureRect)
		{
			sprite.setTextureRect(textureRect);
		}

		void ImageView::SetScale(float xScale, float yScale)
		{
			sprite.setScale(
				xScale / sprite.getTexture()->getSize().x,
				yScale / sprite.getTexture()->getSize().y
			);
		}

		void ImageView::SetScale(float width, float height, float tileWidth, float tileHeight)
		{
			sprite.setScale(
				width / tileWidth,
				height / tileHeight
			);
		}

		void ImageView::SetPosition(sf::Vector2f position)
		{
			sprite.setPosition(position);
		}

		void ImageView::SetRotation(float angle)
		{
			sprite.setRotation(angle);
		}

		void ImageView::SetOriginAtCentre()
		{
			sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		}

		void ImageView::SetImageAlpha(float alpha)
		{
			sf::Color color = sprite.getColor();
			color.a = alpha;
			sprite.setColor(color);
		}

		void ImageView::SetCentreAlinged(bool y)
		{
			sprite.setPosition(
				(gameWindow->getSize().x / 2) - (sprite.getGlobalBounds().width / 2), y == true ? 
				(gameWindow->getSize().y / 2) - (sprite.getGlobalBounds().height / 2) 
				: sprite.getGlobalBounds().getPosition().y

			);
		}

		void ImageView::SetColor(sf::Color color)
		{
			sprite.setColor(color);
		}

		const sf::Sprite& ImageView::GetSprite()
		{
			return sprite;
		}
	}
}







