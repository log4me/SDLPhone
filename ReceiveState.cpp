//ReceiveState.cpp
#include "ReceiveState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string ReceiveState::s_receiveID = "RECEIVE";

ReceiveState::~ReceiveState(){}

void ReceiveState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void ReceiveState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool ReceiveState::onEnter(){
	vector<WorldObject*> objects = World::Instance()->getObjects();
	int len = objects.size();
	for(int i = 0; i < len ; i++){
		m_worldObjects.push_back(objects[i]);
	}
	m_loadingComplete = true;
	return true;
}

bool ReceiveState::onExit(){
	return true;
}