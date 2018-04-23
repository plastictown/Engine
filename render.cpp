/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include "render.h"
#include <exception>
#include <stdexcept>

Render* Render::instance = nullptr;

void Render::Entry(int state)
{
  //TODO
}

void Render::entry_func(int state)
{
  instance->Entry(state);
}

void Render::Motion(int x, int y)
{
  //TODO
}

void Render::motion_func(int x, int y)
{
  instance->Motion(x,y);
}

void Render::Mouse(int button, int state, int x, int y)
{
  //int modifiers = glutGetModifiers();
  // using with GLUT_ACTIVE_CTRL, GLUT_ACTIVE_ALT, GLUT_ACTIVE_SHIFT
  //TODO
}

void Render::mouse_func(int button, int state, int x, int y)
{
  instance->Mouse(button, state, x, y);
}

void Render::passive_motion_func(int x, int y)
{
  instance->PassiveMotion(x, y);
}

void Render::PassiveMotion(int x, int y)
{
  //TODO
}

void Render::idle_fucn()
{
  instance->Idle();
}

void Render::Idle()
{
  draw();
}

void Render::init()
{
  int image_flags = IMG_INIT_PNG;
  int init = IMG_Init(image_flags);
  if((init & image_flags) != image_flags)
    throw std::runtime_error("can't init SDL_Image");

  glEnable   (GL_TEXTURE_2D);
  glEnable   (GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glutDisplayFunc(draw_func);
  glutReshapeFunc(reshape_func);
  glutIdleFunc(idle_fucn);
  glutPassiveMotionFunc(passive_motion_func);
  glutMouseFunc(mouse_func);
  glutMotionFunc(motion_func);
  glutEntryFunc(entry_func);
  setClearColor(Color4 {1.0f,1.0f,1.0f,0.5f});
}

void Render::draw_func()
{
  instance->draw();
}

void Render::reshape_func(GLint w, GLint h)
{
  instance->reshape(w,h);
}

void Render::setupCam(GLint x, GLint y, GLint w, GLint h)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,h,0);
  glViewport(x,y,w,h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Render::reshape(int w, int h)
{
  glutPostRedisplay();
  setupCam(0,0,w,h);
}

Render::Render(int argc, char** argv,
               GLuint w,
               GLuint h,
               GLuint x,
               GLuint y,
               char* name )
{
  instance = this;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA);
  glutInitWindowSize(w,h);
  if(!(x==0 && y==0))
    glutInitWindowPosition(x,y);
  if(name!=nullptr)
    glutCreateWindow(name);
  else
    glutCreateWindow("OpenGL window");


  init(); // throws runtime_exception

  setupCam(0,0,640,480);
}

Render::~Render()
{
  // disablecallback
  glutDisplayFunc(nullptr);
  glutReshapeFunc(nullptr);
  glutIdleFunc(nullptr);
  glutPassiveMotionFunc(nullptr);
  glutMouseFunc(nullptr);
  glutMotionFunc(nullptr);
  glutEntryFunc(nullptr);

  IMG_Quit();
  Image::cleanup();
}

void Render::setClearColor(Color4&& c)
{
  m_clearColor= c;
  glClearColor(c.r,c.g,c.b,c.a);
}

void Render::draw()
{
  glClear(GL_COLOR_BUFFER_BIT);

  if(scene != nullptr)
    {
      scene->Draw();
    }

  glFlush();
  glutSwapBuffers();
}

void Render::DrawImage(const Image& im, const Point2f& pos)
{
  glBindTexture(GL_TEXTURE_2D,im.getId());
  Rectf r(Point2f(0,0), Point2f(im.width(),im.height()));
  r.heightByAspect(im.getAspect());
  glPushMatrix();
  glTranslatef(pos.x, pos.y, 0.0);
  glBegin(GL_QUADS);
  glTexCoord2f(0,0);
  glVertex2i (0  ,0  );
  glTexCoord2f(0 ,1);
  glVertex2i (0  ,r.right_bottom.y);
  glTexCoord2f(1 ,1);
  glVertex2i (r.right_bottom.x,r.right_bottom.y);
  glTexCoord2f(1,0);
  glVertex2i (r.right_bottom.x,0);
  glEnd();
  glPopMatrix();
}

void Render::run()
{
  glutMainLoop();
}

void Render::SetScene(shared_ptr<Scene>& s)
{
  scene = s;
}
