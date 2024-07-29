#include "../../Header/Graphics/GraphicService.h"


namespace Graphic 
{
	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMode();
		return new sf::RenderWindow(*videoMode, "Dunk Hunt", sf::Style::Fullscreen);
	}

	void GraphicService::SetVideoMode()
	{
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::Destroy()
	{
		delete(gameWindow);
		delete(videoMode);
	}

	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMode = nullptr;
	}
	GraphicService::~GraphicService()
	{
		Destroy();
	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		gameWindow->setFramerateLimit(frameRate);
	}

	void GraphicService::Update()
	{

	}

	void GraphicService::Render()
	{

	}

	bool GraphicService::IsGameWindowOpen()
	{
		return gameWindow->isOpen();
	}

	sf::RenderWindow* GraphicService::GetGameWindow()
	{
		return gameWindow;
	}

	sf::Color GraphicService::GetWindowColor()
	{
		return windowColor;
	}
}






