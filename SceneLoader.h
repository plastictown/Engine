#ifndef SCENELOADER_H_INCLUDED
#define SCENELOADER_H_INCLUDED

#include <string>
#include <list>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

class SceneLoader
{
public:
    bool ParseScene(const std::string& filename);
protected:
private:
    Config m_cfg;
};

#endif // SCENELOADER_H_INCLUDED
