#ifndef Player_h
#define Player_h
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

#include <vector>
#include "Platform.h"




using namespace QuickSDL;

class Player : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	//AudioManager* mAudio;

	std::vector<Platform*> mPlatforms;
	
	bool mOnPlatform;
	bool mFalling;
	bool mVisible;
	bool mAnimating;
	
	int mDamage;
	int mLives;
	
	Texture* mModel;
	
	//AnimatedTexture* mDeathAnimation;

	float mFallSpeed;
	Vector2 mFallBounds;

	float mMoveSpeed;
	Vector2 mMoveBounds;

	bool mJumping;
	float mJumpSpeed;
	float mJumpHeight;
	float mGravity;
	float mVerticalVelocity;
	

	
	//static const int MAX_BULLETS = 2;
	//Bullet* mBullets[MAX_BULLETS];
	
private:
	
	void HandleFalling();
	void HandleAerialMovement();
	void HandleGroundMovement();
	void HandleJump();
	//void HandleFiring();
	
public:
	
	Player();
	
	~Player();

	bool IsFalling();
	void Visible(bool visible);
	bool IsAnimating();



	int Damage();
	int Lives();
	
	void AddDamage(int change);
	
	//void WasHit();
	
	void Update();
	void Render();
	
	
};






#endif /* Player_h */
