#include"TextureManager.h"


TextureManager* TextureManager::s_pInstance = NULL;

bool TextureManager::load(const string filename, const string id, SDL_Renderer *pRenderer){
	SDL_Texture *pTexture = IMG_LoadTexture(pRenderer, filename.c_str());
	if(NULL != pTexture){
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
bool TextureManager::loadMessage(string fontName, const string message, string id, int fontsize, SDL_Renderer *pRenderer){
		TTF_Font *font = NULL;
		font = TTF_OpenFont(fontName.c_str(), fontsize);
		if(font == NULL){
			return false;
		}
		SDL_Color color = { 255, 255, 255 };
	    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    	SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surf);
	    SDL_FreeSurface(surf);
    	TTF_CloseFont(font);
    	m_textureMap[id] = texture;
		return true;
}
void TextureManager::draw(const string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, double angle, SDL_Point *center, SDL_RendererFlip flip){
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, center, flip);
}

void TextureManager::drawFrame(const string id, int x, int y, int width, int height, int currentRow, int currentFrame,SDL_Renderer *pRenderer,double angle, SDL_Point *center, SDL_RendererFlip flip){
	//First Row begin Zeroth Frame begin
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, center, flip);
}

TextureManager::~TextureManager(){
	int len = m_textureMap.size();
	m_textureMap.clear();
}