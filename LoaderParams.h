//LoaderParams.h
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include<string>
#include"SDL2/SDL.h"
using std::string;
class LoaderParams{
public:
	LoaderParams(int x, int y,int width, int height, const string textureID, double angle = 0.0, SDL_Point *pCenter = NULL){
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_angle = angle;
		m_textureID = textureID;
		m_pCenter = pCenter;
	}
	int getX()const{
		return m_y;
	}
	int getY()const{
		return m_y;
	}
	int getWidth()const{
		return m_width;
	}
	int getHeight()const{
		return m_height;
	}
	double getAngle()const{
		return m_angle;
	}
	SDL_Point* getCenter()const{
		return m_pCenter;
	}
	string getTextureID()const{
		return m_textureID;
	}
private:
	int m_x;
	int m_y;
	int m_height;
	int m_width;
	double m_angle;
	SDL_Point *m_pCenter;
	string m_textureID;
};
#endif