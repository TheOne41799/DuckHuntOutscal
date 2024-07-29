#pragma once
#include "../UI/UIElement/ImageView.h"
#include "DuckAnimationConfig.h"


namespace Duck 
{
	class DuckController;


	class DuckView 
	{
	private:
		const float duckWidth = 100.f;
		const float duckHeight = 100.f;

		int currentFrame = 0;
		float elapsedTime;

		UI::UIElement::ImageView* duckImage;
		int flip = 1;

		DuckController* duckController;
		bool deadAniamtionFinished = false;

		void CreateUIElemetns();
		void InitializeImage();
		sf::String GetDuckTexturePath();
		void Destroy();

	public:
		DuckView();
		~DuckView();

		void Initialize(DuckController* controller);
		void Update();
		void Render();

		void UpdateAnimation(DuckAnimationConfig animationConfig);
		void ShowDeadAnimation(DuckAnimationConfig animationConfig);

		const sf::Sprite& GetDuckSprite();

		void SetRotation(float angle);
		void SetScale(int flip);
	};
}





