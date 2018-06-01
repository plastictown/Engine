/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#ifndef __RECT2F_H_INCLUDED__
#define __RECT2F_H_INCLUDED__

#include <rect.h>
#include <vertex2f.h>

class rect2f: public rect<float, 2>
{
public:
  rect2f();
  rect2f(const rect2f& other);
  rect2f( const std::initializer_list<vertex2f>& il);
  rect2f& operator =(const rect2f& rhs);
  bool operator ==(const rect2f& rhs) const noexcept;
  void setAt(size_t idx, const vertex2f& val);
  const vertex2f& getAt(size_t idx) const;
  const vertex2f& operator[](size_t idx) const;
  vertex2f& operator[](size_t idx);
  operator rect<float,2>() const;
  virtual ~rect2f();
};

#endif // __RECT2F_H_INCLUDED__
