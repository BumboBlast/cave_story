#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"													// ok so first i initialize a class in header, define it in a cpp file, and use it in another cpp file


/*	Game class
*
*	This class holds all the information for the main game loop
*/

	
namespace {															//making a namespace incase we eventually reuse fps or something later,
	const int FPS = 50;												//dont want it to be global.
}	const int MAX_FRAME_TIME = 5 * 1000 / FPS;						//idk why this is yet ):


Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;



	int LAST_UPDATE_TIME = SDL_GetTicks();

	//start the game loop
	while (true) {
		input.beginNewFrame();										//this will reset pressed keys/ released keys

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {						//SDL tells us that a key is pressed,
				if (event.key.repeat == 0) {						//this makes sure that you arent holding down a key
					input.keyDownEvent(event);		
				}
			}
			else if (event.type == SDL_KEYUP) {						//SDL tells us that a key was released
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			return;
		}


		const int CURRENT_TIME_MS = SDL_GetTicks();		
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;	//how long was this current frame

		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));	//limits the FPS (somehow lol)

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics& graphics) {

}

void Game::update(float elapsedTime) {

}