#ifndef _ANIMATION_H_INCLUDED_
#define _ANIMATION_H_INCLUDED_
#include <GL/gl.h>
#include "image.h"
#include <vector>
#include "incremeter.h"
#include "runnable.h"
#include <chrono>


using namespace std;

class Animation: public runnable, public GameObject
{
    vector<Image> images;
    Incrementer<GLuint> index;
    std::chrono::milliseconds interval;
public:
    explicit Animation( const decltype(interval)& m);
    explicit Animation( const uint32_t m);
    void set_interval(const decltype(interval)& m);
    void AddImage(const Image& img);
    void AddImage(const vector<Image>& v);
    const Image& getCurrentImage() const;
    const Image& getImage() const;
    void run();
    ~Animation();
};


#endif // _ANIMATION_H_INCLUDED_
