//RollbackState.cpp
#include "RollBackState.h"
#include "World.h"
#include "InputHandler.h"
#include "iostream"

const string RollBackState::s_rollBackID = "ROLLBACK";

RollBackState::~RollBackState(){}

void RollBackState::update(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->update();
	}
}

void RollBackState::render(){
	int len = m_worldObjects.size();
	for(int i = 0; i < len; i++){
		m_worldObjects[i]->draw();
	}
}

bool RollBackState::onEnter(){
	vector<WorldObject*> objects = World::Instance()->getObjects();
	int len = objects.size();
	for(int i = 0; i < len ; i++){
		m_worldObjects.push_back(objects[i]);
	}
	m_loadingComplete = true;
	return true;
}

bool RollBackState::onExit(){
	return true;
}