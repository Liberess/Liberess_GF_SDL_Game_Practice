#ifndef __GameObject_H__
#define __GameObject_H__

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

class GameObject
{
public:
  virtual void Load(int x, int y, int width, int height, std::string textureID);
  virtual void Draw(SDL_Renderer* pRenderer);
  virtual void Update();
  virtual void Clean() {};

protected:
  int m_x, m_y;
  int m_width, m_height;
  std::string m_textureID;
  int m_currentRow, m_currentFrame;
};

#endif