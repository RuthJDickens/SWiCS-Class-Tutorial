#define PLAY_IMPLEMENTATION
#include "Play.h"
#include "Laser.h"
#include "Saucer.h"
#include "MainGame.h"

GameState gState;

// The entry point for a Windows program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
    Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
    Play::CentreAllSpriteOrigins();
    Play::LoadBackground( "Data\\Backgrounds\\background.png" );
    Saucer::SpawnWave(gState);
    //Play::StartAudioLoop( "music" );
}

// Called by the PlayBuffer once for each frame of the game (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
    gState.time += elapsedTime;

    Play::DrawBackground();
    if (gState.saucers.size() == 0)
    {
        gState.counter = 0;
        gState.difficulty++;
        Saucer::SpawnWave(gState);
    }
    Laser::UpdateAll(gState);
    UpdatePlayer();
    Saucer::UpdateAll(gState);
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

void UpdatePlayer( void )
{
    //Player movement
    if( Play::KeyDown( VK_LEFT ) )
        gState.playerPos.x -= gState.playerSpeed;

    if( Play::KeyDown( VK_RIGHT ) )
        gState.playerPos.x += gState.playerSpeed;

    if( Play::KeyPressed( VK_SPACE ) )
    {
        //Spawn laser at player
        Laser l = Laser({ gState.playerPos.x, gState.playerPos.y - 50 });
        gState.lasers.push_back(l);
        if (gState.score >= l.GetCost())
        {
           gState.score -= l.GetCost(); 
        }
        Play::PlayAudio("laser");
    }

    float yWobble = sin( gState.time * PLAY_PI ) * 3;
    Play::DrawSprite( Play::GetSpriteId( "Rocket" ), { gState.playerPos.x, gState.playerPos.y + yWobble }, (int)( 2.0f * gState.time ) );
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



