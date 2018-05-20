#ifndef __LINE_OBJECT_H__
#define __LINE_OBJECT_H__

#include "color4.h"
#include "drawable.h"
#include "point2f.h"

class LineObject : public Drawable {
 public:
  LineObject();
  LineObject(const Point2f& p1, const Point2f& p2, const Color4& color);
  LineObject(const LineObject& rhs);
  ~LineObject();
  LineObject& operator=(const LineObject& rhs);
  LineObject& operator=(LineObject&& rhs);
  bool operator==(const LineObject& rhs) const noexcept;

  const Point2f& getA() const noexcept;
  void setA(const Point2f& value) noexcept;

  const Point2f& getB() const noexcept;
  void setB(const Point2f& value) noexcept;

  const Color4& getColor() const noexcept;
  void setColor(const Color4& value) noexcept;

  void draw();

 private:
  Point2f a;
  Point2f b;
  Color4 color;
};

#endif  //__LINE_OBJECT_H__
