//Phone.cpp
#include "Phone.h"

#include "World.h"

Phone::Phone(const LoaderParams *params):m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
}
void Phone::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer());
}
void Phone::update(){

}

void Phone::clean(){

}

Phone::~Phone(){
		
}