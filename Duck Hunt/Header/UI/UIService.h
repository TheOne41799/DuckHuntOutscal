#pragma once


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController;
	}


	class UIService
	{
	private:
		MainMenu::MainMenuUIController* mainMenuUIController;

		void CreateUIControllers();
		void InitializeControllers();
		void Destroy();
	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();
	};
}
