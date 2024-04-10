#ifndef Stage_h
#define Stage_h

#include "GameEntity2.h"
#include "AnimatedTexture.h"
#include "Platform.h"

using namespace QuickSDL;

class Player;

class Stage : public GameEntity {

private:


	//Timer* mTimer;
	//AudioManager* mAudio;

	int mStageNumber;

	Texture* mBackgroundImage;
	



private:



public:

	Stage(int stageNumber);
	~Stage();

	void LoadPlatforms(int stageNumber);
	bool IsPlayerOnPlatform(const Player& player);
	void UpdatePlayer(Player& player);

	void Update();
	void Render();


};


#endif /* Stage_h */
