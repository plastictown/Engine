#ifndef _COLOR4_H_
#define _COLOR4_H_
#include <GL/gl.h>

struct Color4
{
    Color4();
    Color4(const Color4& other);
    Color4(float _r, float _g, float _b, float _a):
        r(_r), g(_g), b(_b), a(_a) {};
    Color4& operator=(const Color4& other);

    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
};

#endif // _COLOR4_H_
