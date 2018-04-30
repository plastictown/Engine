/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include "polygon.h"
#include <utility>

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
Polygon::~Polygon () try
{
  m_vertices.clear ();
}
catch (...)
{
  //stub
}
bool Polygon::empty () const noexcept
{
  return m_vertices.empty ();
}
bool Polygon::valid () const noexcept
{
  return m_vertices.size () > 2;
}

bool Polygon::pointInPolygon (const Point2f& p) const try
{
  if (!valid ())
    return false;
  int nvert = m_vertices.size ();
  float testx = p.x;
  float testy = p.y;
  int i, j, c = 0;
  for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
      if (((m_vertices[i].y > testy) != (m_vertices[j].y > testy))
	  && (testx
	      < (m_vertices[j].x - m_vertices[i].x) * (testy - m_vertices[i].y)
		  / (m_vertices[j].y - m_vertices[i].y) + m_vertices[i].x))
	c = !c;
    }
  return static_cast<bool> (c);
}
catch (...)
{
  //stub
  return false;
}
bool Polygon::pointInPolygon (const Point2f&& p) const try
{
  if (!valid ())
    return false;
  int nvert = m_vertices.size ();
  float testx = p.x;
  float testy = p.y;
  int i, j, c = 0;
  for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
      if (((m_vertices[i].y > testy) != (m_vertices[j].y > testy))
	  && (testx
	      < (m_vertices[j].x - m_vertices[i].x) * (testy - m_vertices[i].y)
		  / (m_vertices[j].y - m_vertices[i].y) + m_vertices[i].x))
	c = !c;
    }
  return static_cast<bool> (c);
}
catch (...)
{
  //stub
  return false;
}

void Polygon::addPoint (const Point2f& rhs) try
{
  m_vertices.push_back (rhs);
}
catch (...)
{
  //stub
}
void Polygon::addPoint (const Point2f&& rhs) try
{
  m_vertices.emplace_back (rhs);
}
catch (...)
{
  //stub
}
