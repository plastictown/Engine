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
  Render render; /**< render it and in Africa render */
  shared_ptr<Scene> scene; /**< Current scene. Must be replaced by a list of scenes. */

  Engine() = delete;
  Engine(const Engine&) = delete;
  Engine& operator = (const Engine&) = delete;
  Engine(Engine&&) = delete;
  Engine& operator = (Engine&&) = delete;
public:
  /** @brief Constructs new Engine object
   * @param [in] argc - argc parameter from main()
   * @param [in] argv - argv parameter from main()
   * @remarks The Engine object must be created
   * before any OpenGL function can be called.
   */
  Engine(int argc, char** argv);
  /** @brief Start program cycle by
   * glutMainLoop() call
   * @see Render
   */
  static void Run();
  /** @brief Load image from the file.
   * Only PNG images supported now.
   * @param [in] filename - A relative or
   * absolute path to the file
   * @return new Image object
   * @see Image
   * @see SceneLoader
   */
  static Image LoadImage(const string& filename);
/** @brief Add new GameObject into current
 * scene.
 * @param [in] obj - pointer to any GameObject such as
 * Image or Animation.
 * @return new scene object id.
 * @see Scene
 * @see Image
 * @see Animation
 * @see GameObject
 * @see RemoveObject
 */
  uint32_t AddObject(shared_ptr<GameObject>&& obj);
  /** @brief Remove object from current scene
   * @param [in] key - id of object to be removed
   * @see AddObject
   */
  void RemoveObject(uint32_t key);
  /** @brief Set or replace current scene
   * @param [in] scn - new Scene pointer
   * @see Render
   */
  void SetScene(shared_ptr<Scene>&& scn);
};

#endif // _ENGINE_H_INCLUDED_
