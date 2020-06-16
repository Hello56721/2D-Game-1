/*
 * Window.h
 *
 *  Created on: Jun 14, 2020
 *      Author: liang
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
	// the window handle
	GLFWwindow* window;
	
	// Width and height
	unsigned int width;
	unsigned int height;
	
	// The title
	const char* title;
public:
	// Create the window
	Window(unsigned int width, unsigned int height, const char*);
	
	// Destroy the window
	~Window();
	
	// swap the window's buffer
	void swapBuffers();
	
	// Poll the events
	static void pollEvents();
	
	// Just Getters.
	unsigned int getHeight() const { return height; }
	const char* getTitle() const { return title; }
	unsigned int getWidth() const { return width; }
	GLFWwindow* getHandle() const { return window; }
};

#endif /* WINDOW_H_ */
