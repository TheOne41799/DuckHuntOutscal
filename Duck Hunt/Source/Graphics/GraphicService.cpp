#include "../../Header/Graphics/GraphicService.h"


namespace Graphics
{
	GraphicService::GraphicService()
	{
		videoMode = nullptr;
		gameWindow = nullptr;
	}

	GraphicService::~GraphicService()
	{
		OnDestroy();
	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		gameWindow->setFramerateLimit(frameRate);
	}

	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMode();
		return new sf::RenderWindow(*videoMode, gameWindowTitle, sf::Style::Fullscreen);
	}

	void GraphicService::SetVideoMode()
	{
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
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

	sf::Color GraphicService::GetGameWindowColor()
	{
		return gameWindowColor;
	}

	void GraphicService::OnDestroy()
	{
		delete(videoMode);
		delete(gameWindow);
	}
}