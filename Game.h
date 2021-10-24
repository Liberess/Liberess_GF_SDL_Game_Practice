#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "Player.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>

class Game
{
public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new Game();
    
    return s_pInstance;
  }
  bool Init(const char* title, int xPos, int yPos, int width, int height, int flags);
  bool Running() const { return m_bRunning; }
  void HandleEvents();
  void Update();
  void Render();
  void Clean();
  
private:
  Game() {}
  ~Game() {}
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
  int m_dircX;
  std::vector<GameObject*> m_gameObjs;
};

typedef Game TheGame;

#endif