#pragma once
#include "Play.h"
#include "MainGame.h"

class Saucer
{
private:
    bool m_active{ true };
    bool m_isDead{ false };
    Point2f m_startPos{ 0,0 };
    Point2f m_pos{ 0,0 };
    Vector2f m_velocity{ 0,0 };
    float m_speed{ 5 };
    float m_rot{ 0 };
    int m_points{ 1000 };
    int m_width{120};

public:
    Saucer(Point2f pos);
    //Getters
    bool IsActive();
    bool IsDead();
    Point2f GetPosition();
    Point2f GetStartPosition();
    Vector2f GetVelocity();
    float GetSpeed();
    float GetRotation();
    int GetPoints();
    int GetWidth();
    //Setters
    void SetInactive();
    void SetDead();
    void SetPosition(Point2f pos);
    void SetStartPosition(Point2f pos);
    void SetVelocity(Vector2f speed);
    void SetSpeed(float speed);
    void SetRotation(float rot);
    void SetPoints(int points);
    void SetWidth(int width);
    //Update
    static void UpdateAll(GameState& state);
    void Update(GameState& state);
    static void SpawnWave(GameState& state);

};

