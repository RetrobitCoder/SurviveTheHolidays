#include <Arduboy2.h>
#include "Bitmaps.h"

enum class GameState : unsigned char
{
  Title, Play, Pause, GameOver
};

enum class PlayState : unsigned char
{
  NewYears
};

Arduboy2 ab;
Sprites sprite;
GameState gameState = GameState::Title;
PlayState playState = PlayState::NewYears;

void setup() {
  ab.begin();
  ab.clear();
  sprite.drawSelfMasked(0,0,ArduboyTitle_RetrobitCoder,0);
  ab.display();
  ab.delayShort(3000);
}

void mainTitle()
{
  sprite.drawSelfMasked(0,0,title,0);
  ab.setCursor(WIDTH/2-18, HEIGHT-8);
  ab.print("Press A");
  if(ab.justPressed(A_BUTTON))
  {
    gameState = GameState::Play;
  }
}

void gameLoop()
{
  //need to add new years game level
}

void loop() {
  if(!ab.nextFrame()) return;
  ab.clear();
  ab.pollButtons();
  switch(gameState)
  {
    case GameState::Title:
      mainTitle();
      break;
    case GameState::Play:
      gameLoop();
      break;
    case GameState::Pause:
      break;
    case GameState::GameOver:
      break;
  }
  ab.display();
}
