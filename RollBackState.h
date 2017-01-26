//RollBackState.h
#ifndef ROLLBACKSTATE_H
#define ROLLBACKSTATE_H
#include "WorldState.h"
class RollBackState : public WorldState{
public:
	virtual ~RollBackState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{return s_rollBackID; }

private:
	bool m_loadingComplete;
	bool m_exiting;
	vector<string> m_textureIDList;
	vector<WorldObject*> m_worldObjects;
	static const string s_rollBackID;	
};
#endif