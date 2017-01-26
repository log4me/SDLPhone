#include "StateMachine.h"

void StateMachine::clean(){
    if(!m_worldStates.empty()){
        m_worldStates.back()->onExit();

        delete m_worldStates.back();
        
        m_worldStates.clear();
    }
}

void StateMachine::update(){
    if(!m_worldStates.empty()){
        m_worldStates.back()->update();
	}
}

void StateMachine::render(){
    if(!m_worldStates.empty()){
        m_worldStates.back()->render();
    }
}

void StateMachine::pushState(WorldState *pState){
    m_worldStates.push_back(pState);
    m_worldStates.back()->onEnter();
}

void StateMachine::popState(){
    if(!m_worldStates.empty()){
        m_worldStates.back()->onExit();
        m_worldStates.pop_back();
    }
    
    m_worldStates.back()->resume();
}

void StateMachine::changeState(WorldState *pState){
    if(!m_worldStates.empty()){
        if(m_worldStates.back()->getStateID() == pState->getStateID()){
            return; // do nothing
        }

		m_worldStates.back()->onExit();
		m_worldStates.pop_back();
    }

	// initialise it
    pState->onEnter();
    
    // push back our new state
    m_worldStates.push_back(pState);
}