#include "Game.h"
#include "Enemy.h"
#include "Player.h"

Game* Game::s_pInstance = 0;

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

        if(TheTextureManager::Instance()->Load("Assets/animate-alpha.png", "animate", m_pRenderer)) 
        {
          m_gameObjs.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
          m_gameObjs.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));
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
  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Update();
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Draw();

  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}