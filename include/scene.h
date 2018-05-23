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

#include <animation.h>
#include <image.h>
#include <game-object.h>
#include <incremeter.h>
#include <SceneLoader.h>

using namespace std;

class Scene
{
  /// id generator for Scene objects
  Incrementer<uint32_t> gen_id;
  std::map<uint32_t, std::shared_ptr<GameObject>> objects;
  /// scene file reader
  SceneLoader m_loader;
  /// scene visibility
  bool m_visibility;
public:
  /**
   * @brief Default constructor
   */
  Scene();
  /**
   * @brief Add new GameObject into Scene
   * @param[in] obj - pointer to the object
   * @return new object id
   * @see RemoveObject
   * @see Count
   */
  uint32_t AddObject(std::shared_ptr<GameObject>& obj);
  /**
   * @brief Removes GameObject from the Scene
   * @param[in] key - object id
   * @see AddObject
   * @see Count
   */
  void RemoveObject(uint32_t key);
  /**
   * @brief Returns GameObject by the key
   * @param[in] key - object id
   * @return pointer to the object or
   * nullptr if no such object in the scene
   */
  std::shared_ptr<GameObject> GetObject(uint32_t key);
  /**
   * @brief Draw current scene
   */
  void Draw();
  /**
   * @brief Returns the number of objects in the scene
   * @return a value of type size_t:
   * the number of objects in the scene
   * @see AddObject
   * @see RemoveObject
   */
  size_t Count() const;

  bool FromFile(const std::string& filename);
  void print() const;
  void setVisible(bool state) noexcept;
  bool isVisible() const noexcept;
};

#endif // _SCENE_H_INCLUDED_
