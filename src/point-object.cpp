/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <point-object.h>
#include <utility>
#include <render.h>

PointObject::PointObject() : Drawable(), point{}, color{}
{
  setType("point2f");
}

PointObject::PointObject(const Point2f& pt, const Color4& c)
  : Drawable(), point(pt), color(c)
{
  setType("point2f");
}

PointObject::PointObject(const PointObject& rhs) : Drawable()
{
  if (this == &rhs)
    return;
  setType("point2f");
  point = rhs.point;
  color = rhs.color;
}

PointObject::PointObject(PointObject&& rhs)
{
  type = std::move(rhs.type);
  point = rhs.point;
  color = rhs.color;
}

PointObject& PointObject::operator=(const PointObject& rhs)
{
  if (this == &rhs)
    return *this;
  setType(rhs.type);
  point = rhs.point;
  color = rhs.color;
  return *this;
}

PointObject& PointObject::operator=(PointObject&& rhs)
{
  type = std::move(rhs.type);
  point = rhs.point;
  color = rhs.color;
  return *this;
}

bool PointObject::operator==(const PointObject& rhs) const noexcept
{
  if (this == &rhs)
    return true;
  return (point == rhs.point) && (color == rhs.getColor());
}

PointObject::~PointObject() {}

const Point2f& PointObject::getPoint() const noexcept
{
  return point;
}

const Color4& PointObject::getColor() const noexcept
{
  return color;
}

void PointObject::setPoint(const Point2f& pt) noexcept
{
  point = pt;
}

void PointObject::setColor(const Color4& c) noexcept
{
  color = c;
}

void PointObject::draw()
{
  Render::DrawObject(*this);
}
