#ifndef DIALNUM_H
#define DIALNUM_H
#include "WorldObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
class DialNum: public WorldObject{
public:
	DialNum(const LoaderParams* params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~DialNum();
	void setVelocity(const double velocity);
private:
	int inNum(const Vector2D *mousePosition);
	void updateFromWait();
	void updateFromDialing();
	void updateFromRollBack();
	void updateFromReceive();
	Vector2D m_position;
	int m_width;
	int m_height;
	double m_angle;
	double m_velocity;
	static const Vector2D center;
	static const int num_radius;
	static const Vector2D num_pos[10];
	static const Vector2D needle;
	int cur_num;
	SDL_Point *m_pCenter;
	string m_textureID;
	static const double PI;
	static string nums;
};
#endif