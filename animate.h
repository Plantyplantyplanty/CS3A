#define _CRTDBG_MAP_ALLOC

#ifndef GAME_H
#define GAME_H
#include "system.h"
#include "sidebar.h"
#include "fileHandler.h"
#include <fstream>
class animate {
public:
    animate();
    /*Big Three*/
    animate(animate& rhs);
    animate& operator=(const animate& rhs);
    ~animate();

    void run();
    //Runs the program
    void processEvents();
    //Takes in user input and processes it
    void update(); 
    //Calls system's step and updates the mouse pointer
    void render();
    //Clears, draws, and displays the window
    void Draw();
    //Draws the calculator. Takes into account the input and help flags.
private:
    void copy(const animate &rhs);     //For the copy constructor
    Graph_info* _info;
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    bool input;                         //if input is being entered
    bool help;                          //if display "help". First set by sidebar
    Queue<string> oldEq;                //Contains all of the equations entered in this session
    fileHandler f;                      //handles the saving of old equations
    void initializeText();              //Sets all the attributes of the text objects  
    void initializeFuncBox();            //Sets all the attributes of the function box
    string getMyTextLabel();             //Gets the string for the text label 

    void stripSpaces(string& str);      //strips the white spaces from a string

    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    sf::String equationInput;           //The new equation as a set of characters
    sf::Text newEquation;               //The new equation as a string
    sf::Text yequals;                   //holds the string y = 
    sf::Text Help;                      //Holds the help 
    sf::RectangleShape functionBox;      //To draw the function box
};

//Returns the mouse position as a string
string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
