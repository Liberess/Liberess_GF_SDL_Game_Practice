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

  m_textureManager.Load("Assets/animate-alpha.png", "animate", m_pRenderer);

  m_dircX = 1;

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
  m_currentFrame = (SDL_GetTicks() / 100) % 6;

  SDL_Delay(10);
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  m_textureManager.Draw("animate", 0, 0, 128, 82, m_pRenderer);
  m_textureManager.DrawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}