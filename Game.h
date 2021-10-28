#ifndef __Game_H__
#define __Game_H__

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

typedef struct
{
  SDL_Texture* texture;
  SDL_Rect srcRect;
  SDL_Rect desRect;
} Sprite;

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
  SDL_Texture* m_pTexture;
  SDL_Rect m_srcRect;
  SDL_Rect m_desRect;
  int m_dirX;
  Sprite backSprite;
  int m_screenWidth, m_screenHeight;
};

#endif