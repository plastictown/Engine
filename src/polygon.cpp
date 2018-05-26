/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <polygon.h>
#include <utility>
#include <algorithm>

Polygon::Polygon ()
  :m_vertices{}
{
}
Polygon::Polygon (const Polygon& rhs)try
  :m_vertices{}
{
  if (this == &rhs)
    return;
  m_vertices = rhs.m_vertices;
}
catch (...)
{
  m_vertices.clear ();
  throw;
}
Polygon::Polygon (Polygon && rhs) try
  :m_vertices{}
{
  m_vertices = std::move (rhs.m_vertices);
}
catch (...)
{
  m_vertices.clear ();
  throw;
}
Polygon& Polygon::operator= (const Polygon& rhs) try
{
  if (this == &rhs)
    return *this;
  m_vertices = rhs.m_vertices;
  return *this;
}
catch (...)
{
  m_vertices.clear ();
  throw;
}
Polygon& Polygon::operator= (const Polygon&& rhs) try
{
  m_vertices = std::move (rhs.m_vertices);
  return *this;
}
catch (...)
{
  m_vertices.clear ();
  throw;
}
Polygon::~Polygon () noexcept try
{
  m_vertices.clear ();
}
catch (...)
{
  // handle it!
}
bool Polygon::empty () const noexcept
{
  return m_vertices.empty ();
}
bool Polygon::valid () const noexcept
{
  return m_vertices.size () > 2;
}

bool Polygon::pointInPolygon (const vertex2f& p) const try
{
  if (!valid ())
    return false;
  int nvert = m_vertices.size ();
  float testx = p.getX();
  float testy = p.getY();
  int i, j, c = 0;
  for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
      if (((m_vertices[i].getY() > testy) != (m_vertices[j].getY() > testy))
	  && (testx
	      < (m_vertices[j].getX() - m_vertices[i].getX()) * (testy - m_vertices[i].getY())
		  / (m_vertices[j].getY() - m_vertices[i].getY()) + m_vertices[i].getX()))
	c = !c;
    }
  return static_cast<bool> (c);
}
catch (...)
{
  //stub
  return false;
}
bool Polygon::pointInPolygon (const vertex2f&& p) const try
{
  if (!valid ())
    return false;
  int nvert = m_vertices.size ();
  float testx = p.getX();
  float testy = p.getY();
  int i, j, c = 0;
  for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
      if (((m_vertices[i].getY() > testy) != (m_vertices[j].getY() > testy))
	  && (testx
	      < (m_vertices[j].getX() - m_vertices[i].getX()) * (testy - m_vertices[i].getY())
		  / (m_vertices[j].getY() - m_vertices[i].getY()) + m_vertices[i].getX()))
	c = !c;
    }
  return static_cast<bool> (c);
}
catch (...)
{
  //stub
  return false;
}

void Polygon::addPoint (const vertex2f& rhs) try
{
  m_vertices.push_back (rhs);
}
catch(...)
{
  //TODO: handle it!
  throw;
}

void Polygon::addPoint (const vertex2f&& rhs) try
{
  m_vertices.emplace_back (std::move(rhs));
}
catch(...)
{
  //TODO: handle it!
  throw;
}

/*
void Polygon::fromRect(const Rectf& rect)try
{
  m_vertices.resize(4);
  m_vertices[0] = {rect.left_top.x, rect.right_bottom.y};
  m_vertices[1] = rect.left_top;
  m_vertices[2] = {rect.right_bottom.x, rect.left_top.y};
  m_vertices[3] = rect.right_bottom;
}
catch(...)
{
  //stub
}
*/

size_t Polygon::numPoints() const noexcept
{
  return m_vertices.size();
}

bool Polygon::operator == (const Polygon& other) const noexcept
{
  if( this->numPoints() != other.numPoints()) return false;
  return std::equal(m_vertices.begin(), m_vertices.end(), other.m_vertices.begin());
}
