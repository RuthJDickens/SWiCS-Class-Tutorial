#include "Saucer.h"
#include "MainGame.h"

//Constructor
Saucer::Saucer(Point2f pos) : m_startPos{ SAUCER_START_POS }
{
	m_pos = pos;
}

//Getters
bool Saucer::IsActive()
{
    return m_active;
}

bool Saucer::IsDead()
{
    return m_isDead;
}

Point2f Saucer::GetPosition()
{
    return m_pos;
}

Point2f Saucer::GetStartPosition()
{
    return m_startPos;
}
Vector2f Saucer::GetVelocity()
{
    return m_velocity;
}

float Saucer::GetSpeed()
{
    return m_speed;
}

float Saucer::GetRotation()
{
    return m_rot;
}

int Saucer::GetPoints()
{
    return m_points;
}

int Saucer::GetWidth()
{
    return m_width;
}

//Setters
void Saucer::SetInactive()
{
    m_active = false;
}

void Saucer::SetDead()
{
    m_isDead = true;
}

void Saucer::SetPosition(Point2f pos)
{
    m_pos = pos;
}

void Saucer::SetStartPosition(Point2f pos)
{
    m_startPos = pos;
}
void Saucer::SetVelocity(Vector2f speed)
{
    m_velocity = speed;
}

void Saucer::SetSpeed(float speed)
{
    m_speed = speed;
}

void Saucer::SetRotation(float rot)
{
    m_rot = rot;
}

void Saucer::SetPoints(int points)
{
    m_points = points;
}

void Saucer::SetWidth(int width)
{
    m_width = width;
}

//Update
void Saucer::UpdateAll(GameState& state)
{
    for (Saucer& s : state.saucers)
    {
        s.Update(state);
    }

    for (int n = 0; n < state.saucers.size(); n++)
    {
        if (state.saucers[n].IsDead())
        {
            state.saucers.erase(state.saucers.begin() + n);
        }
    }
}

void Saucer::Update(GameState& state)
{
    if (!IsActive())
    {
        SetRotation(GetRotation() + 0.05f);
        SetVelocity({ -GetSpeed(), GetSpeed() });
        if (GetPosition().y > DISPLAY_HEIGHT + 50)
        {
            SetDead();
        }
    }
    else if (GetPosition().x < OFF_SCREEN_TEST)
    {
        SetPosition(GetStartPosition());
    }
    SetPosition(GetPosition() + GetVelocity());

    Play::DrawSpriteRotated(Play::GetSpriteId("Saucer"), GetPosition(), 0, GetRotation(), 1.0f);
}

void Saucer::SpawnWave(GameState& state)
{
    for (int n = 0; n < state.difficulty; n++)
    {
        Saucer s = Saucer(SAUCER_START_POS);
        if (state.counter >= 1)
        {
            s.SetPosition({ s.GetPosition().x + s.GetWidth() * state.counter, s.GetPosition().y });
            if (state.difficulty >= 5 && state.counter % 3)
            {
                s.SetPosition({ s.GetPosition().x, s.GetPosition().y + 300 });
            }
            s.SetStartPosition(s.GetPosition());
        }
        if (state.counter % 2)
        {
            s.SetSpeed(s.GetSpeed() * 1.5);
        }

        s.SetVelocity({ -s.GetSpeed(), 0 });
        
        state.saucers.push_back(s);
        state.counter++;
    }
}
