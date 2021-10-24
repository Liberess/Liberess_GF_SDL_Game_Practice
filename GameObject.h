#ifndef __GameObject_H__
#define __GameObject_H__

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

class GameObject
{
public:
  void Load(int x, int y, int width, int height, std::string textureID);
  void Draw(SDL_Renderer* pRenderer);
  void Update();
  void Clean() {};

protected:
  int m_x, m_y;
  int m_width, m_height;
  std::string m_textureID;
  int m_currentRow, m_currentFrame;
};

#endif