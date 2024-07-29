#include "../../Header/UI/UIElement/AnimatedImageView.h"


namespace UI 
{
	namespace UIElement 
	{
		void AnimatedImageView::UpdateElapsedDuration()
		{
			float deltaTime = clock.restart().asSeconds();
			elapsedDuration += deltaTime;
		}

		void AnimatedImageView::HandleAnimationProgress()
		{
			if (elapsedDuration >= animationDuration && callbackFunction) {
				callbackFunction();
			}
		}

		void AnimatedImageView::UpdateAnimation()
		{
			switch (animationType)
			{
			case UI::UIElement::AnimationType::FADE_IN:
				FadeIn();
				break;
			case UI::UIElement::AnimationType::FADE_OUT:
				FadeOut();
				break;
			default:
				break;
			}
		}

		void AnimatedImageView::SetAnimationType(AnimationType animationType)
		{
			this->animationType = animationType;
		}

		void AnimatedImageView::SetAnimationDuration(float duration)
		{
			animationDuration = duration;
		}

		void AnimatedImageView::FadeIn()
		{
			float alpha = std::min(1.0f, elapsedDuration / animationDuration);
			sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}

		void AnimatedImageView::FadeOut()
		{
			float alpha = std::max(0.f, 1.f - (elapsedDuration / animationDuration));
			sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
		}

		void AnimatedImageView::Reset()
		{
			animationDuration = defaultAnimationDuration;
			animationType = AnimationType::FADE_IN;
			clock.restart();
			elapsedDuration = 0.0f;
		}

		AnimatedImageView::AnimatedImageView()
		{

		}

		AnimatedImageView::~AnimatedImageView()
		{

		}

		void AnimatedImageView::Initialize(sf::String texturePath, 
										   float imageWidth, float imageHeight, 
										   sf::Vector2f postion)
		{
			ImageView::Initialize(texturePath, imageWidth, imageHeight, postion);
		}

		void AnimatedImageView::Update()
		{
			ImageView::Update();

			if (uiState == UIState::VISIBLE) {
				UpdateElapsedDuration();
				HandleAnimationProgress();
				UpdateAnimation();
			}
		}

		void AnimatedImageView::Render()
		{
			ImageView::Render();
		}

		void AnimatedImageView::PlayAnimation(AnimationType animationType, 
											  float duration, 
											  CallbackFunction animationEndCallback)
		{
			ImageView::Show();
			Reset();
			SetAnimationType(animationType);
			SetAnimationDuration(duration);
			RegisterCallbackFunction(animationEndCallback);
		}

		void AnimatedImageView::RegisterCallbackFunction(CallbackFunction animationEndCallback)
		{
			callbackFunction = animationEndCallback;
		}
	}
}





