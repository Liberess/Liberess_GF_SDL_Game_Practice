#include "Game.h"

Game* Game::s_pInstance = 0;

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

  if(!TheTextureManager::Instance()->Load("Assets/animate-alpha.png", "animate", m_pRenderer))
    return false;

  GameObject* m_go = new GameObject();
  GameObject* m_player = new Player();

  m_go->Load(100, 100, 128, 82, "animate");
  m_player->Load(300, 300, 128, 82, "animate");

  m_gameObjs.push_back(m_go);
  m_gameObjs.push_back(m_player);

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
  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Update();
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);

  for(int i = 0; i < m_gameObjs.size(); i++)
    m_gameObjs[i]->Draw(m_pRenderer);

  SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}