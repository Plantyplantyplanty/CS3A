#define _CRTDBG_MAP_ALLOC
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Graph.h"

using namespace std;

class System
{
public:
    System(Graph_info *info);
    void Step();
    void Draw(sf::RenderWindow& widnow);

private:
    Graph_info* _info;
    Graph _g;
};

#endif // SYSTEM_H
