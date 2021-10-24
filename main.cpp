#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

int main(int argc, char* args[]); // 실습1
bool Init(const char* title, int xPos, int yPos, int width, int height, int flags);
void Update();
void Render();

int main(int argc, char* args[])
{
  if(Init
      (
        "Breaking Up HelloSDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN)
      )
  {
    g_bRunning = true;
  }
  else
  {
    return 1;
  }

  while(g_bRunning)
  {
    Update(); // 실습2
    Render();
  }

  SDL_Quit();

  return 0;
}

bool Init(const char* title, int xPos, int yPos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  g_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

  if (g_pWindow != 0)
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 0);

  return true;
}

void Update()
{
  static int count = 0;

  if(count >= 5)
  {
    g_bRunning = false;
    return;
  }

  SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
  SDL_Delay(1000);
  ++count;
}

void Render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}