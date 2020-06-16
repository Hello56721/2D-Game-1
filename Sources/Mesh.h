/*
 * Mesh.h
 *
 *  Created on: Jun 14, 2020
 *      Author: liang
 */

#ifndef MESH_H_
#define MESH_H_

#include <glad/glad.h>

#include <iostream>

class Mesh {
private:
	// The, well, stuffs
	unsigned int vertexBuffer, vertexArray, elementBuffer;
	// the index array size
	GLsizei sizeOfIndices;
public:
	// Create the mesh
	Mesh(float vertices[], unsigned int indices[], GLsizei verticesSize, GLsizei indicesSize);
	
	// Detsroy the mesh
	~Mesh();
	
	// Render the mesh
	void render();
	
	// Getters for the values
	unsigned int getElementBuffer() const { return elementBuffer; }
	unsigned int getVertexArray() const { return vertexArray; }
	unsigned int getVertexBuffer() const { return vertexBuffer; }
};

#endif /* MESH_H_ */
