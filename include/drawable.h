/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED
#include <string>
#include <utility>
/**
  * @class Drawable
  * @brief interface to all drawable objects.
  * This means that the Render class may be
  * able to draw it.
  */
class Drawable
{
protected:
  std::string type;
public:
  Drawable(): type()  {  }
  /** @brief Draws the object.
    * Despite the idea of a generic rendering
    * implementation by the Render class, the
    * method will be virtual to allow for
    * special implementation.
    * @see Render
    */
  void setType(const std::string& type_){type = type_; }
  void setType(std::string&& type_){type = std::move(type_); }
  const std::string& getType() const { return type; }
  virtual void draw() = 0;
  virtual ~Drawable(){}
};

#endif // DRAWABLE_H_INCLUDED
