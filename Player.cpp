#include "Player.h"

void Player::Load(int x, int y, int w, int h, std::string textureID)
{
  GameObject::Load(x, y, w, h, textureID);
}

void Player::Draw(SDL_Renderer* pRenderer)
{
  GameObject::Draw(pRenderer);
}

void Player::Update()
{
  m_x -= 1;
}

void Player::Clean()
{

}