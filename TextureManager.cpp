#include "TextureManager.h"

bool TextureManager::Load(std::string path, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(path.c_str());

  if(pTempSurface == 0)
    return false;

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  if(pTexture != 0)
  {
    m_textureMap[id] = pTexture;
    return true;
  }

  return false;
}

void TextureManager::Draw(std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = 0;
  srcRect.y = 0;
  desRect.x = x;
  desRect.y = y;
  desRect.w = srcRect.w = w;
  desRect.h = srcRect.h = h;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = w * frame;
  srcRect.y = h * row;
  desRect.x = x;
  desRect.y = y;
  desRect.w = srcRect.w = w;
  desRect.h = srcRect.h = h;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, flip);
}