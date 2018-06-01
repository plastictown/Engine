/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#ifndef __RECT_H_INCLUDED__
#define __RECT_H_INCLUDED__

#include <type_traits>
#include <array>
#include <exception>
#include <algorithm>
#include <initializer_list>

#include <vertex.h>

template <typename T, size_t N>
class rect
{
public:
  using vtx_t = vertex<T, N>;
  using rect_t = rect<T, N>;

  rect();
  rect(const rect_t& other);
  rect( const std::initializer_list<vtx_t>& il);
  rect_t& operator =(const rect_t& rhs);
  bool operator ==(const rect_t& rhs) const noexcept;
  void setAt(size_t idx, const vtx_t& val);
  const vtx_t& getAt(size_t idx) const;
  const vtx_t& operator[](size_t idx) const;
  vtx_t& operator[](size_t idx);
  virtual ~rect();
protected:
  std::array<vtx_t, 4> pts;
};

template <typename T, size_t N>
rect<T, N>::rect()
  : pts()
{
  static_assert( N > 1, "rect: too few coordinates! should be 2 or more");
  static_assert(std::is_arithmetic
                < typename std::remove_cv
                < typename std::remove_reference
                <T>::type >::type >::value,
                "values must have an arithmetic type!");
}

template <typename T, size_t N>
rect<T, N>::rect (const rect<T, N>& other)
  : rect()
{
  if(this == &other)
    return;
  std::copy(other.pts.cbegin(), other.pts.cend(), pts.begin());
}

template <typename T, size_t N>
rect<T, N>::rect( const std::initializer_list<vtx_t>& il)
: rect()
{
  if(il.size() != 4)
    throw std::invalid_argument("rect::ctor(): invalid IL size, should be 4");
  std::copy(il.begin(), il.end(), pts.begin());
}

template <typename T, size_t N>
rect<T, N>& rect<T, N>::operator =(const rect<T, N>& rhs)
{
  if(this == &rhs)
    return *this;
  std::copy(rhs.pts.cbegin(), rhs.pts.cend(), pts.begin());
  return *this;
}

template <typename T, size_t N>
bool rect<T, N>::operator ==(const rect<T, N>& rhs) const noexcept
{
  if(this == &rhs)
    return true;
  return (rhs.pts == pts);
}

template <typename T, size_t N>
void rect<T, N>::setAt(size_t idx, const vtx_t& val)
{
  if(idx >= 4)
    throw std::out_of_range("rect::setAt(): invalid index");
  pts[idx] = val;
}

template <typename T, size_t N>
const vertex<T, N>& rect<T, N>::getAt(size_t idx) const
{
  if(idx >= 4)
    throw std::out_of_range("rect::getAt(): invalid index");
  return pts[idx];
}

template <typename T, size_t N>
vertex<T, N>& rect<T, N>::operator[](size_t idx)
{
  if(idx >= 4)
    throw std::out_of_range("rect::operator[]: invalid index");
  return pts[idx];
}

template <typename T, size_t N>
const vertex<T, N>& rect<T, N>::operator[](size_t idx) const
{
  if(idx >= 4)
    throw std::out_of_range("rect::operator[]: invalid index");
  return pts[idx];
}

template <typename T, size_t N>
rect<T, N>::~rect()
{
  //stub
}

#endif // __RECT_H_INCLUDED__
