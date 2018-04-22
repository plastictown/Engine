/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include "engine.h"


Engine::Engine(int argc, char** argv):
  render(argc, argv)
{
  scene=make_shared<Scene>();
  render.SetScene(scene);
}

void Engine::Run()
{
  Render::run();
}

Image Engine::LoadImage(const string& filename)
{
  Image im;
  if(!im.load(filename))
    throw runtime_error(string("can't load image: ") + filename);
  return im;
}
uint32_t Engine::AddObject(shared_ptr<GameObject>&& obj)
{
  return scene->AddObject(obj);
}

void Engine::RemoveObject(uint32_t key)
{
  scene->RemoveObject(key);
}

void Engine::SetScene(shared_ptr<Scene>&& scn)
{
    scene = std::move(scn);
    render.SetScene(scene);
}
