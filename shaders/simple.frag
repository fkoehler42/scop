#version 410 core

uniform int interpolate;

smooth in vec4 smooth_color;
flat in vec4 flat_color;

out vec4 FragColor;

void main()
{
	if (interpolate == 1)
		FragColor = smooth_color;
	else
		FragColor = flat_color;
}