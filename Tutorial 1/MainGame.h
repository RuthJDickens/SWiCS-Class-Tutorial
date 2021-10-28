#pragma once
#include "Play.h"

//Global Variables
const int DISPLAY_WIDTH = 1280;
const int DISPLAY_HEIGHT = 720;
const int DISPLAY_SCALE = 1;
const Point2f SAUCER_START_POS = { 1500, 125 };
const int OFF_SCREEN_TEST = -50;

class Laser;
class Saucer;

void UpdatePlayer();
bool HasCollided(Point2f pos1, Point2f pos2);

struct GameState
{
    int counter{ 0 };
    int time{ 0 };
    int score{ 0 };
    int difficulty{ 1 };
    Point2f playerPos = { 640, 650 };
    float playerSpeed = 5.0f;
    std::vector<Laser> lasers;
    std::vector<Saucer> saucers;
};