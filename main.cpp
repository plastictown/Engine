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
#include <thread>
#include <vertex.h>
<<<<<<< HEAD
#include <color.h>

=======
>>>>>>> dev
using namespace std;

int main(int argc, char** argv) try {
<<<<<<< HEAD
    color<int, 3> c1 {1, 2, 3};
    color<int, 3> c2 {1, 2, 3};
    auto a1 = c1.getAt(0);
    auto a2 = c1.getAt(1);
    auto a3 = c1.getAt(2);
    cout << std::boolalpha << (c1 == c2) << endl;

    color<float, 2> c3{1.2, 2.3};
    auto b1 = c3.getAt(0);
    auto b2 = c3.getAt(1);


//    vertex<float, 3> v{1, 2, 3};

//    v.setAt(0, 8);

//    std::cout << v.getAt(4) << endl;
=======
    vertex<float, 3> v1{1, 2, 3};
    vertex<float, 3> v2{4, 4, 7};
    vertex<float, 3> v3{1, 2, 3};

    vertex<float, 3> v4(v2);

    std::cout << v1.getAt(2) << " " << (v4 == v2) << endl;;
>>>>>>> dev

//    Engine e(argc, argv);

//    std::shared_ptr<Scene> scn = std::make_shared<Scene>();
//    scn->setVisible(true);
//    e.SetScene(std::move(scn));

//    Engine::Run();

//    cin.get();
    return 0;
} catch(std::exception& e) {
    std::cerr << __FUNCTION__ << ": " << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cerr << __FUNCTION__ << ": unknown exception" << std::endl;
}
