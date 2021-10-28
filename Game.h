#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "SDL_image.h"
#include "Player.h" //실습
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

class Game
{
public:
  Game() {}
  ~Game() {}
  bool Init(const char* title, int x, int y, int h, int w, int flags);
  void Update();
  void Render();
  void HandleEvents();
  void Clean();
  bool Running() const { return m_bRunning; }

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_screenWidth, m_screenHeight;
  GameObject m_go;
  Player m_player;
};

#endif