/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <exception>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "engine.h"
#include "SceneLoader.h"
#include "polygon.h"

#include <thread>
using namespace std;
int main(int argc, char** argv) try
{
  Engine e(argc, argv);

  std::shared_ptr<Scene> scn = std::make_shared<Scene>();
  scn->setVisible(true);
  e.SetScene(std::move(scn));

  Engine::Run();

  cin.get();
  return 0;
}
catch(std::exception& e)
{
    std::cerr << __FUNCTION__ << ": " << e.what() << std::endl;
    return -1;
}
catch(...)
{
    std::cerr << __FUNCTION__ << ": unknown exception" << std::endl;
}
