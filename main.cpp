#include"World.h"
#include<iostream>
using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0 / FPS;
int main(int argc, char *argv[]){
	Uint32 frameStart, frameTime;
	cout << "World init attempt..." << endl;
	World *world = World::Instance();
	if(false == world->init("dialphone", 100, 100, 1132, 706, false)){
		cerr << SDL_GetError() << endl;
	}
	cout << "World init success!" << endl;

	while(world->running()){

		frameStart = SDL_GetTicks();
		world->handleEvents();
		world->update();
		world->render();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < DELAY_TIME){
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	world->clean();
	
	return 0;
}
