//DialingState.h
#ifndef DIALINGSTATE_H 
#define DIALINGSTATE_H 
#include "WorldState.h"
class DialingState : public WorldState{
public:
	virtual ~DialingState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_dialingID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_dialingID;	
};
#endif