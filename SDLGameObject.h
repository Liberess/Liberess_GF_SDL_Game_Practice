#ifndef __SDLGameObject_H__
#define __SDLGameObject_H__

#include "SDL.h"
#include "Game.h"
#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void Draw();
  virtual void Update() {}
  virtual void Clean() {}
  virtual ~SDLGameObject() {}

protected:
  int m_x, m_y;
  int m_width, m_height;
  std::string m_textureID;
  int m_currentRow, m_currentFrame;
};

#endif