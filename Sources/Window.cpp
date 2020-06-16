/*
 * Window.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: liang
 */

#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const char* title) {
	// Initialize Members
	this->width = width;
	this->height = height;
	this->title = title;
	
    /* Initialize the library */
    if (!glfwInit()){
    	std::cout << "ERROR: Failed to initialize GLFW" << std::endl;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
    	std::cout << "ERROR: Failed to create GLFW window." << std::endl;
    }
    
    /* Make the window in the center of the screen */
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (videoMode->width - width) / 2, (videoMode->height - height) / 2);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    // Limit the FPS
    glfwSwapInterval(1);
}

Window::~Window() {
	glfwDestroyWindow(window);
}

void Window::swapBuffers() {
	glfwSwapBuffers(window);
}

void Window::pollEvents() {
	glfwPollEvents();
}
