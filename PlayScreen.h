#ifndef PlayScreen_h
#define PlayScreen_h

#include "GameEntity2.h"
#include "InputManager.h"
#include "AnimatedTexture.h"

#include "Player.h"
#include "Stage.h"


using namespace QuickSDL;

class PlayScreen : public GameEntity {
	
private:
	
	Timer* mTimer;
	InputManager* mInput;
	//AudioManager* mAudio;

	Stage* mStage;
	Player* mPlayer;
	
private:
	
	
public:
	
	PlayScreen();
	~PlayScreen();
	
	void StartNewGame();

	void Update();
	void Render();
	
	
};


#endif /* PlayScreen_h */
