#ifndef __Enemy_H__
#define __Enemy_H__

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);
  void Draw();
  void Update();
  void Clean() {}
};

#endif