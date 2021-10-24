#include "Player.h"

void Player::Load(int x, int y, int width, int height, std::string textureID)
{
  GameObject::Load(x, y, width, height, textureID);
}

void Player::Draw(SDL_Renderer* pRenderer)
{
  GameObject::Draw(pRenderer);
}

void Player::Update()
{
  m_x -= 1;
}