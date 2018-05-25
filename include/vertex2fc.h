/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018
 * Mikhail Domchenkov agplastictown@yandex.ru
 * Paul Sachkov paul.pix71@gmail.com
 */

#ifndef __VERTEX2FC_H_INCLUDED__
#define __VERTEX2FC_H_INCLUDED__

#include <vertex2f.h>
#include <color.h>

using rgba = color < float, 4>;

class vertex2fc: public vertex2f {
  public:
    vertex2fc();
    vertex2fc(const vertex2fc & rhs);
    vertex2fc(float x, float y, rgba c);
    float getX() const;
    float getY() const;
    rgba getColor() const;
    void setX(const float& x);
    void setY(const float& y);
    void setColor(const rgba);
    vertex2fc& operator=(const vertex2fc& rhs);
    bool operator == (const vertex2fc& rhs);

  private:
    rgba color;
};


#endif  //__VERTEX2FC_H_INCLUDED__

vertex2fc::vertex2fc(): vertex2f () {}

vertex2fc::vertex2fc(const vertex2fc &rhs)
    : vertex2f (rhs), color(rhs.getColor()) {
}

vertex2fc::vertex2fc(float x, float y, rgba c): vertex2f {x, y}, color(c) {
}

rgba vertex2fc::getColor() const {
    return color;

}


