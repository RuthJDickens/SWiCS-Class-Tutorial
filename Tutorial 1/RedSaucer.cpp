#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Saucer.h"
#include "RedSaucer.h"

const Point2f SAUCER_START_POS = { 1500, 125 };

RedSaucer::RedSaucer(Point2f pos)
{
	m_pos = pos;
	m_startPos = { 1500, 125 };
	m_points = 2000;
	m_speed = 10;
}

void RedSaucer::SpawnWave(GameState& state)
{
    if (state.difficulty >= 2)
    {
        for (int n = 0; n < state.difficulty; n++)
        {
            RedSaucer* s = new RedSaucer(SAUCER_START_POS);
            //Spawning subsequent saucers next to each each and not on top of each other
            if (state.redCounter >= 1)
            {
                s->m_pos.x += s->m_width * state.redCounter;
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
}

void RedSaucer::Draw(GameState& state)
{
	Play::ColourSprite("Saucer", Play::cRed);
	Play::DrawSpriteRotated(m_spriteId, m_pos, 0, m_rot, 1.0f);
}
