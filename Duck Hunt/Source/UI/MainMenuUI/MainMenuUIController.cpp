#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../../Header/UI/UIElement/ButtonView.h"
#include "../../../Header/UI/UIElement/ImageView.h"
#include "../../../Header/UI/UIElement/TextView.h"


namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;
        using namespace Sound;
        using namespace UIElement;


        MainMenuUIController::MainMenuUIController() {
            CreateImage();
            CreateButton();
            CreateText();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            Destroy();
        }

        void MainMenuUIController::Initialize()
        {
            InitializeBackgroundImage();
            InitializeButtons();
            InitializeText();
            RegisterButtonCallback();
        }

        void MainMenuUIController::Update()
        {
            backgroundImage->Update();
            playButton->Update();
            quitButton->Update();
            duckHuntTextView->Update();
        }

        void MainMenuUIController::Render()
        {
            backgroundImage->Render();
            playButton->Render();
            quitButton->Render();
            duckHuntTextView->Render();
        }

        void MainMenuUIController::Show()
        {
            backgroundImage->Show();
            playButton->Show();
            quitButton->Show();
            duckHuntTextView->Show();

            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void MainMenuUIController::CreateImage()
        {
            backgroundImage = new ImageView();
        }

        void MainMenuUIController::CreateButton()
        {
            playButton = new ButtonView();
            quitButton = new ButtonView();
        }

        void MainMenuUIController::CreateText()
        {
            duckHuntTextView = new TextView();
        }

        void MainMenuUIController::InitializeBackgroundImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            backgroundImage->Initialize(Config::mainMenuBackgroundTexturePath, 
                                        gameWindow->getSize().x, gameWindow->getSize().y, 
                                        sf::Vector2f(0.f, 0.f));
            backgroundImage->SetColor(sf::Color(255, 230, 255));
        }

        void MainMenuUIController::InitializeButtons()
        {
            playButton->Initialize("Play Button", Config::playButtonTexturePath, 
                                    buttonWidth, buttonHeight, 
                                    sf::Vector2f(0, playButtonYPosition));
            quitButton->Initialize("Quit Button", Config::quitButtonTexturePath, 
                                    buttonWidth, buttonHeight, 
                                    sf::Vector2f(0, quitButtonYPosition));

            playButton->SetCentreAlinged(false);
            quitButton->SetCentreAlinged(false);
        }

        void MainMenuUIController::InitializeText()
        {
            duckHuntTextView->Initialize("Duck Hunt", duckHuntTextPosition,
                UIElement::FontType::MILKY_VANTAGE, fontSize);
        }

        void MainMenuUIController::RegisterButtonCallback()
        {
            playButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));
            quitButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
        }

        void MainMenuUIController::PlayButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::QuitButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
        }

        void MainMenuUIController::Destroy()
        {
            delete(playButton);
            delete(quitButton);
            delete(backgroundImage);
            delete(duckHuntTextView);
        }
    }
}










