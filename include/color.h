/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018
 * Mikhail Domchenkov
 * agplastictown@yandex.ru
 * Paul Sachkov
 * paul.pix71@gmail.com
 */

#ifndef __COLOR_H__
#define __COLOR_H__

#include <type_traits>
#include <initializer_list>
#include <array>
#include <vector>
#include <exception>

typedef unsigned char uchar;

template <typename T, size_t N>
class color
{
public:
  /// defaut ctor
  color<T, N>();
  color<T, N> (const std::initializer_list<T>& ilist);
  ///copy ctor
  color<T, N>(const color<T, N>& rhs);
  color<T, N>& operator=(const color<T, N>& rhs );
  bool operator==(const color<T, N>& rhs ) const;
  void set(const std::initializer_list<T>& ilist );
  void setAt(const size_t index, const T& value);
  T& getAt(const size_t index);

protected:
  std::array<T, N> colors;
};


template<typename T, size_t N>
color<T, N>::color()
{
  static_assert( N > 1, "too few coordinates! should be 2 or more");
  static_assert(std::is_arithmetic
                <typename std::remove_cv
                < typename std::remove_reference
                <T>::type>::type>::value,
                "values must have an arithmetic type!");
  colors.fill(0);
}

template<typename T, size_t N>
color<T, N>::color(const std::initializer_list<T>& ilist): color<T, N>()
{
  set(ilist);
}

template <typename T, size_t N>
color<T, N>::color(const color<T, N>& rhs)
{
  if(this == &rhs)
    return;
  std::copy(rhs.colors.cbegin(), rhs.colors.cend(), colors.begin());
}
template<typename T, size_t N>
color<T, N>& color<T, N>::operator=(const color<T, N>& rhs)
{
  if(this != &rhs)
  {
    std::copy(rhs.colors.cbegin(), rhs.colors.cend(), colors.begin());
  }
  return * this;
}

template <typename T, size_t N>
bool color<T, N>::operator==(const color<T, N>& rhs) const
{
  return ((this == &rhs) ? true : (colors == rhs.colors));
}

template <typename T, size_t N>
void color<T, N> ::set(const std::initializer_list<T>& ilist)
{
  if(ilist.size() != N)
    throw std::invalid_argument("color::ctor(std::initializer_list) : invalid number of color parameters");
  size_t iter = 0;
  for(auto& i : ilist)
    colors[iter++] = i;
}

template<typename T, size_t N>
void color<T, N>::setAt(const size_t index, const T& value)
{
  if(index >= N)
    throw std::out_of_range("color::setAt(): invalid argument");
  colors[index] = value;
}

template<typename T, size_t N>
T& color<T, N>::getAt(const size_t index)
{
  if(index >= N)
    throw std::out_of_range("color::getAt(): invalid argument");
  return colors[index];
}


#endif  //__COLOR_H__
