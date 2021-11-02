#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Laser.h"
#include "Saucer.h"

//Constructor
Laser::Laser(Point2f pos)
{
	m_pos = pos;
    m_type = OBJ_LASER;
}

//Update
void Laser::Update(GameState& state)
{
    //Collision - find objects of type Saucer
    std::vector<GameObject*> vSaucers;
    GetObjectList(OBJ_SAUCER, vSaucers);
    for (GameObject* p : vSaucers)
    {
       Saucer* s = dynamic_cast<Saucer*>(p);
       if (s != nullptr)
       {
          if (s->IsDead() == false && HasCollided(m_pos, s->GetPosition()))
          {
             m_active = false;
             s->SetDead();
             state.score += s->GetPoints();
             Play::PlayAudio("clang");
          }
       }
    }
    m_velocity = { 0, m_speed };
    m_pos -= m_velocity;

    //Set inactive if offscreen
    if (m_active && m_pos.y < 0)
    {
       m_active = false;
    }
}

void Laser::Draw(GameState& state)
{
    Play::DrawSprite(Play::GetSpriteId("Laser"), GetPosition(), 0);
}