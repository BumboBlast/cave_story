#ifndef GRAPHICS_H
#define GRAPHICS_H



/*	holds all information dealing with graphics for the game
* 
*/

#include <map>
#include <string>


struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();				//constructor
	~Graphics();			//descructor



	/*SDL_Surface* loadImage
	* loads an image onto the _spriteSheets map, if it doesnt already exist.
	* As a result, each image will only ever be loaded once.
	* Returns an image from the map, regardless whether it was just loaded
	*/

	SDL_Surface *loadImage(const std::string& filePath);



	/*void blitSurface
	* draws a rectangle to a certain part of the screen
	* 
	* source : *what* we are drawing to the screen
	* sourceRectanlge : what *part* of source are we drawing to the screen 
	* destinationRectangle : *where* on the screen we are drawing
	* 
	* is what draws images (SDL_Textures) to the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);



	/* void flip
	* Renders everything to the screen
	*/
	void flip();



	/*void clear
	* clears the screen
	*/
	void clear();

	/* SDL_Renderer* getRenderer
	* Returns the renderer so it can be used elsewhere
	* (needed in the sprite class)
	*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;				// this map is going to hold every sprite loaded into the game
																	// if they are held onto for the entire time graphics exists, 
																	//then an image will never have to be loaded more than once.
};



#endif


/*
	forward declaring lets me use these pointers without declaring them,
	because were going to declare them later in an implementation file.



	- at the beginning of each drawing cycle, we want to clear the render
	- blitsurface, will draw TO that render after its been cleared out
	- flip will take whatever is on that render, and draw it to the screen
	--> ok so render is like "staging" the graphics to be actually drawn onto the screen
*/