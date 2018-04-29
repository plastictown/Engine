/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#ifndef SCENELOADER_H_INCLUDED
#define SCENELOADER_H_INCLUDED

#include <iostream>
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
  bool visibility;
  void print() const
  {
    std::cout
        << "posX = " << pos.x << endl
        << "posY = " << pos.y << endl
        << "szX = " << sz.x << endl
        << "szY = " << sz.y << endl
        << "filename = " << file << endl;
  }
  void clear()
  {
    pos= {0.0f,0.0f};
    sz= {0.0f,0.0f};
    file.clear();
    visibility = false;
  }
} img_desc_t;

typedef struct AnimationDescription
{
  Point2f  pos;
  Point2f  sz;
  uint32_t interval;
  std::list<std::string> files;
  bool visibility;
  void print() const
  {
    std::cout
        << "posX = " << pos.x << endl
        << "posY = " << pos.y << endl
        << "szX = " << sz.x << endl
        << "szY = " << sz.y << endl
        << "interval = " << interval << endl
        << "nImages = " << files.size() << endl;
  }
  void clear()
  {
    pos= {0.0f,0.0f};
    sz= {0.0f,0.0f};
    interval = 0u;
    files.clear();
    visibility = false;
  }
} ani_desc_t;

typedef struct SceneDescription
{
  std::string name;
  Point2f pos;
  bool visibility;
  void clear()
  {
    name.clear();
    pos={0.0f,0.0f};
    visibility=false;
  }
}scn_desc_t;

class SceneLoader
{
public:
  bool ParseScene(const std::string& filename);
  const std::list<ImageDescription>&     getImages()     const;
  const std::list<AnimationDescription>& getAnimations() const;
  const SceneDescription& getDescription() const;
protected:
private:
  Config                          m_cfg;
  SceneDescription                m_scndsc;
  std::list<ImageDescription>     m_imgdsc;
  std::list<AnimationDescription> m_anidsc;
};

#endif // SCENELOADER_H_INCLUDED
