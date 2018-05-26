/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _IMAGE_H_INCLUDED_
#define _IMAGE_H_INCLUDED_

#include <cstdint>
#include <string>
#include <set>
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <rectf.h>
#include <point2f.h>
#include <incremeter.h>
#include <game-object.h>

class Image: public GameObject
{
private:
  //---POD type---//
  // deep copy not required
  GLuint m_id = 0;
  GLfloat aspect {0.0f};
  Rectf box;
  // global image id generator
  static Incrementer<GLuint> id_gen;
  static std::set<GLuint> textures;
public:
  GLfloat getAspect() const noexcept
  {
    return aspect;
  }
  GLuint getId() const noexcept
  {
    return m_id;
  }
  Image(): m_id {id_gen.get_next()}, box {}
  {
    setType(GameObjectType::TypeImage);
  }
  int width() const noexcept
  {
    return box.right_bottom.x;
  }
  int height() const noexcept
  {
    return box.right_bottom.y;
  }
  bool load(const std::string& fname);
  void set() const noexcept;
  const Image& getImage() const;
  static void cleanup();
  ~Image();
};

#endif // _IMAGE_H_INCLUDED_
