#ifndef WORLDSTATE_H
#define WORLDSTATE_H
#include <string>
#include <vector>
#include "WorldObject.h"
using std::string;
using std::vector;
class WorldState{
public:
    virtual ~WorldState() {
    }
    
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    
    virtual void resume() {
    }
    
    virtual string getStateID() const = 0;
    
protected:
    
    WorldState() : m_loadingComplete(false), m_exiting(false){
    }
    
    bool m_loadingComplete;
    bool m_exiting;
    vector<string> m_textureIDList;
};

#endif
