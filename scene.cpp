#include "scene.h"
#include "render.h"
//#include <iostream>

using namespace std;

Scene::Scene()
{
}

uint32_t Scene::AddObject(shared_ptr<GameObject>& obj)
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

shared_ptr<GameObject> Scene::GetObject(uint32_t key)
{
    auto ptr = objects.find(key);
    if(ptr != objects.cend())
        return objects[key];
    return nullptr;
}

void Scene::Draw()
{
    for(auto& o:objects)
        {
            Render::DrawImage(o.second->getImage(), o.second->getPosition());
        }
}

size_t Scene::Count() const
{
    return objects.size();
}
