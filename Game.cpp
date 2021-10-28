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
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

        SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

        if(pTempSurface != 0) //실습1
        {
          m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);
          SDL_QueryTexture(m_pTexture, NULL, NULL, &m_srcRect.w, &m_srcRect.h);

          m_desRect.x = m_srcRect.x = 0;
          m_desRect.y = m_srcRect.y = 0;

          m_desRect.w = m_srcRect.w;
          m_desRect.h = m_srcRect.h;
          m_dirX = 1;
        }
        else
        {
          return false;
        }

        pTempSurface = IMG_Load("Assets/background.png");
        if(pTempSurface != 0) //실습1
        {
          backSprite.texture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);

          backSprite.desRect.x = backSprite.srcRect.x = 0;
          backSprite.desRect.y = backSprite.srcRect.y = 0;

          backSprite.desRect.w = backSprite.srcRect.w = w;
          backSprite.desRect.h = backSprite.srcRect.h = h;
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
  if(m_desRect.x + m_desRect.w >= m_screenWidth || m_desRect.x < 0)
    m_dirX *= -1;

  m_desRect.x += 1 * m_dirX; //실습1
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, backSprite.texture, &backSprite.srcRect, &backSprite.desRect);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_srcRect, &m_desRect); //실습2
  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}