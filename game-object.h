/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _GAME_OBJECT_H_INCLUDED_
#define _GAME_OBJECT_H_INCLUDED_

#include "point2f.h"
#include "rectf.h"

class Image;

/** @enum GameObjectType
 * contain types of all possible
 * objects in a Scene
 */
enum class GameObjectType
{
    TypeImage,
    TypeAnimation
};

class GameObject
{
public:
  void setPosition(const Point2f& position)
  {
    pos = position;
  }
  const Point2f& getPosition() const
  {
    return pos;
  }
  const GameObjectType& getType() const
  {
      return m_type;
  }
  void setType(const GameObjectType& type)
  {
      m_type = type;
  }
  virtual ~GameObject() {}
protected:
  Point2f pos;
private:
    GameObjectType m_type;
};

#endif // _GAME_OBJECT_H_INCLUDED_
