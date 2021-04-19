#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;


};



#endif


/*
	forward declaring lets me use these pointers without declaring them,
	because were going to declare them later in an implementation file.
*/