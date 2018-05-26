/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <functional>
#include <exception>
#include <stdexcept>
#include <memory>
#include <map>
#include <image.h>
#include <color4.h>
#include <point2f.h>
#include <point-object.h>
#include <rectf.h>
#include <scene.h>
#include <drawable.h>
#include <line-object.h>

using namespace std;

// must be a singleton
/** @class Render
 * @brief The class is responsible for
 * drawing the object and event management
 */
class Render
{
  static Render* instance;
  int window = 0;
  Color4 m_clearColor{1.0f, 1.0f, 1.0f, 0.8f};
  shared_ptr<Scene> scene{nullptr};
  std::map<std::string, std::function<void(const Drawable*)>> callbacks;
  const unsigned char KEY_ESCAPE = 27;

  void init();
  static void draw_func();
  static void reshape_func(GLint w, GLint h);
  static void idle_fucn();
  void PassiveMotion(int x, int y);
  static void passive_motion_func(int x, int y);
  void Motion(int x, int y);
  static void motion_func(int x, int y);
  void Keyboard(unsigned char key, int x, int y);
  static void keyboard_func(unsigned char key, int x, int y);
  void Entry(int state);
  static void entry_func(int state);
  void Mouse(int button, int state, int x, int y);
  static void mouse_func(int button, int state, int x, int y);
  void setupCam(GLint x, GLint y, GLint w, GLint h);
  void reshape(int w, int h);

  void draw_object(const Drawable& o);

  void draw_point2(const Drawable* po);
  void draw_line2(const Drawable* po);

  static void drawPoint2(const Drawable* po);
  static void drawLine2(const Drawable* po);
  /**
   * @brief Draw all
   */
  void draw();
  void Idle();

public:
  void SetScene(shared_ptr<Scene>&);
  static void DrawImage(const Image& im, const Point2f& pos);
  static void DrawObject(const Drawable& o);
  static void run();
  static Point2f getWindowSize() noexcept;
  Image LoadImage(const string& filename);
  Render(int argc,
         char** argv,
         GLuint w = 640,
         GLuint h = 480,
         GLuint x = 0,
         GLuint y = 0,
         char* name = nullptr);
  ~Render();
  void setClearColor(Color4&& c);
};

#endif  // RENDER_H_INCLUDED
