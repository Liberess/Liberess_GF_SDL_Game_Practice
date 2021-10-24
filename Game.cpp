#include "Game.h"

bool Game::Init(const char* title, int xPos, int yPos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return false;

  m_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

  if (m_pWindow == 0)
    return false;

  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

  if(m_pRenderer == 0)
    return false;

  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

  m_bRunning = true;
  return true;
}

void Game::HandleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::Update()
{
  static int count = 0;

  if(count >= 5)
  {
    m_bRunning = false;
    return;
  }

  SDL_SetRenderDrawColor(m_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
  SDL_Delay(1000);
  ++count;
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}