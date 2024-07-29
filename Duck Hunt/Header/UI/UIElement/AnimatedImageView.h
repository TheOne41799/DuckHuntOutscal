#pragma once
#include "ImageView.h"
#include <functional>


namespace UI 
{
	namespace UIElement 
	{
		enum class AnimationType 
		{
			FADE_IN,
			FADE_OUT
		};

		class AnimatedImageView : public ImageView 
		{
		private:
			using CallbackFunction = std::function<void()>;
			CallbackFunction callbackFunction = nullptr;

			void UpdateElapsedDuration();
			void HandleAnimationProgress();
			void UpdateAnimation();

		protected:
			float defaultAnimationDuration = 2.f;
			AnimationType animationType;

			float animationDuration;
			float elapsedDuration;

			sf::Clock clock;

			void SetAnimationType(AnimationType animationType);
			void SetAnimationDuration(float duration);

			void FadeIn();
			void FadeOut();

			virtual void Reset();

		public:
			AnimatedImageView();
			~AnimatedImageView();

			void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion) override;
			void Update() override;
			void Render() override;

			void PlayAnimation(AnimationType animationType, float duration, CallbackFunction animationEndCallback);
			void RegisterCallbackFunction(CallbackFunction animation_end_callback);
		};
	}
}
