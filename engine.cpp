#include "engine.h"


Engine::Engine(int argc, char** argv):
    render(argc, argv)
{
    // TODO:can throw bad_alloc!!!
    scene.reset(new Scene);
    render.SetScene(scene);
}

void Engine::Run()
{
    Render::run();
}

Image Engine::LoadImage(const string& filename)
{
    Image im;
    if(!im.load(filename))
        throw runtime_error(string("can't load image: ") + filename);
    return im;
}

uint32_t Engine::AddObject(Image& img)
{
    shared_ptr<GameObject> image(&img);
    return scene->AddObject(image);
}

uint32_t Engine::AddObject(Animation& a)
{
    shared_ptr<GameObject> animation(&a);
    return scene->AddObject(animation);
}

void Engine::RemoveObject(uint32_t key)
{
    scene->RemoveObject(key);
}
