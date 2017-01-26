//ReceiveState.h
#ifndef RECEIVESTATE_H 
#define RECEIVESTATE_H 
#include "WorldState.h"
class ReceiveState : public WorldState{
public:
	virtual ~ReceiveState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_receiveID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_receiveID;	
};
#endif