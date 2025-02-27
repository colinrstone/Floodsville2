
// Used to intialize and release all other manager                     //
// Contains the game loop as well as the Update and Render functions   //
// Used to make sure all functions are called in the correct order     //

#include "GameManager.h"
#include <time.h>


namespace QuickSDL {
	//Initializing to NULL
	GameManager* GameManager::sInstance = NULL;

	GameManager* GameManager::Instance() {

		//Create a new instance if no instance was created before
		if(sInstance == NULL)
			sInstance = new GameManager();

		return sInstance;
	}

	void GameManager::Release() {

		delete sInstance;
		sInstance = NULL;
	}

	GameManager::GameManager() {
		
		srand((Uint8)time(0));

		mQuit = false;

		//Initialize SDL
		mGraphics = Graphics::Instance();

		// Quits the game if SDL fails to initialize
		if(!Graphics::Initialized())
			mQuit = true;

		//Initialize AssetManager
		mAssetMgr = AssetManager::Instance();

		//Initialize InputManager
		mInputMgr = InputManager::Instance();

		//Initialize AudioManager
		mAudioMgr = AudioManager::Instance();

		//Initialize Timer
		mTimer = Timer::Instance();

		mStars = BackgroundStars::Instance();

		mScreenMgr = ScreenManager::Instance();
	}

	GameManager::~GameManager() {
		
		ScreenManager::Release();
		mScreenMgr = NULL;
		
		
		AudioManager::Release();
		mAudioMgr = NULL;

		AssetManager::Release();
		mAssetMgr = NULL;

		Graphics::Release();
		mGraphics = NULL;

		InputManager::Release();
		mInputMgr = NULL;

		Timer::Release();
		mTimer = NULL;

		BackgroundStars::Release();
		mStars = NULL;
		

	}

	void GameManager::EarlyUpdate() {

		//Updating the input state before any other updates are run to make sure the Input check is accurate
		mInputMgr->Update();
	}

	void GameManager::Update() {

		//int j = 0;
		//for (int i = 0; i < 100000000; i++)
		//{
		//	j++;
		//}

		//printf("DeltaTime: %f\n", mTimer->DeltaTime());

		//GameEntity Updates should happen here
		mScreenMgr->Update();
	}

	void GameManager::LateUpdate() {

		//Any collision detection should happen here

		mInputMgr->UpdatePrevInput();
		mTimer->Reset();
	}

	void GameManager::Render() {

		//Clears the last frame's render from the back buffer
		mGraphics->ClearBackBuffer();

		
		
		//All other rendering is to happen here
		mScreenMgr->Render();
		
		//Renders the current frame
		mGraphics->Render();
	}

	void GameManager::Run() {

		while(!mQuit) {

			mTimer->Update();

			while(SDL_PollEvent(&mEvents) != 0) {
				//Checks if the user quit the game
				if(mEvents.type == SDL_QUIT) {

					mQuit = true;
				}
			}

			//Limits the frame rate to FRAME_RATE
			if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {

				EarlyUpdate();
				Update();
				LateUpdate();
				Render();
			}
		}
	}
}
