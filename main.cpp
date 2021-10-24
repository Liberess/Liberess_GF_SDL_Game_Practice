#include "Game.h"

int main(int argc, char* args[])
{
  if(TheGame::Instance()->Init("Chapter 1", 100, 100, 640, 480, false))
  {
    while(TheGame::Instance()->Running())
    {
      TheGame::Instance()->HandleEvents();
      TheGame::Instance()->Update();
      TheGame::Instance()->Render();
      SDL_Delay(10);
    }
  }
  else
  {
    std::cout << "Game Init Failure " << SDL_GetError() << std::endl;
    return -1;
  }

  TheGame::Instance()->Clean();
  return 0;
}