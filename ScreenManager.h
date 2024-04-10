#ifndef ScreenManager_h
#define ScreenManager_h
#include "StartScreen2.h"
#include "PlayScreen.h"


class ScreenManager {


	private:

		enum SCREENS { start, play };

		static ScreenManager* sInstance;

		InputManager* mInput;


		StartScreen* mStartScreen;
		PlayScreen* mPlayScreen;

		SCREENS mCurrentScreen;



	public:


		static ScreenManager* Instance();
		static void Release();

		void Update();
		void Render();


	private:

		ScreenManager();
		~ScreenManager();



};




#endif /* ScreenManager2_h */

