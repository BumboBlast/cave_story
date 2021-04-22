#ifndef INPUT_H		// header guard
#define INPUT_H		// this ensures that we dont define functions more than once in main.
					
#include <SDL.h>
#include <map>

class Input {											// Keeping the state of the keyboard! Very helpful!
public:
	void beginNewFrame();								//will get called at the beginning of every frame.
	void keyUpEvent(const SDL_Event& event);			//will get called if a key was pressed or was released.
	void keyDownEvent(const SDL_Event& event);

	bool wasKeyPressed(SDL_Scancode key);				//can pass in any key into this function, and it will tell if it was pressed, released or held.
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
private:
	std::map<SDL_Scancode, bool> _heldKeys;				//"this map is going to hold what keys are currently being held (as in, continually pressed)"
														// a map holds two types of related information together
														// SDL_Scancode (used to be keycode, which would assign keys for input) used to represent keyboard keys
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;			//"The reason for a bool, we'll be able to pass in any key, and this map will know if it was held, pressed, or released."
};


#endif
