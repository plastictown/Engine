#ifndef _GAME_OBJECT_H_INCLUDED_
#define _GAME_OBJECT_H_INCLUDED_

#include "point2f.h"
#include "rectf.h"

class Image;

class GameObject
{
public:
    virtual const Image& getImage() const = 0;
    void setPosition(const Point2f& position)
    {
        pos = position;
    }
    const Point2f& getPosition() const
    {
        return pos;
    }
    virtual ~GameObject() {}
protected:
    Point2f pos;
};

#endif // _GAME_OBJECT_H_INCLUDED_
