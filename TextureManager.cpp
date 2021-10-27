#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

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

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = 0;
  srcRect.y = 0;
  desRect.x = x;
  desRect.y = y;

  desRect.w = srcRect.w = width;
  desRect.h = srcRect.h = height;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  desRect.x = x;
  desRect.y = y;

  desRect.w = srcRect.w = width;
  desRect.h = srcRect.h = height;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, flip);
}