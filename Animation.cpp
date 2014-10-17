#include "Animation.h"


Animation::Animation(int nframes,float frmHeight,float frmWidth,std::string path,SDL_Renderer* gRenderer){

	gSpriteSheetTexture.loadFromFile(path,gRenderer);
	frame=0;
	numframes = nframes;
	frameHeight = frmHeight;
	frameWidth = frmWidth;
	timer = 0;
	loadMedia();
}


bool Animation::loadMedia()
{
    //Loading success flag
    bool success = true;
	int x =0;
	int y=0;
    //Load sprite sheet texture
	for(int i = 0; i<numframes;i++){
		 //Set sprite clips
        gSpriteClips[ i ].x =   x;
        gSpriteClips[ i ].y =   y;
		gSpriteClips[ i ].w =  frameWidth;
		gSpriteClips[ i ].h = frameHeight;
		x+=frameWidth;
	}
	//int temp = gSpriteClips[ 1 ].x;

  
     /*   //Set sprite clips
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w =  64;
        gSpriteClips[ 0 ].h = 205;

        gSpriteClips[ 1 ].x =  64;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w =  64;
        gSpriteClips[ 1 ].h = 205;
        
        gSpriteClips[ 2 ].x = 128;
        gSpriteClips[ 2 ].y =   0;
        gSpriteClips[ 2 ].w =  64;
        gSpriteClips[ 2 ].h = 205;

        gSpriteClips[ 3 ].x = 196;
        gSpriteClips[ 3 ].y =   0;
        gSpriteClips[ 3 ].w =  64;
        gSpriteClips[ 3 ].h = 205;
       */
    return success;
}


void Animation::Draw(SDL_Renderer* gRenderer, SDL_RendererFlip flipType, float x,float y,int delay) {
	   SDL_Rect* currentClip = &gSpriteClips[ frame ];
				gSpriteSheetTexture.render( ( x - currentClip->w ) / 2, ( y - currentClip->h ) / 2, currentClip, NULL, NULL, flipType, gRenderer);

	timer++;

				    //Go to next frame
				if(timer>=delay){
					++frame;
					timer = 0;
				}

                //Cycle animation
				if( frame >= numframes )
                {
                    frame = 0;
                }
}