#ifndef __LoaderParams_H__
#define __LoaderParams_H__

#include <iostream>

class LoaderParams
{
public:
  LoaderParams(int x, int y, int width, int height, std::string textureID)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}
  int GetX() const { return m_x; }
  int GetY() const { return m_y; }
  int GetWidth() const { return m_width; }
  int GetHeight() const { return m_height; }
  std::string GetTextureID() const { return m_textureID; }
  
protected:
  int m_x, m_y;
  int m_width, m_height;
  std::string m_textureID;
};

#endif