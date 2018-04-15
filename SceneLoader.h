#ifndef SCENELOADER_H_INCLUDED
#define SCENELOADER_H_INCLUDED

#include <string>
#include <list>
#include <cstdint>
#include "point2f.h"
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

typedef struct ImageDescription
{
    Point2f     pos;
    Point2f     sz;
    std::string file;
    void print() const
    {
      std::cout
      << "posX = " << pos.x << endl
      << "posY = " << pos.y << endl
      << "szX = " << sz.x << endl
      << "szY = " << sz.y << endl
      << "filename = " << file << endl;
    }
} img_desc_t;

typedef struct AnimationDescription
{
    Point2f  pos;
    Point2f  sz;
    uint32_t interval;
    std::list<std::string> files;
    void print() const
    {
      std::cout
      << "posX = " << pos.x << endl
      << "posY = " << pos.y << endl
      << "szX = " << sz.x << endl
      << "szY = " << sz.y << endl
      << "nImages = " << files.size() << endl;
    }
} ani_desc_t;

class SceneLoader
{
public:
    bool ParseScene(const std::string& filename);
protected:
private:
    Config m_cfg;
    std::list<ImageDescription>     m_imgdsc;
    std::list<AnimationDescription> m_anidsc;
};

#endif // SCENELOADER_H_INCLUDED
