#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shader.h"
#include "Mesh.h"
#include "Window.h"

#include "Utilities.h"

#define windowWidth 800
#define windowHeight 600

void resizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(void) {
    float xpos;
    float ypos;
    
    Window* window = new Window(windowWidth, windowHeight, "Hello World!");
    
    // initialize glad
    GLUtils::loadOpenGL();
    
    // Set the resize callback
    glfwSetFramebufferSizeCallback(window->getHandle(), resizeCallback);
    
    Shader* shader = new Shader("data/shaders/BasicVertex.glsl", "data/shaders/BasicFragment.glsl", "basic");
    
    float vertices[] = {
         0.1f,  0.1f, 0.0f,  
         0.1f, -0.1f, 0.0f, 
        -0.1f, -0.1f, 0.0f, 
        -0.1f,  0.1f, 0.0f  
    };                       
    unsigned int indices[] = {
        0, 1, 3,   
        1, 2, 3    
    }; 
    
    Mesh* mesh = new Mesh(vertices, indices, sizeof(vertices), sizeof(indices));

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window->getHandle())) {
    	// Recieve Input
    	// *********************************
    	// *********************************
    	
    	// Move left and right
    	if (glfwGetKey(window->getHandle(), GLFW_KEY_LEFT) == GLFW_PRESS) {
    		xpos = xpos - 0.05f;
    	}
    	if (glfwGetKey(window->getHandle(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
    	    xpos = xpos + 0.05f;
    	}
    	
    	// Move up and down
    	if (glfwGetKey(window->getHandle(), GLFW_KEY_UP) == GLFW_PRESS) {
    		ypos = ypos + 0.05f;
    	}
    	if (glfwGetKey(window->getHandle(), GLFW_KEY_DOWN) == GLFW_PRESS) {
    	    ypos = ypos - 0.05f;
    	}
    	
        /* Render here */
    	// *********************************
    	// *********************************
    	
    	// Clear the window with red
    	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // "Run" the shader program
        shader->use();
        
        // Set the xpos an ypos
        shader->setUniform("xpos", xpos);
        shader->setUniform("ypos", ypos);
        
        mesh->render();
        
        // Update the window here
        // *********************************
        // *********************************

        /* Swap front and back buffers */
        window->swapBuffers();

        /* Poll for and process events */
        Window::pollEvents();
    }
    
    // Delete everything afterwards
    delete shader;
    delete mesh;
    delete window;

    glfwTerminate();
    return 0;
}
