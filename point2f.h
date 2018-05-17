/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _POINT2F_H_
#define _POINT2F_H_
#include <GL/gl.h>
#include "drawable.h"
#include "color4.h"

struct Point2f: public Drawable
{
public:
  Point2f() {}
  ~Point2f(){}
  Point2f(const Point2f& other);
  Point2f(GLfloat _x, GLfloat _y):
    x(_x), y(_y) {}
  Point2f(GLfloat _x, GLfloat _y, const Color4& _color):
    x(_x), y(_y), color(_color) {}
  Point2f& operator=(const Point2f& other);

  GLfloat x = 0.0f;
  GLfloat y = 0.0f;
  Color4  color;

  void draw();
};

#endif // _POINT2F_H_
