/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <vertex2f.h>

vertex2f::vertex2f()
  : vertex()
{
}

vertex2f::vertex2f(const vertex2f& other)
  : vertex(other)
{
}

vertex2f::vertex2f( float x, float y)
  : vertex({x, y})
{
}

float vertex2f::getX() const
{
  return getAt(0);
}

float vertex2f::getY() const
{
  return getAt(1);
}

void vertex2f::setX(const float& x)
{
  setAt(0, x);
}

void vertex2f::setY(const float& y)
{
  setAt(1, y);
}

vertex2f& vertex2f::operator=(const vertex2f& rhs)
{
  if(this == &rhs)
    return *this;
  this->coords = rhs.coords;
  return *this;
}

bool vertex2f::operator ==(const vertex2f& rhs) const noexcept
{
  if(this == &rhs)
    return true;
  return vertex<float, 2>::operator==(rhs);
}

const float* vertex2f::data() const noexcept
{
  return this->coords.data();
}

vertex2f::operator vertex<float,2>() const
{
  return static_cast<vertex<float,2>>(*this);
}

float& vertex2f::operator [] (size_t idx)
{
  return vertex<float, 2>::operator[](idx);
}

const float& vertex2f::operator [] (size_t idx) const
{
  return vertex<float, 2>::operator[](idx);
}

