#define _CRTDBG_MAP_ALLOC
#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 1600;
const float SCREEN_HEIGHT = 1200;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;
const int POINTS = 1000;
const float X_MAX = 5;
const float Y_MAX = 5;

const float FRAME_OFFSET = 50;
const float FRAME_HEIGHT = SCREEN_HEIGHT - FRAME_OFFSET;
const float FRAME_WIDTH = WORK_PANEL - FRAME_OFFSET;
const int VECTOR_CAP = 40; //how many items to add to sidebar
const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;
#endif // CONSTANTS_H
