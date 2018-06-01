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
#include <rect2f.h>

using namespace std;

int main(int argc, char** argv) try {
    Engine e(argc, argv);
  vertex2f v{100,100};
  rect2f r{v,v,vertex2f{22,33},v};
  std::cout << r[2].getY() << std::endl;
//-------------------------------------------------------------//
    std::shared_ptr<Scene> scn = std::make_shared<Scene>();
    scn->setVisible(true);
    e.SetScene(std::move(scn));

    Engine::Run();

    //cin.get();
    return 0;
} catch(std::exception& e) {
    std::cerr << __FUNCTION__ << ": " << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cerr << __FUNCTION__ << ": unknown exception" << std::endl;
}
