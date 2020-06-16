/*
 * Mesh.cpp
 *
 *  Created on: Jun 14, 2020
 *      Author: liang
 */

#include "Mesh.h"

Mesh::Mesh(float vertices[], unsigned int indices[], GLsizei verticesSize, GLsizei indicesSize) {
    // create the vertex array
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    // create the vertex buffer
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    
    // Feed the vertex buffer data
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
    
    // Speicify the layout of the vertex buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    // Create the element buffer
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    
    // Give the element buffer data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
    
    // Set the size of indices
    sizeOfIndices = indicesSize;
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vertexArray);
	unsigned int buffers[2] = {vertexBuffer, elementBuffer};
	glDeleteBuffers(2, buffers);
}

void Mesh::render() {
	// Bind the vertex array
	glBindVertexArray(vertexArray);
	// Enable the vertex attributes
    glEnableVertexAttribArray(0);
    // Bind the element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    // Draw
    glDrawElements(GL_TRIANGLES, sizeOfIndices, GL_UNSIGNED_INT, NULL);
    // Now disable everything
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
