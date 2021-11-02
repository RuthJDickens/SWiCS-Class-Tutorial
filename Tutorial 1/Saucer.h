#pragma once

class Saucer: public GameObject
{
private:
    bool m_isDead{ false };
    Point2f m_startPos{ 1500, 125 };
    float m_speed{ 5 };
    float m_rot{ 0 };
    int m_points{ 1000 };
    int m_width{120};

public:
    Saucer(Point2f pos);
    //Getters
    bool IsDead() { return m_isDead; };
    Point2f GetStartPosition() { return m_startPos; };
    float GetSpeed() { return m_speed; };
    float GetRotation() { return m_rot; };
    int GetPoints() { return m_points; };
    int GetWidth() { return m_width; };
    //Setters
    void SetDead() { m_isDead = true; };
    void SetStartPosition(Point2f pos) { m_startPos = pos; };
    void SetSpeed(float speed) { m_speed = speed; };
    void SetRotation(float rot) { m_rot = rot; };
    void SetPoints(int points) { m_points = points; };
    void SetWidth(int width) { m_width = width; };
    //Update
    void Update(GameState& state);
    void Draw(GameState& state);
    static void SpawnWave(GameState& state);

};

