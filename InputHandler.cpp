//InputHandler.cpp
#include "InputHandler.h"
#include "World.h"
#include <iostream>
using namespace std;
InputHandler* InputHandler::s_pInstance = NULL;
InputHandler::InputHandler(){
	for(int i = 0; i < 3; i++){
		m_mouseButtonStates.push_back(false);
	}
	m_keystates = NULL;
	m_mousePosition = new Vector2D(0,0);
}
void InputHandler::onMouseButtonDown(SDL_Event &e){
	if(SDL_BUTTON_LEFT == e.button.button){
		m_mouseButtonStates[LEFT] = true;

	}
	if(SDL_BUTTON_MIDDLE == e.button.button){
		m_mouseButtonStates[MIDDLE] = true;
	}
	if(SDL_BUTTON_RIGHT == e.button.button){
		m_mouseButtonStates[RIGHT] = true;
	}
}
void InputHandler::onMouseButtonUp(SDL_Event &e){
	if(SDL_BUTTON_LEFT == e.button.button){
		m_mouseButtonStates[LEFT] = false;
	}
	if(SDL_BUTTON_MIDDLE == e.button.button){
		m_mouseButtonStates[MIDDLE] = false;
	}
	if(SDL_BUTTON_RIGHT == e.button.button){
		m_mouseButtonStates[RIGHT] = false;
	}
}
void InputHandler::onMouseMove(SDL_Event &e){
	if(NULL != m_mousePosition){
		delete m_mousePosition;
	}
	m_mousePosition = new Vector2D(e.motion.x, e.motion.y);
}
bool InputHandler::isKeyDown(SDL_Scancode key){
	if(m_keystates != NULL){
		if(1 == m_keystates[key]){
			return true;
		}
	}
	return false;
}
void InputHandler::onKeyDown(){
	m_keystates = SDL_GetKeyboardState(NULL);
}
void InputHandler::onKeyUp(){
	m_keystates = SDL_GetKeyboardState(NULL);
}
void InputHandler::reset(){
	cout << "reset" << endl;
	m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}
void InputHandler::update(){
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		switch(e.type){
			case SDL_QUIT:
				World::Instance()->quit();
				break;
			case SDL_KEYDOWN:
				onKeyDown();
				break;
			case SDL_KEYUP:
				onKeyUp();
				break;
			case SDL_MOUSEMOTION:
				onMouseMove(e);
				break;
			case SDL_MOUSEBUTTONDOWN:
				onMouseButtonDown(e);
				break;
			case SDL_MOUSEBUTTONUP:
				onMouseButtonUp(e);
				break;
			default:
				break;
        }

    }
}