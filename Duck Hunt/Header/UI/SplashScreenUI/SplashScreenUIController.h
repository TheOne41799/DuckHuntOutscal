#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/AnimatedImageView.h"


namespace UI 
{
	namespace SplashScreenUI 
	{

		class SplashScreenUIController : public Interface::IUIController 
		{
		private:
			const float logoAnimationDuration = 2.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 600.f;

			UIElement::ImageView* backgroundImage;
			UIElement::AnimatedImageView* outscaleLogoView;

			void InitializeBackgroundImage();

			void InitializeOutscalLogo();
			void FadeInAnimationCallback();
			void FadeOutAnimationCallback();
			sf::Vector2f GetLogoPosition();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;

			void Show() override;
		};

	}
}