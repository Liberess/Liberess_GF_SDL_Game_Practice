#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
  : GameObject(pParams)
{
  m_x = pParams->GetX();
  m_y = pParams->GetY();
  m_width = pParams->GetWidth();
  m_height = pParams->GetHeight();
  m_textureID = pParams->GetTextureID();
  m_currentRow = m_currentFrame = 0;
}

void SDLGameObject::Draw()
{
  TheTextureManager::Instance()->DrawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->GetRenderer());
}