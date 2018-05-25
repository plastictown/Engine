/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018
 * Mikhail Domchenkov agplastictown@yandex.ru
 * Paul Sachkov paul.pix71@gmail.com
 */

#ifndef __VERTEX2FC_H_INCLUDED__
#define __VERTEX2FC_H_INCLUDED__

#include <vertex.h>
#include <color.h>

class vertex2fc: public vertex2f {
  public:


  private:
    color <float, 4> rgbaColor;
};


#endif  //__VERTEX2FC_H_INCLUDED__
