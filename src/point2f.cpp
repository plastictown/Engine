/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <point2f.h>
#include <render.h>

Point2f::Point2f(const Point2f& other)
{
  if (this != &other) *this = other;
}

Point2f& Point2f::operator=(const Point2f& rhs)
{
  if (this == &rhs) return *this;
  x = rhs.x;
  y = rhs.y;
  return *this;
}

bool Point2f::operator==(const Point2f& rhs) const noexcept
{
  if (this == &rhs) return true;
  return (x == rhs.x) && (y == rhs.y);
}
