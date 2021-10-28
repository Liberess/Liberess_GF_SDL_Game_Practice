#ifndef __TextureManager_H__
#define __TextureManager_H__

#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <iostream>

class TextureManager
{
public:
  static TextureManager* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new TextureManager();

    return s_pInstance;
  }
  bool Load(std::string path, std::string id, SDL_Renderer* pRenderer);
  void Draw(std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void DrawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
  TextureManager() {}
  ~TextureManager() {}
  static TextureManager* s_pInstance;
  std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif