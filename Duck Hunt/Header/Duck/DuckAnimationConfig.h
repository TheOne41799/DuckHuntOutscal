#pragma once


namespace Duck 
{
	struct DuckAnimationConfig 
	{
		float tileStart;
		float tileWidth;
		float tileHeight;
		int numberOfAnimationFrame;
		float frameDuration;


		DuckAnimationConfig(float tileStart, float tileWidth, float tileHeight, 
							int numberOfAnimationFrame, float frameDuration)
							: tileWidth(tileWidth), tileHeight(tileHeight), tileStart(tileStart), 
							  numberOfAnimationFrame(numberOfAnimationFrame), frameDuration(frameDuration)
		{}
	};
}









