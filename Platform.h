#ifndef Platform_H
#define Platform_H

#include "Texture.h" 
#include "GameEntity2.h"
#include "AnimatedTexture.h"

using namespace QuickSDL;

class Player;

class Platform : public GameEntity {
private:

    Texture* mPlatformTexture;
    SDL_Rect mRect;
    Platform* mPlatforms;

public:
    Platform(float x, float y, int width, int height);
    ~Platform();

    // Function to initialize platforms
    void initializePlatforms(int numPlatforms);

    // Function to access a specific platform
    Platform& getPlatform(int index);

    bool CollidesWith(const Player& player);
  
    SDL_Rect BoundingBox() const;

    void Render();

};

#endif // Platform_H
