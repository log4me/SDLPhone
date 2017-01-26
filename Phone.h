#ifndef PHONE_H
#define PHONE_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class Phone : public WorldObject{
public:
	Phone(const LoaderParams *params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~Phone();
private:
	Vector2D m_position;
	int m_width;
	int m_height;
	string m_textureID;
};
#endif