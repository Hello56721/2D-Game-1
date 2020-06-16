/*
 * Shader.h
 *
 *  Created on: Jun 13, 2020
 *      Author: liang
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <glad/glad.h>

#include <sstream>
#include <iostream>
#include <fstream>

class Shader {
private:
	// The shader program handle
	unsigned int program;
	
public:
	// Constructor, which loads and builds the shaders
	Shader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& name);
	
	// Destroy the shader
	~Shader();
	
	// "Run" the shader
	void use();
	
	// Unifrom utility functions
	void setUniform(std::string name, float value);
	
	// Getter for the program handle
	unsigned int getID() { return program; }
};

#endif /* SHADER_H_ */
