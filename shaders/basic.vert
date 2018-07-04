#version 400 core

layout (location = 0) in vec3 position;
uniform mat4 mvp;

smooth out vec4 smooth_color;
flat out vec4 flat_color;

void main()
{
	float merged_position = position.x;

	gl_Position = mvp * vec4(position.x, position.y, position.z, 1.0f);
	smooth_color = vec4(merged_position, merged_position, merged_position, 1.0f);
	flat_color = vec4(position, 1.0f);
}