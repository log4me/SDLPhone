#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
using std::map;
using std::string;
class TextureManager{
public:
	bool load(const string fileName, string id, SDL_Renderer *pRenderer);
	bool loadMessage(string fontName, const string message, string id, int fontsize, SDL_Renderer *pRenderer);
	void draw(const string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(const string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* Instance(){
		if(NULL == s_pInstance){
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clearFromTextureMap(const string id){
     m_textureMap.erase(id);
  	}
  	SDL_Texture* getTexture(const string id){
  		return m_textureMap[id];
  	}
  	~TextureManager();
private:
	map<string, SDL_Texture*> m_textureMap;
	static TextureManager *s_pInstance;
	TextureManager(){
	}
	class CGarbo{
    public:
        ~CGarbo(){  
            if (NULL != TextureManager::s_pInstance)
                delete TextureManager::s_pInstance;
        }
    };
    static CGarbo Garbo;
};
#endif