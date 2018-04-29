/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <iostream>
#include "SceneLoader.h"

using namespace std;
using namespace libconfig;

bool
SceneLoader::ParseScene (const std::string& filename)
{
  m_cfg.setAutoConvert (true);
  try
    {
      m_cfg.readFile (filename.c_str ());
    }
  catch (const FileIOException &fioex)
    {
      cerr << fioex.what () << endl;
      return false;
    }
  catch (const ParseException &pex)
    {
      cerr << "Parse error at " << pex.getFile () << ":" << pex.getLine ()
	  << " - " << pex.getError () << std::endl;
      return false;
    }
  auto& root = m_cfg.getRoot ();
  if(!m_cfg.exists("Scene"))
    {
      std::cerr
        << __FUNCTION__
        << ": Scene block not found"
        << std::endl;
      return false;
    }
  auto& scene_cfg=root["Scene"];
  if(scene_cfg.exists("visibility"))
    {
      scene_cfg.lookupValue("visibility", m_scndsc.visibility);
    }

  //---get static images---//
  try
    {
      ImageDescription desc;
      const char* pstr = nullptr;
      auto& static_images = root["Scene"]["Images"];
      auto cnt = static_images.getLength ();
      cout << "there are " << cnt << " static images" << endl;
      if (cnt >= 1)
	{
	  for (int i = 0; i < cnt; i++)
	    {
	      desc.clear ();
	      auto& simg = static_images[i];
	      try
		{
		  if (simg.exists ("position"))
		    {
		      auto& pos = simg["position"];
		      if (pos.exists ("x"))
			pos.lookupValue ("x", desc.pos.x);
		      if (pos.exists ("y"))
			pos.lookupValue ("y", desc.pos.y);
		    }

		  if (simg.exists ("size"))
		    {
		      auto& size = simg["size"];
		      if (size.exists ("w"))
			size.lookupValue ("w", desc.sz.x);
		      if (size.exists ("h"))
			size.lookupValue ("h", desc.sz.y);
		    }

		  if (simg.exists ("visibility"))
		    {
		      simg.lookupValue("visibility", desc.visibility);
		    }
		  // image - required field
		  simg.lookupValue ("image", pstr);
		  desc.file = string (pstr);
		  m_imgdsc.push_back (desc);
		}
	      catch (...)
		{
		  cerr << "static images: lookupValue failed!" << endl;
		  return false;
		}
	      desc.print ();
	    }
	}
    }
  catch (const SettingNotFoundException &nfex)
    {
      cerr << nfex.what () << endl;
      // static images not found
    }
  //---get animations---//
  try
    {
      AnimationDescription desc;
      const char* pstr = nullptr;
      auto& ani_images = root["Scene"]["Animations"];
      auto cnt = ani_images.getLength ();
      if (cnt >= 1)
	{
	  for (int i = 0; i < cnt; i++)
	    {
	      desc.clear ();
	      auto& simg = ani_images[i];

	      try
		{
		  if (simg.exists ("position"))
		    {
		      auto& pos = simg["position"];
		      if (pos.exists ("x"))
			pos.lookupValue ("x", desc.pos.x);
		      if (pos.exists ("y"))
			pos.lookupValue ("y", desc.pos.y);
		    }

		  if (simg.exists ("size"))
		    {
		      auto& size = simg["size"];
		      if (size.exists ("w"))
			size.lookupValue ("w", desc.sz.x);
		      if (size.exists ("h"))
			size.lookupValue ("h", desc.sz.y);
		    }

		  if (simg.exists ("visibility"))
		    {
		      simg.lookupValue("visibility", desc.visibility);
		    }

		  // time and images - required fields
		  simg.lookupValue ("time", desc.interval);
		  auto& imglist = simg["images"];
		  auto ctr = imglist.getLength ();
		  for (int k = 0; k < ctr; k++)
		    {
		      pstr = imglist[k];
		      desc.files.emplace_back (std::string (pstr));
		    }
		  m_anidsc.push_back (desc);
		}
	      catch (...)
		{
		  cerr << "animations: lookupValue failed!" << endl;
		  return false;
		}
	      desc.print ();
	    }
	}
    }
  catch (const SettingNotFoundException &nfex)
    {
      cerr << nfex.what () << endl;
      // animations not found
    }
  catch (std::exception& e)
  {
    std::cerr
      << __FUNCTION__
      << ": "
      << e.what()
      << std::endl;
  }

  return true;
}

const std::list<ImageDescription>&
SceneLoader::getImages () const
{
  return m_imgdsc;
}

const std::list<AnimationDescription>&
SceneLoader::getAnimations () const
{
  return m_anidsc;
}

const SceneDescription& SceneLoader::getDescription() const
{
  return m_scndsc;
}
