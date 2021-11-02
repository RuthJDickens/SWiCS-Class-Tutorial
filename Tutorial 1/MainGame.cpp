#define PLAY_IMPLEMENTATION
#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"
#include "Laser.h"
#include "Saucer.h"
#include "Player.h"

GameState gState;
const Point2f PLAYER_STARTPOS = { 640, 650 };

// The entry point for a Windows program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
    Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
    Play::CentreAllSpriteOrigins();
    Play::LoadBackground( "Data\\Backgrounds\\background.png" );
    Saucer::SpawnWave(gState);
    new Player(PLAYER_STARTPOS);
    //Play::StartAudioLoop( "music" );
}

// Called by the PlayBuffer once for each frame of the game (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
    gState.time += elapsedTime;
    std::vector<GameObject*> vSaucers;

    Play::DrawBackground();
    GameObject::GetObjectList(GameObject::Type::OBJ_SAUCER, vSaucers);
    if (vSaucers.size() == 0)
    {
        gState.counter = 0;
        gState.difficulty++;
        Saucer::SpawnWave(gState);
    }
    GameObject::UpdateAll(gState);
    GameObject::DrawAll(gState);
    Play::DrawFontText( "105px", "SCORE: " + std::to_string( gState.score ),
        { DISPLAY_WIDTH / 2, 50 }, Play::CENTRE );
    Play::PresentDrawingBuffer();
    return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
    Play::DestroyManager();
    return PLAY_OK;
}

bool HasCollided( Point2f pos1, Point2f pos2 )
{
    const float DISTANCE_TEST = 50.0f;

    Vector2f separation = pos2 - pos1;
    float dist = sqrt( ( separation.x * separation.x ) + ( separation.y * separation.y ) );
    if( dist < DISTANCE_TEST )
        return true;
    else
        return false;
}



