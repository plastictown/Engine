/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _ENGINE_H_INCLUDED_
#define _ENGINE_H_INCLUDED_

#include <memory>
#include <string>
#include <cstdint>
#include "render.h"
#include "scene.h"

class Engine
{
    Render render;
    shared_ptr<Scene> scene;

    Engine() = delete;
    Engine(const Engine&) = delete;
    Engine& operator = (const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator = (Engine&&) = delete;
public:
    Engine(int argc, char** argv);
    static void Run();
    static Image LoadImage(const string& filename);
    uint32_t AddObject(shared_ptr<GameObject>&& obj);
    void RemoveObject(uint32_t key);
};

#endif // _ENGINE_H_INCLUDED_
