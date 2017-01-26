#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H
#include <string>
using std::string;
#include"SDL2/SDL.h"
#include"TextureManager.h"
#include"LoaderParams.h"
class WorldObject{
public:
	//virtual void load(int x, int y, int width, int height, const string textureID, double angle = 0.0, SDL_Point *center = NULL);
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual ~WorldObject(){ 
	}
protected:
	WorldObject(const LoaderParams *pParams){
	}
	WorldObject(){}
};
#endif