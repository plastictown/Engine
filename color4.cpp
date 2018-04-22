/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include "color4.h"

Color4::Color4()
{
  r=g=b=1.0f;
  a=0.5f;
}

Color4::Color4(const Color4& other)
{
  *this = other;
}

Color4& Color4::operator=(const Color4& rhs)
{
  if (this == &rhs) return *this;
  r=rhs.r;
  g=rhs.g;
  b=rhs.b;
  a=rhs.a;
  return *this;
}
