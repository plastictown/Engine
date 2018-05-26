/*
 * https://github.com/plastictown/Engine
 * Copyright (C) 2018  Mikhail Domchenkov
 * agplastictown@yandex.ru
 */

#include <animation.h>
#include <thread>

Animation::Animation( const decltype(interval)& msec)
: interval {msec}
{
  setType(GameObjectType::TypeAnimation);
  this->start();
}

Animation::Animation( const uint32_t msec): interval {std::chrono::milliseconds{msec}}
{
    setType(GameObjectType::TypeAnimation);
  this->start();
}

void Animation::set_interval(const decltype(interval)& msec)
{
  interval = msec;
}

void Animation::AddImage(const Image& img)
{
  images.push_back(img);
  index.set_max(images.size()-1);
  index.set_value(0);
}

void Animation::AddImage(const vector<Image>& v)
{
  for(auto& i:v)
    {
      AddImage(i);
    }
}

const Image& Animation::getCurrentImage() const
{
  if(images.empty())
    throw runtime_error("can't return image: animation is empty!");
  return images[index.get_current()];
}

const Image& Animation::getImage() const
{
  return getCurrentImage();
}

void Animation::run()
{
  index.next();
  std::this_thread::sleep_for(interval);
}

Animation::~Animation()
{
  if(this->running())
    this->stop();
}
