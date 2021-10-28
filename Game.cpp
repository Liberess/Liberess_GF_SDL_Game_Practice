#include "Game.h"

bool Game::Init(const char* title, int x, int y, int h, int w, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags); 

    if (m_pWindow != 0)
    {
      m_screenWidth = w;
      m_screenHeight = h;
      
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

        if(!TheTextureManager::Instance()->Load("Assets/jiu-alpha.png", "animate", m_pRenderer)) 
          return false;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

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
      case SDL_QUIT: m_bRunning = false; break;
      default: break;
    }
  }
}

void Game::Update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 5;
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  TheTextureManager::Instance()->Draw("animate", 0, 0, 52, 48, m_pRenderer);
  TheTextureManager::Instance()->DrawFrame("animate", 100, 100, 52, 49, 3, m_currentFrame, m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}