/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <exception>
#include <thread>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include <engine.h>
#include <SceneLoader.h>
#include <polygon.h>
#include <vertex.h>
#include <vertex2f.h>
#include <vertex2fc.h>
#include <color.h>

using namespace std;

void test_dev_paul()
{
  color <float, 4>* c1 = new color<float, 4> {1.0f, 0.5f, 0.9f, 1.0f};
  color <float, 4>* c2 = new color<float, 4> {0.3f, 0.7f, 0.3f, 1.0f};
  vertex2fc v1(1, 2, *c1);
  vertex2fc v2;
  v2 = v1;
  v2 = *c2;


  cout << std::boolalpha << (v1 == v2) << endl;
}

int main(int argc, char** argv) try
{
  //test
  test_dev_paul();

  //\test

//    Engine e(argc, argv);

//    vertex2f v(1, 5);
//    vertex2f vv(2, 3);

//    cout << (vv == v) << endl;

////-------------------------------------------------------------//
//    std::shared_ptr<Scene> scn = std::make_shared<Scene>();
//    scn->setVisible(true);
//    e.SetScene(std::move(scn));

//    Engine::Run();

  //cin.get();
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
