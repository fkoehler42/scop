#version 410 core

uniform int interpolate;
uniform sampler2D kitty_texture;

smooth in vec4 smooth_color;
flat in vec4 flat_color;
in vec2 tex_coordinates;

out vec4 FragColor;

void main()
{
	if (interpolate == 1)
		FragColor = smooth_color;
	else
		FragColor = flat_color;
	FragColor = texture(kitty_texture, tex_coordinates);
}