#ifndef StartScreen2_h
#define StartScreen2_h
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "BackgroundStars.h"



 
using namespace QuickSDL;

class StartScreen : public GameEntity {


	private:
		Timer* mTimer;
		InputManager* mInput;


		//Top bar entities
		GameEntity* mTopBar;
		Texture* mPlayerOne;
		Texture* mHiScore;
		Texture* mPlayerTwo;

		// Logo entities
		Texture* mLogo;
		AnimatedTexture* mAnimatedLogo;


		//Play mode entities
		GameEntity* mPlayModes;
		Texture* mOnePlayerMode;
		Texture* mTwoPlayerMode;
		Texture* mCursor;
		Vector2 mCursorStartPos;
		Vector2 mCursorOffset;
		int mSelectedMode;

		//Bottom Bar entities
		GameEntity* mBotBar;
		Texture* mNamco;
		Texture* mDates;
		Texture* mRights;

		//Screen animation variables

		Vector2 mAnimationStartPos;
		Vector2 mAnimationEndPos;
		float mAnimationTotalTime;
		float mAnimationTimer;
		bool mAnimationDone;


		BackgroundStars* mStars;




	public:

		StartScreen();
		~StartScreen();


		void ResetAnimation();

		int SelectedMode();

		void ChangeSelectedMode(int change);

		void Update();

		void Render();

};





#endif /* StartScreen2_h */
