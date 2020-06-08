#include "animate.h"
#include "constants.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
#include "system.h"

/*Instantiates the lower classes and creates the funtion box/mousepoint/various text objects
for display*/
animate::animate():system(_info = new Graph_info()), sidebar(WORK_PANEL, SIDE_BAR, _info, &help){
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.

    
    mouseIn = true;
    input = false; //We are not taking in input at this time
    window.setFramerateLimit(60);

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Game CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    initializeFuncBox(); //Initialize the function box
    initializeText(); //Initializes all of the text to their initial strings,
                      //their positions, and their color
    cout << "animate instantiated successfully." << endl;
}

/*Initializes the text objects to their default values. Only called by the constructor.*/
void animate::initializeText() {
    myTextLabel = sf::Text(_info->equation, font);
    myTextLabel.setCharacterSize(40);
    //Sets this to the same blue as the line on the sidebar
    myTextLabel.setFillColor(sf::Color(52, 216, 235));
    //SCREEN_HEIGHT - myTextLabel.getLocalBounds().height puts this at the bottom of the 
    //screen. The -80 keeps it visible.
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 80));

    yequals = sf::Text("y = ", font);
    yequals.setCharacterSize(30);
    yequals.setStyle(sf::Text::Bold);
    //Sets it a little over from the edge of the screen
    yequals.setPosition(sf::Vector2f(10, 12)); 
    //Same color as the sidebar
    yequals.setFillColor(sf::Color(105, 105, 105));
    yequals.setOutlineColor(sf::Color(105, 105, 105));

    newEquation = sf::Text("", font);
    newEquation.setCharacterSize(30);
    //10 + the width of the text is the x value
    newEquation.setPosition(sf::Vector2f(10 + yequals.getLocalBounds().width, 12));
    newEquation.setFillColor(sf::Color::Black);
    newEquation.setOutlineColor(sf::Color::Black);

    Help = sf::Text("New Eq : f then Enter\nReset zoom: r\nZoom out: Tab\nZoom in: Backspace\nPan: Arrow Keys\nLeft Click Eq to view\nRight Click Eq to delete\nStop Help: h", font);
    Help.setCharacterSize(30);
    Help.setFillColor(sf::Color::White);
    Help.setOutlineColor(sf::Color::White);
}
void animate::initializeFuncBox() {
    //want this in the first quadrant
    functionBox.setSize(sf::Vector2f(WORK_PANEL / 2 - 20, 60));
    functionBox.setOutlineThickness(5);
    functionBox.setFillColor(sf::Color::White);
    //Same blue as sidebar line
    functionBox.setOutlineColor(sf::Color(52, 216, 235));
    functionBox.setPosition(sf::Vector2f(10, 10));
}

animate::animate(animate& rhs):system(_info = new Graph_info()), sidebar(WORK_PANEL, SIDE_BAR, _info, &help) {
    copy(rhs);
    /*Sets the graph_info objects equal.*/
    _info->domain = rhs._info->domain;
    _info->equation = rhs._info->equation;
    _info->origin = rhs._info->origin;
    _info->points  = rhs._info->points;
    _info->scale = rhs._info->scale;
    _info->window_dimensions = rhs._info->window_dimensions;
}

/*I'm a little leary about deleting graph_info due to how it is linked with the other 
classes. I instead reset the values.*/
animate& animate::operator=(const animate& rhs) {
    copy(rhs);
    _info->domain = rhs._info->domain;
    _info->equation = rhs._info->equation;
    _info->origin = rhs._info->origin;
    _info->points = rhs._info->points;
    _info->scale = rhs._info->scale;
    _info->window_dimensions = rhs._info->window_dimensions;
    return *this;
}

void animate::copy(const animate &rhs){
    //Sets all non-dynamic variables possible equal
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    mousePoint = rhs.mousePoint;         //The little red dot
    system = rhs.system;                      //container for all the animated objects                        //command to send to system
    mouseIn = rhs.mouseIn;                       //mouse is in the screen
    input = rhs.input;                         //if input is being entered
    help = rhs.input;                          //if display "help"
    oldEq = rhs.oldEq;                //Contains all of the equations entered in this session

    font = font;                      //font to draw on main screen
    myTextLabel = rhs.myTextLabel;               //text to draw on main screen
    equationInput = rhs.equationInput;           //The new equation as a set of characters
    newEquation = rhs.newEquation;               //The new equation as a string
    yequals = rhs.yequals;                   //holds the string y = 
    Help = rhs.Help;                      //Holds the help 
    functionBox = rhs.functionBox;      //To draw the function box
}

/*Draws the window, taking into account flags*/
void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);
    
    myTextLabel.setString(getMyTextLabel()); //outputs the equation and domain
    window.draw(myTextLabel);

    if (input) { //If input flag is set, draw the new equation as it is and the input prompt
        window.draw(functionBox);
        window.draw(yequals);
        window.draw(newEquation);
        //window.draw(newEquation);
    }
    if (help) { //If help flag is set, draw the help
        window.draw(Help);
    }
    //. . . . . . . . . . . . . . . . . . .
}

/*Steps system and draws the mouse's red dot*/
void animate::update(){
    //cause changes to the data for the next frame
    system.Step();
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}

/*Re-draws the window*/
void animate::render(){
       window.clear();
       Draw();
       window.display();
}


/*Takes in user input and processes it*/
void animate::processEvents()
{
   
   double to_scale = (_info->domain.y - _info->domain.x) * .07; //the amount to scale by
   sf::Event event; 
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type){
           
           // window closed
           case sf::Event::Closed:
               window.close();
               break;
           case sf::Event::TextEntered: //Enter text
               if (event.text.unicode == '\b' && input) { //backspace
                   if (equationInput.getSize() > 0) {
                       equationInput.erase(equationInput.getSize() - 1, 1);
                       newEquation.setString(equationInput);
                   }
               } //Only activates if input flag is set
               else if (event.text.unicode < 128 && input) { //text input
                   equationInput += event.text.unicode;
                   newEquation.setString(equationInput);        
               }
               break;
           // key pressed
           case sf::Event::KeyPressed:

               switch (event.key.code) {
                   /*
               OLD KEYBOARD INPUT: Kept in case of debug needs
               case sf::Keyboard::LShift:
                   sidebar[SB_KEY_PRESSED] = _info->equation;
                   if (old_equations.is_open()) {
                       old_equations << _info->equation << endl;
                   }
                   window.clear();
                   cout << "Equation: y = ";
                   _info->reset();
                   getline(cin, _info->equation);
                   break;*/
               case sf::Keyboard::Enter: //For entering in an equation
                   sidebar[SB_KEY_PRESSED] = "ENTER KEY";
                   if (input) {
                       input = false; //stop the flag
                       string old_equation = _info->equation;
                       stripSpaces(old_equation);
                       sidebar.push_back(old_equation);
                       _info->reset(); //reset the zoom
                       oldEq.push(old_equation); //push the equation into the stack to be 
                                                    //written                       
                       _info->equation = string(newEquation.getString()); //reset equation
                       newEquation.setString("");
                       equationInput.clear();
                   }
                   break;
               case sf::Keyboard::Tab: //Zooms out
                    sidebar[SB_KEY_PRESSED] = "TAB";
                   _info->domain.x -= to_scale;
                   _info->domain.y += to_scale;
                   _info->scale.x = _info->reset_x_scale();
                   _info->origin.y = -(_info->domain.x) * _info->scale.x;
                   break;
               case sf::Keyboard::Backspace: //zooms in if input is not activated
                   sidebar[SB_KEY_PRESSED] = "BACKSPACE";
                   if(!input){
                       _info->domain.x += to_scale;
                       _info->domain.y -= to_scale;
                       _info->scale.x = _info->reset_x_scale();
                       _info->origin.y = -(_info->domain.x) * _info->scale.x;
                   }
                   break; /*Panning*/
               case sf::Keyboard::Left:
                    sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                   _info->domain.x -= to_scale;
                   _info->domain.y -= to_scale;
                   _info->scale.x = _info->reset_x_scale();
                   _info->origin.y += to_scale * _info->scale.x;
                   break;
               case sf::Keyboard::Right:
                    sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   _info->domain.x += to_scale;
                   _info->domain.y += to_scale;
                   _info->scale.x = _info->reset_x_scale();
                   _info->origin.y -= to_scale * _info->scale.x;
                   break;
               case sf::Keyboard::Up:
                    sidebar[SB_KEY_PRESSED] = "UP ARROW";
                   _info->origin.x += to_scale * _info->scale.x;
                   break;
               case sf::Keyboard::Down:
                   sidebar[SB_KEY_PRESSED] = "DOWN ARRow";
                   _info->origin.x -= to_scale * _info->scale.x;
                   break;
               case sf::Keyboard::Escape: //Close the window
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                   break;
               case sf::Keyboard::F: //Activates recieving input
                   sidebar[SB_KEY_PRESSED] = "F";
                    input = true;
                    window.pollEvent(event);
               case sf::Keyboard::R: //Resets the zoom
                   sidebar[SB_KEY_PRESSED] = "R";
                   _info->reset();
                   break;
               case sf::Keyboard::H: //For activating/deactiviating help
                   sidebar[SB_KEY_PRESSED] = "H";
                   if (help) {
                       help = false;
                   }
                   else if(!input){
                       help = true;
                   }
                   break;
               }
               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);
                               //Recieves the string to be deleted. Does nothing with it right now, 
                               //but could in the future be used to delete from file.
                               string to_delete = sidebar.rightClickText(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                   }
                   else{
                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                               //send mouse coordinates over to sidebar to see if something has been clicked
                               string new_eq = sidebar.clickText(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                               if (new_eq.length() > 0) {
                                   _info->equation = new_eq;
                               }
                   }
                   break;

               default:
                   break;
           }
       }
}

/*Runs the program*/
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }

   /*Push in the last of the equations*/
   oldEq.push(_info->equation);
   //Saves the old equations to the file if they aren't duplicates
   f.saveFunctions(oldEq);
    
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

/*Strip away white spaces*/
void animate::stripSpaces(string& str) {
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] == ' ') || (str[i] == '\n')) {
            str.erase(i, 1);
        }
    }
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

string animate::getMyTextLabel() {
    std::stringstream stream; //gotta do this to set precision
    stream << std::fixed << std::setprecision(2) << _info->equation << "\nD: (" << _info->domain.x << "," << _info->domain.y << ")";
    return stream.str();
}

animate::~animate() {
    delete _info;
}