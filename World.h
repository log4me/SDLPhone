#ifndef WORLD_H
#define WORLD_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
#include "WorldObject.h"
#include "StateMachine.h"
#include "WaitState.h"
#include <vector>
using std::vector;
class World{
public:
	static World* Instance(){
		if(NULL == s_pInstance){
			s_pInstance = new World();
		}
		return s_pInstance;
	}
	virtual bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
	virtual void render();
	void update();
	void handleEvents();
	void clean();
	void draw();
	void quit(){
		m_bRunning = false;
	}
	bool running(){
		return m_bRunning;
	}
	SDL_Renderer* getRenderer()const{
		return m_pRenderer;
	}
	StateMachine* getStateMachine(){
		return m_pStateMachine;
	}
	vector<WorldObject*> getObjects(){
		return m_worldObjects;
	}
private:
	World(){
	}
	string num;
	static World *s_pInstance;
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	SDL_Texture *m_pTexture;
    StateMachine* m_pStateMachine;
	bool m_bRunning;
	int m_currentFrame;
	vector<WorldObject*> m_worldObjects;
	class CGarbo // 释放内存
    {
    public:
        ~CGarbo()
        {  
            if (NULL != World::s_pInstance)
                delete World::s_pInstance;
        }
    };
    static CGarbo Garbo;
};
#endif