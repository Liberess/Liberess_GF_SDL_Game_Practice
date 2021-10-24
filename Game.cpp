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

  SDL_Surface* pTempSurface2 = IMG_Load("Assets/background.png");
  if(pTempSurface2 != 0) //실습1
  {
    m_background.texture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);
    SDL_FreeSurface(pTempSurface2);

    m_background.desRect.w = m_background.srcRect.w = 640;
    m_background.desRect.h = m_background.srcRect.h = 480;
    m_background.desRect.x = m_background.srcRect.x = 0;
    m_background.desRect.y = m_background.srcRect.y = 0;
  }
  else
  {
    return false;
  }
  
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
  if(pTempSurface == 0) //실습1
    return false;

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  //실습1
  m_desRect.w = m_srcRect.w = 128;
  m_desRect.h = m_srcRect.h = 82;
  m_desRect.x = m_srcRect.x = 0;
  m_desRect.y = m_srcRect.y = 0;

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
  if(m_desRect.x + m_desRect.w >= 640 || m_desRect.x < 0)
    m_dircX *= -1;

  //m_desRect.x += 1 * m_dircX;

  m_srcRect.x = 128 * ((SDL_GetTicks() / 100) % 6);

  SDL_Delay(10);
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_background.texture, &m_background.srcRect, &m_background.desRect);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_desRect);
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}