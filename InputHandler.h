//InputHandler.h
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include <vector>
using std::vector;

enum mouse_buttons{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
class InputHandler{
public:
	static InputHandler* Instance(){
		if(NULL == s_pInstance){
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();
	void onKeyDown();
	void onKeyUp();
	void reset();
	void onMouseMove(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);
	bool getMouseButtonState(int buttonNumber){
		if(buttonNumber >=0 && buttonNumber <3)
			return m_mouseButtonStates[buttonNumber];
		return false;
	}
	Vector2D* getMousePosition(){
		return m_mousePosition;
	}
	~InputHandler(){
		delete m_keystates;
  		delete m_mousePosition;
	    m_mouseButtonStates.clear();
	}
private:
	const Uint8* m_keystates;
    Vector2D *m_mousePosition;
	vector<bool> m_mouseButtonStates;
	static InputHandler* s_pInstance;
	InputHandler();
	class CGarbo {
    public:
        ~CGarbo(){  
            if (NULL != InputHandler::s_pInstance)
                delete InputHandler::s_pInstance;
        }
    };
    static CGarbo Garbo;
};
#endif