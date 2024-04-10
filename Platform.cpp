#include "Platform.h"

Platform::Platform(float x, float y, int width, int height) {

    mPlatformTexture = new Texture("platform.png"); 
    mRect.x = x;
    mRect.y = y;
    mRect.w = width;
    mRect.h = height;
}

Platform::~Platform() {
    delete mPlatformTexture;
    
}

SDL_Rect Platform::BoundingBox() const {
    return mRect;
}

void Platform::initializePlatforms(int numPlatforms) {
    // Allocate memory for platforms
    // Assuming platforms is a dynamic array of Platform objects
    platforms = new Platform[numPlatforms];
}

Platform& Platform::getPlatform(int index) {
    // Return reference to platform at given index
    return platforms[index];
}

bool Platform::CollidesWith(const Player& player) {
    // Implement collision detection logic
    // Return true if player is colliding with this platform, false otherwise
}

void Platform::Render() {

   //mPlatformTexture->Render(mRect.x, mRect.y);

}

