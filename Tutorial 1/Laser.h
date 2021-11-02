#pragma once

class Laser: public GameObject
{
private:
    int m_cost{ 0 };
    int m_speed{ 20 };

public:
    Laser(Point2f pos);
    //Getters and Setters
    void SetCost(int cost) {m_cost = cost;};
    int GetCost() const { return m_cost; };
    void SetSpeed(int speed) { m_speed = speed; };
    int GetSpeed() const { return m_speed; };
    //Update
    void Update(GameState& state);
    void Draw(GameState& state);
};

