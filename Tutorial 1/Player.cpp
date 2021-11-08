#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Player.h"
#include "Laser.h"

float PLAYER_SPEED = 5.0f;

Player::Player(Point2f pos)
{
	m_pos = pos;
    m_velocity = { PLAYER_SPEED, 0 };
    m_type = OBJ_PLAYER;
    m_spriteId = Play::GetSpriteId("Rocket");
}

void Player::Update(GameState& state)
{
    //Player movement
    if (Play::KeyDown(VK_LEFT))
        m_pos -= m_velocity;

    if (Play::KeyDown(VK_RIGHT))
        m_pos += m_velocity;

    if (Play::KeyPressed(VK_SPACE))
    {
        //Spawn laser at player
        Laser* l = new Laser({ m_pos.x, m_pos.y - 50 });
        if (state.score >= l->GetCost())
        {
            state.score -= l->GetCost();
        }
        Play::PlayAudio("laser");
    }
}

void Player::Draw(GameState& state)
{
    float yWobble = sin(state.time * PLAY_PI) * 3;
    Play::DrawSprite(m_spriteId, { m_pos.x, m_pos.y + yWobble }, (int)(2.0f * state.time));
}