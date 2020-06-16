/*
 * Shader.cpp
 *
 *  Created on: Jun 13, 2020
 *      Author: liang
 */

#include "Shader.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& name) {
	std::string str_vertexSource, str_fragmentSource;
	std::ifstream vertexFile, fragmentFile;
	std::stringstream vertexStream, fragmentStream;
	
	// Ensure that file stream can throw exceptions
	vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try {
		// Open the files
		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);
		
		// Read the files
		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();
		
		// Close the files
		vertexFile.close();
		fragmentFile.close();
	} catch (std::ifstream::failure& e) {
		std::cout << "[WARNING]: Error while loading shader sources of " << name << std::endl;
	}
	
	// Convert the string streams into c strings
	str_vertexSource = vertexStream.str();
	str_fragmentSource = fragmentStream.str();
	const char* vertexSource = str_vertexSource.c_str();
	const char* fragmentSource = str_fragmentSource.c_str();
	
    int success;
    char infoLog[512];
    
    // the vertex shader
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    
    // Build the vertex shader
    glShaderSource(vertex, 1, &vertexSource, NULL);
    glCompileShader(vertex);
    
    // Check for compiliation errors
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
    	glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    	std::cout << "WARNING: Failed to compile vertex shader of " << name << ":\n" << infoLog << std::endl << std::endl;
    }
    
    // the vertex shader
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    
    // Build the vertex shader
    glShaderSource(fragment, 1, &fragmentSource, NULL);
    glCompileShader(fragment);
    
    // Check for compiliation errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
    	glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    	std::cout << "WARNING: Failed to compile fragment shader of " << name << ":\n" << infoLog << std::endl << std::endl;
    }
	
	program = glCreateProgram();
	
    // Link the shaders together into this program
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    
    // Check of linking error
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
    	glGetProgramInfoLog(program, 512, NULL, infoLog);
    	std::cout << "WARNING: Failed to link shader program of " << name << ":\n" << infoLog << std::endl << std::endl;
    }
}

Shader::~Shader() {
	glDeleteProgram(program);
}

void Shader::use() {
	glUseProgram(program);
}

void Shader::setUniform(std::string name, float value) {
	glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}
