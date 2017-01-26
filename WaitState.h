//WaitState.h
#ifndef WAITSTATE_H
#define WAITSTATE_H
#include "WorldState.h"
class WaitState : public WorldState{
public:
	virtual ~WaitState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_waitID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_waitID;	
};
#endif