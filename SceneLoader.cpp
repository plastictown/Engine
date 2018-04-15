#include <iostream>
#include "SceneLoader.h"

using namespace std;
using namespace libconfig;

bool SceneLoader::ParseScene(const std::string& filename)
{
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
    }
    return true;
}
