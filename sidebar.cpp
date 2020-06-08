#include "sidebar.h"
#include "constants.h"

const double VERTICAL_LINE_SPACING = 5.0;
const double LEFT_MARGIN = 10.0;


Sidebar::Sidebar(float left, float width, Graph_info *info, bool * help):_left(left), _width(width), _info(info), _help(help){
    cout<<"Sidebar CTOR: TOP"<<endl;

    initializeRect(left, width);

    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;
    cout<<"Sidebar CTOR: Text object initialized."<<endl;

    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    for (int i = 0; i < 4; i++) {
        items.push_back("");
    }

    /*READ FROM TEXT FILE*/
    info->equation = readFromFile();

    items.push_back(""); 
    items.push_back("_______");
    items.push_back("EQUATION HISTORY");
    items.push_back("");
    items.push_back("--------");
    items.push_back("HELP: H");
    items.push_back("");
    items.push_back("--------");

    items[SB_MOUSE_CLICKED] = "MOUSE CLICK";
    items[SB_KEY_PRESSED] = "KEY PRESS";
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::initializeRect(float left, float width) {
    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(105, 105, 105)); //(192,192,192)); //silver
    rect.setOutlineColor(sf::Color(52, 216, 235));
    rect.setOutlineThickness(2);
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
}

string Sidebar::readFromFile() {
    old_eq.open("old_equation.txt");
    //Pushes in all the old equations
    string line = "";
    string eq = ""; /*gets the actual function string*/
    bool empty = true; //checks if the files is empty
    if (old_eq.is_open()) {
        while (getline(old_eq, line))
        {
            empty = false;
            items.push_back(line);
            if (line != "\n" && line != "") {
                eq = line;
            }

            if (items.size() > VECTOR_CAP) {
                items.erase(items.begin()+4);
            }
        }
        if (empty) {
            *_help = true; //shows the help automatically
            eq = "sin(x)"; //will show sin(x)
        }
        old_eq.close();
        *_help = false;
    }
    else {
        cout << "Unable to load old equations \n";
        *_help = true; //showi the help automatically
        eq = "sin(x)"; //will show sin(x)
    }
    return eq;
}

void Sidebar::draw(sf::RenderWindow& window){
    window.draw(rect);
    float height = 10;
    bool start_pushback = false; //only want equations being pushed back
    equations.clear();

    //For the mouseclick, etc
    for (vector<string>::iterator it = items.begin(); it != items.begin() + 3; it++) {
        readItems(window, it, height, start_pushback);
    }
    //For the equations
    for (vector<string>::iterator it = items.end() - 1; it != items.begin() + 4; it--) {
        readItems(window, it, height, start_pushback);
    }
}

void Sidebar::readItems(sf::RenderWindow& window, vector<string>::iterator it, float& height, bool& start_pushback) {
    bool blank = false;
    if (strlen(it->c_str()) == 0) {
        //empty rows must be taken into account (getLocalBounds())
        //    but not drawn
        blank = true;
        sb_text.setString("BLANK");
    }
    else {
        sb_text.setString(it->c_str());
    }
    sb_text.setPosition(sf::Vector2f(_left + LEFT_MARGIN, height));
    height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;
    if (!blank) {
        sf::Text new_text = sb_text;
        if (*it == "_______") {
            start_pushback = true; //We've pushed back the deliminator string, all that
                                   //is left is equations
        }
        else if (start_pushback) {
            //we do not want these to go at the same time!! otherwise we'll get the 
            //deliminator string
            equations.push_back(sb_text);
        }
        window.draw(sb_text);
    }
}

string Sidebar::clickText(sf::Vector2f mouse) {
    string equation = "";
    for (vector<sf::Text>::iterator it = equations.begin(); it != equations.end(); it++) {
           if (it->getGlobalBounds().contains(mouse)) {
               equation = string(it->getString());
           }
    }

    return equation;
}

string Sidebar::rightClickText(sf::Vector2f mouse) {
    string equation = "";
    for (vector<sf::Text>::iterator it = equations.begin(); it != equations.end(); it++) {
        if (it->getGlobalBounds().contains(mouse)) {
            equation = string(it->getString());
            
            //Erase equation from items
            for (vector<string>::iterator it = items.begin(); it != items.end(); it++) {
                if (*it == equation) {
                    items.erase(it);
                    break;
                }          
            }
        }
    }

    return equation;
}

string& Sidebar::operator [](int index){
    return items[index];
}

void Sidebar::push_back(string str) {
    items.insert(items.end() - 8, str);
}