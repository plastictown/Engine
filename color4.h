/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef _COLOR4_H_
#define _COLOR4_H_
#include <GL/gl.h>

/** @struct Color4
 * @brief Contain color in RGBA
 * format.
 */
struct Color4 {
  /** @brief Default constructor
   */
  Color4();
  /** @brief Copy constructor
   * @param [in] other - Color4 object to be copied
   */
  Color4(const Color4& other);
  /** @brief Constructs new Color4 object with
   * specified RGBA value
   * @param [in] _r - red component value
   * @param [in] _g - green component value
   * @param [in] _b - blue component value
   * @param [in] _a - alpha component value
   */
  Color4(float _r, float _g, float _b, float _a = 1.0f)
      : r(_r), g(_g), b(_b), a(_a) {}
  /** @brief Сopy assignment operator
  * @param [in] other - Color4 object to be copied
  * @return reference to current Color4 object
  */
  Color4& operator=(const Color4& other);
  bool operator==(const Color4& rhs) const noexcept;

  GLfloat r; /**< red component value */
  GLfloat g; /**< green component value */
  GLfloat b; /**< blue component value */
  GLfloat a; /**< alpha component value */
};

#endif  // _COLOR4_H_
