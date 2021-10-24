#ifndef __Enemy_H__
#define __Enemy_H__

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams)
    : SDLGameObject(pParams) {}
  virtual void Draw();
  virtual void Update();
  virtual void Clean() {};
};

#endif