/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "engine.h"
#include "SceneLoader.h"


using namespace std;
int main(int argc, char** argv)
{
  Engine e(argc, argv);

  std::shared_ptr<Scene> scn = std::make_shared<Scene>();
  if(!scn->FromFile("sample_scene.scn"))
    {
      cerr << __FUNCTION__ << ": can't load scene" << endl;
      return -1;
    }

  e.SetScene(std::move(scn));

  Engine::Run();

  return 0;
}
