/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _ANIMATION_H_INCLUDED_
#define _ANIMATION_H_INCLUDED_
#include <GL/gl.h>
#include "image.h"
#include <vector>
#include "incremeter.h"
#include "runnable.h"
#include <chrono>

using namespace std;

/**
 * @class Animation
 * @brief Contain a set of images and change it
 * in cycle with specified interval
 */
class Animation: public runnable, public GameObject
{
    /**< images to draw */
  vector<Image> images;
    /**< current image index */
  Incrementer<GLuint> index;
    /**< interval between image changing */
  std::chrono::milliseconds interval;
public:
  explicit Animation( const decltype(interval)& m);
  explicit Animation( const uint32_t m);
  void set_interval(const decltype(interval)& m);
  /**
   * @brief Add new Image into Animation
   * @see Image
   * @see AddImage
   */
  void AddImage(const Image& img);
  /**
   * @brief Add vector of Images into Animation
   * @param [in] v - vector of Image objects.
   * @see Image
   * @see AddImage
   */
  void AddImage(const vector<Image>& v); //TODO: make same && method
  /**
   * @brief Get current displayed image
   * @return Current Image object
   * @see Image
   * @see Incrementer
   */
  const Image& getCurrentImage() const;
  /**
   * @brief Alias for getCurrentImage()
   * @return Current Image object
   * @see Image
   * @see Incrementer
   * @see getCurrentImage
   */
  const Image& getImage() const;
   /**
   * @brief Animation thread procedure.
   * Changes Image id with specified interval
   * @see runnable
   * @remarks runnable thread calls this method
   * in the while cycle.
   */
  void run();
  ~Animation();
};


#endif // _ANIMATION_H_INCLUDED_
