/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * see https://wrf.ecse.rpi.edu//Research/Short_Notes/pnpoly.html
 * for PNPOLY algorithm
 */

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <vector>
#include <point2f.h>
#include <rectf.h>

class Polygon
{
public:
  Polygon();
  Polygon(const Polygon&);
  Polygon(Polygon&&);
  Polygon& operator=(const Polygon&);
  Polygon& operator=(const Polygon&&);
  bool operator ==(const Polygon&) const noexcept;
  virtual ~Polygon();
  bool empty() const noexcept;
  bool valid() const noexcept;
  bool pointInPolygon(const Point2f&) const;
  bool pointInPolygon(const Point2f&&)const;
  void addPoint(const Point2f&);
  void addPoint(const Point2f&&);
  void fromRect(const Rectf&);
  size_t numPoints() const noexcept;

private:
  std::vector<Point2f> m_vertices;
};

#endif /* _POLYGON_H_ */

