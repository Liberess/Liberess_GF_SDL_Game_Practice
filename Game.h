#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "Player.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

class Game
{
public:
  Game() {}
  ~Game() {}
  bool Init(const char* title, int xPos, int yPos, int width, int height, int flags);
  bool Running() const { return m_bRunning; }
  void HandleEvents();
  void Update();
  void Render();
  void Clean();
  
private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
  int m_dircX;
  GameObject m_go;
  Player m_player;
};

#endif