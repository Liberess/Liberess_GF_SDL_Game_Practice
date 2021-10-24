#ifndef __Player_H__
#define __Player_H__

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams)
    : SDLGameObject(pParams) {}
  virtual void Draw();
  virtual void Update();
  virtual void Clean() {};
};

#endif