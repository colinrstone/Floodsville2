#include "GameManager.h"

int main(int argc, char* argv[]) {

	//printf("test");


	//const char *_cdecl error = SDL_GetError();

	//printf("%s", error);


	QuickSDL::GameManager* game = QuickSDL::GameManager::Instance();

	game->Run();


	QuickSDL::GameManager::Release();
	game = NULL;

	return 0;
}