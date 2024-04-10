#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	
	//mTimer = Timer::Instance();
	//mInput = InputManager::Instance();
	//mAudio = AudioManager::Instance();

}

PlayScreen::~PlayScreen() {
	
	//mTimer = NULL;
	//mInput = NULL;
	

}

void PlayScreen::StartNewGame() {

	mPlayer = new Player();
	mStage = new Stage();

}




void PlayScreen::Update() {
	
	mPlayer->Update();
	mStage->Update();

}


void PlayScreen::Render() {

	mStage->Render();
	mPlayer->Render();


}
