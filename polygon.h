/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * see https://wrf.ecse.rpi.edu//Research/Short_Notes/pnpoly.html
 * for PNPOLY algorithm
 */

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <vector>
#include "point2f.h"

int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
	 (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}

class Polygon
{
public:
private:
  std::vector<Point2f> m_pts;
};

#endif /* _POLYGON_H_ */
