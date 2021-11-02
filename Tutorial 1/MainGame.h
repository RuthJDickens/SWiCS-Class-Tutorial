#pragma once
#include "Play.h"

//Global Variables
const int DISPLAY_WIDTH = 1280;
const int DISPLAY_HEIGHT = 720;
const int DISPLAY_SCALE = 1;

class Laser;
class Saucer;

bool HasCollided(Point2f pos1, Point2f pos2);

struct GameState
{
    int counter{ 0 };
    int time{ 0 };
    int score{ 0 };
    int difficulty{ 1 };
};