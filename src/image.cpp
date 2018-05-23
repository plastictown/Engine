/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <image.h>
#include <GL/gl.h>
#include <iostream>

Incrementer<GLuint> Image::id_gen;
std::set<GLuint> Image::textures;

void Image::cleanup()
{
  if(textures.empty())
    return;
  for(auto i:textures)
    {
      glDeleteTextures(1, &i);
    }
}

bool Image::load(const std::string& fname)
{
  SDL_RWops *rwop = SDL_RWFromFile(fname.c_str(), "rb");
  if(!rwop)
    return false;
  SDL_Surface* surface = IMG_LoadPNG_RW(rwop);
  if(surface == nullptr)
    return false;
  glGenTextures(1, &m_id);
  glBindTexture(GL_TEXTURE_2D, m_id);

  int Mode = GL_RGBA;
  glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);
  box.right_bottom = Point2f {GLfloat(surface->w), GLfloat(surface->h)};

  aspect = GLfloat(surface->w) / GLfloat(surface->h);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

  SDL_FreeSurface(surface);
  return true;
}
void Image::set() const noexcept
{
  glBindTexture(GL_TEXTURE_2D, m_id);
}
Image::~Image()
{
  //glDeleteTextures(1,&m_id);
}

const Image& Image::getImage() const
{
  return *this;
}
