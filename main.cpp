/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "engine.h"
#include "SceneLoader.h"
#include <vector>

using namespace std;
int main(int argc, char** argv)
{
  Engine e(argc, argv);

  shared_ptr<Scene> scn= make_shared<Scene>();
  if(!scn->FromFile("sample_scene.scn"))
    {
      cerr << __FUNCTION__ << ": can't load scene" << endl;
      return -1;
    }

  e.SetScene(std::move(scn));

  Engine::Run();

  return 0;
}
