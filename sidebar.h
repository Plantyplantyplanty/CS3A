#define _CRTDBG_MAP_ALLOC
#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Stack.h"
#include "Graph_info.h"

using namespace std;


class Sidebar
{
public:
    Sidebar(float left, float width, Graph_info *info, bool * help);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
    string clickText(sf::Vector2f mouse);
    string rightClickText(sf::Vector2f mouse);
    void push_back(string str);

private:
    void initializeRect(float left, float width);//initializes the sidebar rectangle
    void readItems(sf::RenderWindow& window, vector<string>::iterator it, float &height, bool &start_pushback);
    string readFromFile();              //reads from the equation file initially

    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    vector<sf::Text> equations;
    float _left;
    float _width;
    ifstream old_eq;
    Graph_info * _info;
    bool* _help;                        //pointer from animate-used to set help
};

#endif // SIDEBAR_H
