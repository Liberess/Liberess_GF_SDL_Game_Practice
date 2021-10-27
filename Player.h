#ifndef __Player_H__
#define __Player_H__

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  void Draw();
  void Update();
  void Clean() {}
};

#endif