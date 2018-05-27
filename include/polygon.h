/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 * see https://wrf.ecse.rpi.edu//Research/Short_Notes/pnpoly.html
 * for PNPOLY algorithm
 */

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <vector>
#include <vertex.h>

template<typename T, size_t N>
class polygon
{
public:

  polygon<T, N>();
  polygon<T, N>(const polygon<T, N>& other);
  polygon<T, N>(polygon<T, N>&& other);
  polygon<T, N>& operator=(const polygon<T, N>& rhs);
  polygon<T, N>& operator=(const polygon<T, N> && rhs);
  bool operator ==(const polygon<T, N>& rhs) const noexcept;
  virtual ~polygon<T, N>() noexcept;
  bool empty() const noexcept;
  bool valid() const noexcept;
  bool pointInPolygon(const vertex<T, N>&) const; //for 2D only
  void addVertex(const vertex<T, N>&);
  const vertex<T, N>& getAt(size_t idx) const;
  void setAt(size_t idx, const vertex<T, N>& vtx);
  size_t size() const noexcept;
  vertex<T, N>& operator[](size_t idx);
  //void fromRect(const Rectf&); // TODO
protected:
  std::vector<vertex<T, N>> m_vtx;
};


template< typename T, size_t N>
polygon<T, N>::polygon()
  : m_vtx()
{
  static_assert( N > 1, "too few coordinates! should be 2 or more");
  static_assert(std::is_arithmetic
                < typename std::remove_cv
                < typename std::remove_reference
                <T>::type >::type >::value,
                "values must have an arithmetic type!");
}

template< typename T, size_t N>
polygon<T, N>::polygon(const polygon<T, N>& other)
  : polygon()
{
  m_vtx = other.m_vtx;
}
template< typename T, size_t N>
polygon<T, N>::~polygon() noexcept
{
  m_vtx.clear();
}

template< typename T, size_t N>
polygon<T, N>::polygon(polygon<T, N>&& other)
  : polygon()
{
  m_vtx = std::move(other.m_vtx);
}

template< typename T, size_t N>
polygon<T, N>& polygon<T, N>::operator=(const polygon<T, N>& rhs)
{
  if(this == &rhs)
    return *this;
  m_vtx = rhs.m_vtx;
  return *this;
}

template< typename T, size_t N>
polygon<T, N>& polygon<T, N>::operator=(const polygon<T, N> && rhs)
{
  m_vtx = std::move(rhs.m_vtx);
  return *this;
}

template< typename T, size_t N>
bool polygon<T, N>::operator==(const polygon<T, N>& rhs) const noexcept
{
  if( this == &rhs)
    return true;
  return (m_vtx == rhs.m_vtx);
}

template< typename T, size_t N>
bool polygon<T, N>::empty() const noexcept
{
  return m_vtx.empty();
}

template< typename T, size_t N>
bool polygon<T, N>::valid() const noexcept
{
  return (m_vtx.size() > 2);
}

template< typename T, size_t N>
void polygon<T, N>::addVertex(const vertex<T, N>& vtx)
{
  m_vtx.push_back(vtx);
}

template< typename T, size_t N>
const vertex<T, N>& polygon<T, N>::getAt(size_t idx) const
{
  if(idx >= m_vtx.size())
    throw std::out_of_range("polygon::getAt(): invalid index value");
  return m_vtx[idx];
}

template< typename T, size_t N>
void polygon<T, N>::setAt(size_t idx, const vertex<T, N>& vtx)
{
  if(idx >= m_vtx.size())
    throw std::out_of_range("polygon::setAt(): invalid index value");
  m_vtx[idx] = vtx;
}

template< typename T, size_t N>
size_t polygon<T, N>::size() const noexcept
{
  return m_vtx.size();
}

template< typename T, size_t N>
vertex<T, N>& polygon<T, N>::operator[](size_t idx)
{
  if(idx >= m_vtx.size())
    throw std::out_of_range("polygon::operator[]: invalid index value");
  return m_vtx[idx];
}

template< typename T, size_t N>
bool polygon<T, N>::pointInPolygon (const vertex<T, N>& p) const try
{
  static_assert(N == 2, "only 2D vertexes supported");

  if (!valid ())
    return false;
  int nvert = m_vtx.size ();
  T testx = p.getAt(0);
  T testy = p.getAt(1);
  int i, j, c = 0;
  for (i = 0, j = nvert - 1; i < nvert; j = i++)
  {
    if (((m_vtx[i].getAt(1) > testy) != (m_vtx[j].getAt(1) > testy))
        && (testx
            < (m_vtx[j].getAt(0) - m_vtx[i].getAt(0)) * (testy - m_vtx[i].getAt(1))
            / (m_vtx[j].getAt(1) - m_vtx[i].getAt(1)) + m_vtx[i].getAt(0)))
      c = !c;
  }
  return static_cast<bool> (c);
}
catch (...)
{
  //stub
  return false;
}

#endif /* _POLYGON_H_ */

