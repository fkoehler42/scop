#version 410 core

layout (location = 0) in vec3 position;
uniform mat4 mvp;
uniform int interpolate;
uniform int color;
uniform int y_gradient;

smooth out vec4 smooth_color;
flat out vec4 flat_color;

void main()
{
	float merged_position = position.x;
	int avoid_unused_var_error = interpolate + color + y_gradient;

	gl_Position = mvp * vec4(position.x, position.y, position.z, 1.0f);
	if (interpolate == 1)
		smooth_color = vec4(merged_position, merged_position, merged_position, 1.0f);
	else
		flat_color = vec4(position, 1.0f);
}