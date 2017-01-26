//DialNum.cpp
#include <cmath>
#include "DialNum.h"
#include <iostream>
#include "World.h"
#include "WorldState.h"
#include "DialingState.h"
#include "WaitState.h"
#include "RollBackState.h"
#include "ReceiveState.h"
#include <string>
#include "InputHandler.h"
#include "SoundManager.h"
using std::string;
using std::cout;
using std::endl;
const double DialNum::PI = 3.1415927;
const Vector2D DialNum::center = Vector2D(565, 344);
const int DialNum::num_radius = 12;
const Vector2D DialNum::num_pos[10]={
		Vector2D(579, 401),
		Vector2D(626, 348),
		Vector2D(620, 315),
		Vector2D(597, 291),
		Vector2D(565, 281),
		Vector2D(533, 291),
		Vector2D(511, 316),
		Vector2D(505, 349),
		Vector2D(519, 379),
		Vector2D(545, 399)
	};
const Vector2D DialNum::needle = Vector2D(617, 384);
string DialNum::nums = "";
DialNum::DialNum(const LoaderParams *params) : m_position(params->getX(), params->getY()){
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();
	m_pCenter = params->getCenter();
	m_pCenter = new SDL_Point();
	m_pCenter->x = center.getX();
	m_pCenter->y = center.getY();
	nums = "";
}
void DialNum::draw(){
	TextureManager::Instance()->draw(m_textureID, 
		(int)m_position.getX(), 
		(int)m_position.getY(),
		m_width, 
		m_height, 
		World::Instance()->getRenderer(),
		m_angle * 180 / PI,
		m_pCenter
		);
}
void DialNum::update(){
	string curStateName = World::Instance()->getStateMachine()->getState()->getStateID();
	if(curStateName == "WAIT"){
		updateFromWait();
	}else if(curStateName == "DIALING"){
		SoundManager::Instance()->playSound("dialing", 0);
		updateFromDialing();
	}else if(curStateName == "ROLLBACK"){
		SoundManager::Instance()->playSound("rollback", 0);
		updateFromRollBack();
	}else if(curStateName== "RECEIVE"){
		updateFromReceive();
	}
}
int DialNum::inNum(const Vector2D *mousePos){
	for(int i = 0; i < 10; i++){
		Vector2D diff = *mousePos - num_pos[i];
		if(diff.length() < num_radius){
			return i;
		}
	}
	return -1;
}
void DialNum::updateFromWait(){
	cur_num = inNum(InputHandler::Instance()->getMousePosition());
	if(InputHandler::Instance()->getMouseButtonState(LEFT) && cur_num != -1){
		World::Instance()->getStateMachine()->changeState(new DialingState());
	}
}

void DialNum::updateFromDialing(){
	if(!InputHandler::Instance()->getMouseButtonState(LEFT)){
		World::Instance()->getStateMachine()->changeState(new RollBackState());
	}
	Vector2D *mousePos = InputHandler::Instance()->getMousePosition();
	Vector2D mouseDir = *mousePos - center;
	mouseDir.normalize();
	double mouseAngle = atan2(mouseDir.getY(), mouseDir.getX());
	if(mouseAngle < 0){
		mouseAngle += 2 * PI;
	}

	Vector2D originNumDir = num_pos[cur_num] - center;
	originNumDir.normalize();
	double originNumAlgle = atan2(originNumDir.getY(), originNumDir.getX());
	if(originNumAlgle < 0){
		originNumAlgle += 2 * PI;
	}

	Vector2D endDir = needle - center;
	endDir.normalize();
	double endAngle = atan2(endDir.getY(), endDir.getX());
	if(endAngle < 0){
		endAngle += 2 * PI;
	}

	double moveAngle = 0.0;
	double diffAngle = 0.0;
	if(cur_num == 1){
		moveAngle = mouseAngle - originNumAlgle;
		diffAngle = endAngle - originNumAlgle;
	}else{
		diffAngle = endAngle + 2 * PI - originNumAlgle;
		if(mouseAngle < 1.30){
			moveAngle = 2 * PI - originNumAlgle + mouseAngle;
		}else{
			moveAngle = mouseAngle - originNumAlgle;
		}
	}
	if(m_angle < moveAngle){
		m_angle = moveAngle;
	}
	m_velocity = m_angle / 50;
	if(m_angle > diffAngle){
		m_angle = diffAngle;
		nums += string(1,char(cur_num+'0'));
		World::Instance()->getStateMachine()->changeState(new ReceiveState());
	}

}
void DialNum::updateFromRollBack(){
	m_angle -= m_velocity;
	if(m_angle < 1e-6){
		m_angle = 0;
		World::Instance()->getStateMachine()->changeState(new WaitState());
	}

}
void DialNum::updateFromReceive(){
	cout << "Dialing Number:" << nums <<endl;
	World::Instance()->getStateMachine()->changeState(new RollBackState());
}

void DialNum::setVelocity(const double velocity){
	m_velocity = velocity;
}

void DialNum::clean(){

}

DialNum::~DialNum(){
		
}