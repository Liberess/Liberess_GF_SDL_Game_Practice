#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "SDL_image.h"
#include "Player.h" //실습
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
  bool Init(const char* title, int x, int y, int h, int w, int flags);
  void Update();
  void Render();
  void HandleEvents();
  void Clean();
  bool Running() const { return m_bRunning; }
  SDL_Renderer* GetRenderer() const { return m_pRenderer; }

private:
  Game() {}
  ~Game() {}
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_screenWidth, m_screenHeight;
  std::vector<GameObject*> m_gameObjs;
};

typedef Game TheGame;

#endif