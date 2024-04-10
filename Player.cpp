#include "Player.h"

Player::Player() {

	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	mOnPlatform = true;
	mFalling = false;
	mVisible = true;
	mAnimating = false;

	mDamage = 0;
	mLives = 0;

	mModel = new Texture("copycat.png");
	mModel->Parent(this);
	mModel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));

	mFallSpeed = 200.0f;
	//mFallBounds = Vector2(700.0f, 0.0f);

	mMoveSpeed = 1000.0f;
	mMoveBounds = Vector2(700.0f, 0.0f);

}

Player::~Player() {

	mTimer = NULL;
	mInput = NULL;

	mOnPlatform = NULL;
	mFalling = NULL;
	mVisible = NULL;
	mAnimating = NULL;

	mDamage = NULL;
	mLives = NULL;

	mMoveSpeed = NULL;
	mMoveBounds = NULL;

	delete mModel;
	mModel = NULL;
}

void Player::HandleFalling () {


	Translate(-VEC2_UP * mFallSpeed * mTimer->DeltaTime());


	Vector2 pos = Pos(local);
	//if (pos.x < mMoveBounds.x)
	//	pos.x = mMoveBounds.x;
	//else if (pos.x > mMoveBounds.y)
	//	pos.x = mMoveBounds.y;

	Pos(pos);
}

void Player::HandleAerialMovement() {

	if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
		Translate(VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime());
	}
	else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
		Translate(-VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime());
	}

	Vector2 pos = Pos(local);
	//if (pos.x < mMoveBounds.x)
	//	pos.x = mMoveBounds.x;
	//else if (pos.x > mMoveBounds.y)
	//	pos.x = mMoveBounds.y;

	Pos(pos);
}

void Player::HandleGroundMovement() {

	if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
		Translate(VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime());
	}
	else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
		Translate(-VEC2_RIGHT * mMoveSpeed * mTimer->DeltaTime());
	}

	Vector2 pos = Pos(local);
	//if (pos.x < mMoveBounds.x)
	//	pos.x = mMoveBounds.x;
	//else if (pos.x > mMoveBounds.y)
	//	pos.x = mMoveBounds.y;

	Pos(pos);
}

void Player::HandleJump() {

	if (mInput->KeyPressed(SDL_SCANCODE_SPACE) && !mJumping) {
		mVerticalVelocity = -mJumpSpeed; // Initial jump velocity
		mJumping = true;
	}

	if (mJumping) {
		// Apply gravity
		mVerticalVelocity += mGravity * mTimer->DeltaTime();

		// Update position
		Translate(VEC2_UP * mVerticalVelocity * mTimer->DeltaTime());

		// Check for landing on platform
		//if (IsOnPlatform()) {
			//mJumping = false;
			// Set player's position to be on top of the platform
			// Adjust position and velocity as needed
		//}
	}


}

bool Player::IsFalling() {

	return mFalling;
}


void Player::Visible(bool visible) {

	mVisible = visible;

}

bool Player::IsAnimating() {

	return mAnimating;
}

int Player::Damage() {

	return mDamage;
}

int Player::Lives() {

	return mLives;
}

void Player::AddDamage(int change) {

	mDamage += change;
}

void Player::Update() {

	if (mOnPlatform) {
		HandleGroundMovement();
	}
	else {
		HandleFalling();
		HandleAerialMovement();
	}
	
	//HandleFalling();
	//HandleMovement();
	//HandleJump();





	//if (mAnimating) {
	
	//}
	//else {

	//	if (Active()) {

			//HandleMovement();

	//	}

	//}
}


void Player::Render() {

	mModel->Render();
	//if (mVisible) {

	//	if (mAnimating) {

	//	} else {

			//mShip->Render();

//		}
//	}
}
	