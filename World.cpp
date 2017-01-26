#include"World.h"
#include "InputHandler.h"
#include "DialNum.h"
#include "Phone.h"
#include "Needle.h"
#include "SoundManager.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::cout;
World* World::s_pInstance = NULL;
bool World::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
	// attemp to initialize SDL
	m_bRunning = false;
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if(0 == SDL_Init(SDL_INIT_EVERYTHING)){
		cerr << "SDL init success" << endl;
		//init the window	
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(0 != m_pWindow){
			//window init success
			cerr << "window creation success" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if(0 != m_pRenderer){
				//renderer init success
				cerr << "renderer creation success" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}else{
				cerr << "renderer init fail" << endl;
				return false;
			}
		}else{
			cerr << "window init fail" << endl;
			return false;//window init fail
		}
	}else{
		cerr << "SDL init fail" << endl;
		return false;
	}
	if(!TextureManager::Instance()->load("assets/dial_num.png","dial_num", m_pRenderer)){
		return false;
	}
	num = "";
	if(!TextureManager::Instance()->load("assets/phone.png", "phone", m_pRenderer)){
		return false;
	}
	if(!TextureManager::Instance()->load("assets/needle.png", "needle", m_pRenderer)){
		return false;
	}
	int dial_num_x = 0;
	int dial_num_y = 0;
	int dial_num_width;
	int dial_num_height;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("dial_num"), NULL, NULL, &dial_num_width, &dial_num_height);
	int phone_x = 0;
	int phone_y = 0;
	int phone_width;
	int phone_height;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("phone"), NULL, NULL, &phone_width, &phone_height);
	int needle_x = 0;
	int needle_y = 0;
	int needle_width = 0;
	int needle_height = 0;
	SDL_QueryTexture(TextureManager::Instance()->getTexture("needle"), NULL, NULL, &needle_width, &needle_height);
	m_worldObjects.push_back(new Phone(new LoaderParams(phone_x, phone_y, phone_width, phone_height, "phone")));
	m_worldObjects.push_back(new DialNum(new LoaderParams(dial_num_x, dial_num_y, dial_num_width, dial_num_height, "dial_num")));
	m_worldObjects.push_back(new Needle(new LoaderParams(needle_x, needle_y, needle_width, needle_height, "needle")));
	m_pStateMachine = new StateMachine();
	m_pStateMachine->changeState(new WaitState());
	SoundManager::Instance()->load("assets/dialing.wav", "dialing", SOUND_SFX);
    SoundManager::Instance()->load("assets/rollback.wav", "rollback", SOUND_SFX);
	cerr << "init success" << endl;
	m_bRunning = true;//start the main loop
	return true;
}
void World::render(){
	SDL_RenderClear(m_pRenderer);//clear the renderer
	m_pStateMachine->render();
	SDL_RenderPresent(m_pRenderer);//draw to the screen
}
void World::clean(){
	cout << "cleaning World" << endl;
	int len = m_worldObjects.size();
	for(int i = 0; i < len ; i++){
		if(NULL != m_worldObjects[i]){
			delete m_worldObjects[i];
		}
	}
	m_worldObjects.clear();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void World::update(){
	m_pStateMachine->update();
}
void World::draw(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}
void World::handleEvents(){
	InputHandler::Instance()->update();
}
