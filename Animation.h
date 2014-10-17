#ifndef ANIMATION_H
#define ANIMATION_H

#include "LTexture.h"
#include "Box2D.h"


class Animation {
public:
	Animation(int,float,float,std::string,SDL_Renderer*);
	bool loadMedia( );
	void Draw(SDL_Renderer*, SDL_RendererFlip, float, float,int);
private:
	//Walking animation
	SDL_Rect gSpriteClips[32];
	LTexture gSpriteSheetTexture;
	int frame;
	int numframes;
	float frameHeight;
	float frameWidth;
	int timer;
};

#endif