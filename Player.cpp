#include "Player.h"

void Player::Draw()
{
  SDLGameObject::Draw();
}

void Player::Update()
{
  m_x -= 1;
  m_currentFrame = (SDL_GetTicks() / 100) % 6;
}