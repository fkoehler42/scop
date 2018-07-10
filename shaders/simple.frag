#version 410 core

uniform int interpolate;
uniform int texturing;
uniform sampler2D my_texture;

smooth in vec4 smooth_color;
flat in vec4 flat_color;
in vec2 tex_coordinates;

out vec4 FragColor;

void main()
{
	vec4 textured = texture(my_texture, tex_coordinates);

	if (texturing == 1 && interpolate == 1)
		FragColor = mix(smooth_color, textured, 0.75f);
	else if (texturing == 1)
		FragColor = mix(flat_color, textured, 0.75f);
	else if (interpolate == 1)
		FragColor = smooth_color;
	else
		FragColor = flat_color;
}