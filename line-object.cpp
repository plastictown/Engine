#include "line-object.h"
#include "render.h"

LineObject::LineObject() : Drawable(), a{}, b{}, color{} {
  setType("line2f");
}

LineObject::LineObject(const Point2f& p1, const Point2f& p2, const Color4& c)
    : Drawable(), a(p1), b(p2), color(c) {
  setType("line2f");
}

LineObject::LineObject(const LineObject& rhs) : Drawable() {
  if (this == &rhs)
    return;
  setType("line2f");
  a = rhs.a;
  b = rhs.b;
  color = rhs.color;
}

LineObject::~LineObject() {}

LineObject& LineObject::operator=(const LineObject& rhs) {
  if (this == &rhs)
    return *this;
  setType(rhs.type);
  a = rhs.a;
  b = rhs.b;
  color = rhs.color;
  return *this;
}
LineObject& LineObject::operator=(LineObject&& rhs) {
  type = std::move(rhs.type);
  a = rhs.a;
  b = rhs.b;
  color = rhs.color;
  return *this;
}

bool LineObject::operator==(const LineObject& rhs) const noexcept {
  if (this == &rhs)
    return true;
  return (a == rhs.a) && (b == rhs.b) && (color == rhs.color);
}

const Point2f& LineObject::getA() const noexcept {
  return a;
}

void LineObject::setA(const Point2f& value) noexcept {
  a = value;
}

const Point2f& LineObject::getB() const noexcept {
  return b;
}

void LineObject::setB(const Point2f& value) noexcept {
  b = value;
}

const Color4& LineObject::getColor() const noexcept {
  return color;
}

void LineObject::setColor(const Color4& value) noexcept {
  color = value;
}

void LineObject::draw() {
  Render::DrawObject(*this);
}
