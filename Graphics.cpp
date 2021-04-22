#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"



/* Graphics Class
*	holds all information dealing with graphics for the game
*/


Graphics::Graphics() {

	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}


SDL_Surface* Graphics::loadImage(const std::string &filePath) {							//this ensures we only load each image once.
	if (this->_spriteSheets.count(filePath) == 0) {									
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}