#pragma once
#include "Play.h"
#include "MainGame.h"

class Laser
{
private:
    bool m_active{ true };
    Point2f m_pos{ 0,0 };
    Vector2f m_velocity{ 0,20 };
    int m_cost = 100;

public:
    Laser(Point2f pos);
    //Getters
    bool IsActive();
    Point2f GetPosition();
    Vector2f GetVelocity();
    int GetCost();
    //Setters
    void SetInactive();
    void SetPosition(Point2f pos);
    void SetVelocity(Vector2f speed);
    void SetCost(int cost);
    //Update
    static void UpdateAll(GameState& state);
    void Update(GameState& state);
};

