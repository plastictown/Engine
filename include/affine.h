/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#ifndef _AFFINE_H_
#define _AFFINE_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <point2f.h>

class Affine
{
public:
  Affine()
    : m_scale{},
      m_rotation_angle{0.0f},
      m_rotation_point{},
      m_translation{}
  {};
  void apply()
  {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(m_translation.x, m_translation.y, 0.0f);
    glRotatef(m_rotation_angle, m_rotation_point.x, m_rotation_point.y, 0.0f);
    glScalef(m_scale.x, m_scale.y, 0.0f);
  }
  void setScale(const Point2f& s)
  {
    m_scale = s;
  }
  void setRotation(GLfloat angle, const Point2f& p)
  {
    m_rotation_angle = angle;
    m_rotation_point = p;
  }
  void setTranslation(const Point2f& p)
  {
    m_translation = p;
  }
private:
  Point2f m_scale;
  GLfloat m_rotation_angle;
  Point2f m_rotation_point;
  Point2f m_translation;
};



#endif /* _AFFINE_H_ */
