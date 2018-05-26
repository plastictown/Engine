/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef __POINT_OBJECT_H__
#define __POINT_OBJECT_H__

#include <drawable.h>
#include <point2f.h>
#include <color4.h>

class PointObject : public Drawable
{
public:
  PointObject();                                    //
  PointObject(const Point2f& pt, const Color4& c);  //
  PointObject(const PointObject& rhs);              //
  PointObject(PointObject&& rhs);                   //
  PointObject& operator=(const PointObject& rhs);   //
  PointObject& operator=(PointObject&& rhs);        //
  bool operator==(const PointObject& rhs) const noexcept;
  const Point2f& getPoint() const noexcept;
  const Color4& getColor() const noexcept;
  void setPoint(const Point2f& pt) noexcept;
  void setColor(const Color4& c) noexcept;
  void draw();     //
  ~PointObject();  //
private:
  Point2f point;
  Color4 color;
};

#endif  // __POINT_OBJECT_H__
