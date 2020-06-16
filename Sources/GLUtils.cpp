/*
 * GLUtils.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: liang
 */

#include "Utilities.h"

void GLUtils::loadOpenGL() {
    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    	std::cout << "ERROR: Failed to load OpenGL" << std::endl;
    }
}
