#include "input.h"						//ok so in the header file, i "initilize" the functions and objects of my class
										//and in this cpp file, i actually define them (or implement them)

/*	Input Class
*	
*	Keeps track of keyboard state
*/


//this function gets called at the beginning of each new frame
//to reset the keys that are no longer relevant.
void Input::beginNewFrame() {
	this->_pressedKeys.clear();											//these only matter for the current frame
	this->_releasedKeys.clear();										//if a key is being held, its already being stored in "heldKeys"
}	


//this gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;				//since pressedkeys is of type SDL_Scanscode, and keysym.scancode is as well,
																		//the map can just be indexed like this.

	this->_heldKeys[event.key.keysym.scancode] = true;					//since key is pressed, key is also held.
}


//this gets called when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;				//let go of the keys
	this->_heldKeys[event.key.keysym.scancode] = false;
}


//called to check if a certain key was pressed 
//during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) {							// ok so SDL_Scancode is a data type					
	return this->_pressedKeys[key];
}


//called to check if a certain key was released
//during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}


//called to check if a certain key is being held
//during the current frame
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}