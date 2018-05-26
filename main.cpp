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
#include <color.h>

using namespace std;

int main(int argc, char** argv) try {
    Engine e(argc, argv);

    vertex2f v{1,5};
    vertex2f vv(2,3);

    cout << v.data()[1] << endl;

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
