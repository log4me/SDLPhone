#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <vector>
#include "WorldState.h"
using std::vector;
class StateMachine{
public:
    
    StateMachine() {}
    ~StateMachine() {}
    
    void update();
    void render();
    
    void pushState(WorldState* pState);
    void changeState(WorldState* pState);
    void popState();
    
    void clean();

    WorldState* getState(){return m_worldStates.back();}
	vector<WorldState*> getStates() { return m_worldStates; }
    
private:
    vector<WorldState*> m_worldStates;
};

#endif 
