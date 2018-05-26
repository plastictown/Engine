/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#ifndef _ANIMATION_H_INCLUDED_
#define _ANIMATION_H_INCLUDED_
#include <GL/gl.h>
#include <image.h>
#include <vector>
#include <incremeter.h>
#include <runnable.h>
#include <chrono>

using namespace std;

/**
 * @class Animation
 * @brief Contain a set of images and change it
 * in cycle with specified interval
 */
class Animation: public runnable, public GameObject
{
  vector<Image> images;               /**< images to draw */
  Incrementer<GLuint> index;          /**< current image index */
  std::chrono::milliseconds interval; /**< interval between image changing */
public:
  /** @brief Construct new Animation object
   * @param [in] msec - interval between images
   * in milliseconds of type std::chrono::milliseconds
   * @remarks Animation ctor also starts animation
   * thread
   * @see Animation
   * @see set_interval
   */
  explicit Animation( const decltype(interval)& msec);
  /** @brief Construct new Animation object
     * @param [in] msec - interval between images
     * in milliseconds of type uint32_t
     * @remarks Animation ctor also starts animation
     * thread
     * @see Animation
     * @see set_interval
     */
  explicit Animation( const uint32_t msec);
  /** @brief Set new intervalbetween images
     * @param [in] msec - new interval value
     * in milliseconds of type std::chrono::milliseconds
     */
  void set_interval(const decltype(interval)& msec);
  /**
   * @brief Add new Image into Animation
   * @param [in] img - Image object to be
   * inserted in Animation.
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
  /** @brief Destructor. Stops and destroys
   * thread object and images.
   */
  ~Animation();
};

#endif // _ANIMATION_H_INCLUDED_
