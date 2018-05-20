/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 */

#include <memory>
#include <cmath>
#include "image.h"
#include "scene.h"
#include "render.h"
#include "point-object.h"

using namespace std;

Scene::Scene()
:m_visibility {false}
{
}

uint32_t Scene::AddObject(std::shared_ptr<GameObject>& obj)
{
  uint32_t id = gen_id.get_next();
  objects.insert(std::make_pair(id, obj));
  return id;
}

void Scene::RemoveObject(uint32_t key)
{
  auto ptr = objects.find(key);
  if(ptr != objects.cend())
    objects.erase(ptr);
}

std::shared_ptr<GameObject> Scene::GetObject(uint32_t key)
{
  auto ptr = objects.find(key);
  if(ptr != objects.cend())
    return objects[key];
  return nullptr;
}

void Scene::Draw()
{
  /*
  for(auto& o:objects)
    {
      if(!o.second->isVisible())
	continue;
      switch(o.second->getType())
        {
        case GameObjectType::TypeImage:
        {
          auto ptr = std::static_pointer_cast<Image>(o.second);
          Render::DrawImage(ptr->getImage(), ptr->getPosition());
          break;
        }
        case GameObjectType::TypeAnimation:
        {
          auto ptr = std::static_pointer_cast<Animation>(o.second);
          Render::DrawImage(ptr->getImage(), ptr->getPosition());
          break;
        }

        }
    }
    */

/*
    glBegin(GL_POINTS);
      glColor4f(0.0f,0.0f,0.0f,1.0f);
      glVertex2f(100.0f,100.0f);
    glEnd();
*/

  glPointSize(4.0f);
  static float delta_x = 0;	
  for(float i= 0.0f;i<640;i+=1.0f){
 	PointObject po(Point2f{i, 240+sin((i+delta_x)/100)*200}, Color4{1,0,0,1});
	po.draw();
	delta_x += 0.01f;
	}

}

size_t Scene::Count() const
{
  return objects.size();
}

bool Scene::FromFile(const std::string& filename)try
  {
    auto rv = m_loader.ParseScene(filename);
    if(!rv)
      {
        cerr
            << __FUNCTION__
            << ": "
            << "can't load scene from file"
            << endl;
        return false;
      }
    auto& images = m_loader.getImages();
    auto& animations = m_loader.getAnimations();
    auto& description = m_loader.getDescription();
    this->setVisible(description.visibility);

    for(auto& img:images)
      {
        std::shared_ptr<GameObject> im = make_shared<Image>();
        im->setVisible(img.visibility);
        auto pi = std::static_pointer_cast<Image>(im);
        if(!pi->load(img.file))
          throw runtime_error(string("can't load image: ") + img.file);
        pi->setPosition(img.pos);
        this->AddObject(im);
      } // for all images

    for (auto& ani:animations)
      {
        std::shared_ptr<GameObject> a = make_shared<Animation>(ani.interval);
        a->setVisible(ani.visibility);
        auto pa = std::static_pointer_cast<Animation>(a);
        for(auto& f:ani.files)
          {
            Image im;
            if(!im.load(f))
              throw runtime_error(string("can't load image: ") + f);
            pa->AddImage(im);
          }
        pa->setPosition(ani.pos);
        this->AddObject(a);
      } // for all animations

    return true;
  } // Scene::FromFile()
catch(const std::exception& e)
  {
    cerr
        << "Scene::FromFile failed: "
        << e.what()
        << endl;
    return false;
  }

void Scene::print() const
{
  cout
      << __FUNCTION__
      << ": there are "
      << objects.size()
      << " objects in scene"
      << endl;
}

void Scene::setVisible(bool state) noexcept
    {
  m_visibility = state;
    }
bool Scene::isVisible() const noexcept
    {
      return m_visibility;
    }
