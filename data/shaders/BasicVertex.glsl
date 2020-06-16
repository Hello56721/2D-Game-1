#version 330 core
layout (location = 0) in vec3 Position;

uniform float xpos;
uniform float ypos;

void main() {
    gl_Position = vec4(Position.x + xpos, Position.y + ypos, Position.z, 1.0);
}