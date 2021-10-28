#include "GameObject.h" //실습2

void GameObject::Load(int x, int y, int w, int h, std::string textureID)
{
  m_x = x;
  m_y = y;
  m_width = w;
  m_height = h;
  m_textureID = textureID;
  m_currentRow = m_currentFrame = 0;
}

void GameObject::Draw(SDL_Renderer* pRenderer)
{
  TheTextureManager::Instance()->DrawFrame("animate", m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::Update()
{
  m_x += 1;
}

void GameObject::Clean()
{

}