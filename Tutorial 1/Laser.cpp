#include "Laser.h"
#include "Saucer.h"
#include "MainGame.h"

//Constructor
Laser::Laser(Point2f pos)
{
	m_pos = pos;
}

//Getters
bool Laser::IsActive()
{
	return m_active;
}

Point2f Laser::GetPosition()
{
	return m_pos;
}

Vector2f Laser::GetVelocity()
{
	return m_velocity;
}

int Laser::GetCost()
{
	return m_cost;
}

//Setters
void Laser::SetInactive()
{
	m_active = false;
}

void Laser::SetPosition(Point2f pos)
{
	m_pos = pos;
}

void Laser::SetVelocity(Vector2f speed)
{
	m_velocity = speed;
}

void Laser::SetCost(int cost)
{
	m_cost = cost;
}

//Update
void Laser::UpdateAll(GameState& state)
{
    for (Laser& l : state.lasers)
    {
        l.Update(state);
    }
    for (int n = 0; n < state.lasers.size(); n++)
    {
        if (!state.lasers[n].IsActive())
        {
            state.lasers[n].SetPosition({ 0, -50 }); // Hide the laser off screen!
            state.lasers.erase(state.lasers.begin() + n);
        }
    }
}

void Laser::Update(GameState& state)
{
    if (IsActive())
    {
        //Movement
        SetPosition(GetPosition() - GetVelocity());
        Play::DrawSprite(Play::GetSpriteId("Laser"), GetPosition(), 0);

        //Collision
        for (Saucer& s : state.saucers)
        {
            if (HasCollided(GetPosition(), s.GetPosition()))
            {
                SetInactive();
                s.SetInactive();
                state.score += s.GetPoints();

                Play::PlayAudio("clang");
            }
        }
    }
}