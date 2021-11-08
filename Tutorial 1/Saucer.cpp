#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Saucer.h"

const Point2f SAUCER_START_POS = { 1500, 300 };
const int OFF_SCREEN_TEST = -50;

//Constructor
Saucer::Saucer()
{
    m_spriteId = Play::GetSpriteId("Saucer");
    m_type = OBJ_SAUCER;
}
Saucer::Saucer(Point2f pos)
{
	m_pos = pos;
    m_spriteId = Play::GetSpriteId("Saucer");
    m_type = OBJ_SAUCER;
}

void Saucer::Update(GameState& state)
{
    //If hit by laser, set spinning trajectory
    if (m_isDead)
    {
        m_rot += 0.05f;
        m_velocity = { -m_speed, m_speed };
        //Set inactive when off bottom of screen
        if (m_pos.y > DISPLAY_HEIGHT + 50)
        {
            m_active = false;
        }
    }
    //Restart when off side of screen and hasn't been hit
    else if (m_pos.x < OFF_SCREEN_TEST)
    {
        m_pos = m_startPos;
    }
    //Movement
    m_pos += m_velocity;
}

void Saucer::SpawnWave(GameState& state)
{
    for (int n = 0; n < state.difficulty; n++)
    {
        Saucer* s = new Saucer(SAUCER_START_POS);
        //Spawning subsequent saucers next to each each and not on top of each other
        if (state.counter >= 1)
        {
            s->m_pos.x += s->m_width * state.counter;
            //Saucers remember where they spawned
            //s->SetStartPosition(s->GetPosition());
        }
        //Every other Saucer moves 1.5x faster
        if (state.counter % 2)
        {
            s->m_speed *= 1.5;
        }

        s->m_velocity = { -s->m_speed, 0 };
        state.counter++;
    }
}

void Saucer::Draw(GameState& state)
{
    Play::ColourSprite("Saucer", Play::cWhite);
    Play::DrawSpriteRotated(m_spriteId, m_pos, 0, m_rot, 1.0f);
}