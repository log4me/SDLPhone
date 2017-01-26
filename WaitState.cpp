//WaitState.cpp
#include "WaitState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string WaitState::s_waitID = "WAIT";

WaitState::~WaitState(){}

void WaitState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void WaitState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool WaitState::onEnter(){
	vector<WorldObject*> objects = World::Instance()->getObjects();
	int len = objects.size();
	for(int i = 0; i < len ; i++){
		m_worldObjects.push_back(objects[i]);
	}
	m_loadingComplete = true;
	return true;
}

bool WaitState::onExit(){
	return true;
}