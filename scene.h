/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _SCENE_H_INCLUDED_
#define _SCENE_H_INCLUDED_

#include <map>
#include <memory>
#include <cstdint>
#include <utility>

#include "animation.h"
#include "image.h"
#include "game-object.h"
#include "incremeter.h"
#include "SceneLoader.h"

using namespace std;

class Scene
{
  Incrementer<uint32_t> gen_id;
  std::map<uint32_t, std::shared_ptr<GameObject>> objects;
  SceneLoader m_loader;
  bool m_visible; //scene visiblity
public:
  Scene();
  // returns new object id
  uint32_t AddObject(std::shared_ptr<GameObject>& obj);
  void RemoveObject(uint32_t key);
  std::shared_ptr<GameObject> GetObject(uint32_t key);
  void Draw();
  size_t Count() const;
  bool FromFile(const std::string& filename);
  void print() const;
  void setVisible(bool state) noexcept;
  bool isVisible() const noexcept;
};

#endif // _SCENE_H_INCLUDED_
