#include "Stage.h"

Stage::Stage(int stageNumber) {

	mStageNumber = stageNumber;

	mBackgroundImage = new Texture("backgroundone.jpg", 0, 0, 360, 180);
	mBackgroundImage->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	mBackgroundImage->Scale(Vector2(3.0f, 3.0f));

}

Stage::~Stage() {



}

void Stage::LoadPlatforms(int stageNumber) {

	switch (stageNumber) {

	case 0:
		
	
		break;

	case 1:
		

		break;

	}


}

bool Stage::IsPlayerOnPlatform(const Player& player) {
	// Check if player is colliding with any platform
	// Return true if player is on a platform, false otherwise

}

void Stage::UpdatePlayer(Player& player) {
	if (IsPlayerOnPlatform(player)) {
		player.mOnPlatform = true;
	}
	else {
		player.mOnPlatform = false;
	}
}

void Stage::Update() {



}

void Stage::Render() {


	mBackgroundImage->Render();
	

}
