#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams)
  : SDLGameObject(pParams)
{

}

void Enemy::Draw()
{
  SDLGameObject::Draw();
}

void Enemy::Update()
{
  m_x += 1;
  m_y += 1;
  m_currentFrame = (SDL_GetTicks() / 100) % 6;
}