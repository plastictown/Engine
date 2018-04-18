#include <iostream>
#include "SceneLoader.h"

using namespace std;
using namespace libconfig;

bool SceneLoader::ParseScene(const std::string& filename)
{
    m_cfg.setAutoConvert(true);
  try
    {
      m_cfg.readFile(filename.c_str());
    }
  catch(const FileIOException &fioex)
    {
      cerr << fioex.what() << endl;
      return false;
    }
  catch(const ParseException &pex)
    {
      cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
           << " - " << pex.getError() << std::endl;
      return false;
    }
  auto& root = m_cfg.getRoot();

  //---get static images---//
  try
    {
      ImageDescription desc;
      const char* pstr=nullptr;
      auto& static_images = root["Scene"]["Images"];
      auto cnt = static_images.getLength();
      cout << "there are " << cnt << " static images" << endl;
      if(cnt>=1)
        {
          for(int i=0; i<cnt; i++)
            {
              auto& simg=static_images[i];
              if(simg.lookupValue("posX",desc.pos.x) &&
                  simg.lookupValue("posY",desc.pos.y) &&
                  simg.lookupValue("szW",desc.sz.x) &&
                  simg.lookupValue("szH",desc.sz.y) &&
                  simg.lookupValue("image",pstr))
                {
                  desc.file=string(pstr);
                  m_imgdsc.push_back(desc);
                }
                else
                {
                    cerr << "lookupValue failed!" << endl;
                    return false;
                }
                desc.print();
                desc.clear();
            }
        }
    }
  catch(const SettingNotFoundException &nfex)
    {
      cerr << nfex.what() << endl;
      // static images not found
    }
    //---get animations---//
  try
    {
      AnimationDescription desc;
      const char* pstr=nullptr;
      auto& ani_images = root["Scene"]["Animations"];
      auto cnt = ani_images.getLength();
      if(cnt>=1)
        {
          for(int i=0; i<cnt; i++)
            {
              auto& simg=ani_images[i];
              if(simg.lookupValue("posX",desc.pos.x) &&
                  simg.lookupValue("posY",desc.pos.y) &&
                  simg.lookupValue("szW",desc.sz.x) &&
                  simg.lookupValue("szH",desc.sz.y) &&
                  simg.lookupValue("time", desc.interval))
                {
                  auto& imglist = simg["images"];
                  auto ctr = imglist.getLength();
                  for(int k=0; k<ctr; k++)
                  {
                    pstr = imglist[k];
                    desc.files.emplace_back(string(pstr));
                  }
                  m_anidsc.push_back(desc);
                }
                else
                {
                    cerr << "lookupValue failed!" << endl;
                    return false;
                }
                desc.print();
                desc.clear();
            }
        }
    }
  catch(const SettingNotFoundException &nfex)
    {
      cerr << nfex.what() << endl;
      // animations not found
    }

  return true;
}

const std::list<ImageDescription>& SceneLoader::getImages() const
{
    return m_imgdsc;
}

const std::list<AnimationDescription>& SceneLoader::getAnimations() const
{
    return m_anidsc;
}
