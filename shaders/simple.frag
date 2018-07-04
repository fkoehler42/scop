#version 400 core

smooth in vec4 smooth_color;
flat in vec4 flat_color;

out vec4 FragColor;

void main()
{
	FragColor = flat_color;
}