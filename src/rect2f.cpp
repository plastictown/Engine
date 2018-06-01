/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

 #include <iterator>
 #include <rect2f.h>

rect2f::rect2f()
:rect()
{

}

rect2f::rect2f(const rect2f& other)
:rect(other)
{

}

rect2f::rect2f( const std::initializer_list<vertex2f>& il)
:rect()
{
  if(il.size() != 4)
    throw std::invalid_argument("rect2f::ctor(): invalid IL size, should be 4");
  std::copy(il.begin(), il.end(), pts.begin());
}

rect2f& rect2f::operator =(const rect2f& rhs)
{
  if(this == &rhs)
    return *this;
  pts = rhs.pts;
  return *this;
}

bool rect2f::operator ==(const rect2f& rhs) const noexcept
{
  if(this == &rhs)
    return true;
  return rect<float,2>::operator == (rhs);
}

void rect2f::setAt(size_t idx, const vertex2f& val)
{
  rect<float,2>::setAt(idx, val);
}

const vertex2f& rect2f::getAt(size_t idx) const
{
  return static_cast<const vertex2f&>(rect<float,2>::getAt(idx));
}

vertex2f& rect2f::operator[](size_t idx)
{
  return static_cast<vertex2f&>(rect<float,2>::operator[](idx));
}

const vertex2f& rect2f::operator[](size_t idx) const
{
  return static_cast<const vertex2f&>(rect<float,2>::operator[](idx));
}

rect2f::operator rect<float,2>() const
{
  return static_cast<rect<float,2>>(*this);
}

rect2f::~rect2f()
{

}
