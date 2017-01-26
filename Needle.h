//NeedleObject.h
#ifndef NEEDLE_H
#define NEEDLE_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class Needle : public WorldObject{
public:
	Needle(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Needle();
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif