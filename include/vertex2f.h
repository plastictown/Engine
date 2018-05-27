/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <vertex.h>

#ifndef __VERTEX2F_H_INCLUDED__
#define __VERTEX2F_H_INCLUDED__

/** @class vertex2f
 * @brief 2D vertex object.
 * Implements vertex on a plain
 * with (x,y) coordinates
 */
class vertex2f: public vertex<float, 2>
{
public:
  /**
   * @brief default ctor
   */
  vertex2f();
  /**
   * @brief copy ctor
   * @param [in] other - source object
   */
  vertex2f(const vertex2f& other);
  /**
   * @brief ctor with arguments
   * @param [in] x - X coordinate of the vertex
   * @param [in] y - Y coordinate of the vertex
   */
  vertex2f( float x, float y);
  /**
   * @brief get X coordinate of the vertex
   * @return X coordinate of the vertex
   */
  float getX() const;
  /**
   * @brief get Y coordinate of the vertex
   * @return Y coordinate of the vertex
   */
  float getY() const;
  /**
   * @brief set X coordinate of the vertex
   * @param [in] x - new value of the X coordinate
   */
  void setX(const float& x);
  /**
   * @brief set Y coordinate of the vertex
   * @param [in] y - new value of the Y coordinate
   */
  void setY(const float& y);
  /**
   * @brief assign value from another vertex2f object
   * @param [in] rhs - source object
   * @return reference on the current object
   */
  vertex2f& operator=(const vertex2f& rhs);
  /**
   * @brief compare two vertex2f objects
   * @param [in] rhs - source object
   * @return true if the objects are euqal,
   * false otherwise
   */
  bool operator ==(const vertex2f& rhs) const noexcept;
  /**
   * @brief get pointer to data array
   * @return pointer to data array
   */
  const float* data() const noexcept;
};

#endif // __VERTEX2F_H_INCLUDED__
