#include "graphics.h"
#include "sprite.h"


Sprite::Sprite() {

}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX),
	_y(posY)
{
	this->_sourceRect.x = sourceX;						//rectangle , in the sprite sheet, where we are selceting the sprite
	this->_sourceRect.y = sourceY;						// i think
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	// if it was loaded somewhere else, it will give us the surface, 
	// if it wasnt yet, it will load it right now, and give us the surface.
	// creating the texture, and storing into our spritesheet

	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}


Sprite::~Sprite() {

}

/*Sprite draw
* 
* this does all the drawing!
* 
*/
void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w, this->_sourceRect.h };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::update() {

}