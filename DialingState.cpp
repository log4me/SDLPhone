//DialingState.cpp
#include "DialingState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string DialingState::s_dialingID = "DIALING";

DialingState::~DialingState(){}

void DialingState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void DialingState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool DialingState::onEnter(){
	vector<WorldObject*> objects = World::Instance()->getObjects();
	int len = objects.size();
	for(int i = 0; i < len ; i++){
		m_worldObjects.push_back(objects[i]);
	}
	m_loadingComplete = true;
	return true;
}

bool DialingState::onExit(){
	return true;
}