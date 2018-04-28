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

/** @class GameObject
 * @brief Base class for all objects in scene
 */
class GameObject
{
public:
  /**
   * @brief Set new position of the scene
   * @param [in] position - scene position relative
   * to the upper-left corner of the client window
   * @see getPosition
   */
  void setPosition(const Point2f& position)
  {
    pos = position;
  }
  /**
   * @brief Get current position of the scene
   * @return scene position relative
   * to the upper-left corner of the client window
   * @see setPosition
   */
  const Point2f& getPosition() const
  {
    return pos;
  }
  /**
   * Get object type
   * @return - value from GameObjectType enumeration
   * @see GameObjectType
   * @see setType
   */
  const GameObjectType& getType() const
  {
      return m_type;
  }
  /**
   * @brief Set object type
   * @param [in] type - object type from
   * GameObjectType enumeration
   * @see GameObjectType
   * @see getType
   */
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
