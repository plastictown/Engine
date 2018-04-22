/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _RECTF_H_INCLUDED_
#define _RECTF_H_INCLUDED_

#include "point2f.h"

struct Rectf
{
  Rectf(): left_top(), right_bottom() {}
  Rectf(GLfloat x, GLfloat y, GLfloat w, GLfloat h):
    left_top {x,y}, right_bottom {x+w, y+h} {}
  Rectf(const Point2f& lt, const Point2f& rb):
    left_top {lt}, right_bottom {rb} {}
  Rectf(const Rectf& r);
  Rectf& operator = (const Rectf& r);
  void heightByAspect(GLfloat aspect);
  void widthByAspect(GLfloat aspect);
  bool pointInRect(const Point2f& pt) const noexcept;

  Point2f left_top;
  Point2f right_bottom;
};

#endif // _RECTF_H_INCLUDED_
