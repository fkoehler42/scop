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
	float merged_position = position.x * position.y * position.z * 2;
	int avoid_unused_var_error = interpolate + color + y_gradient;
	
	gl_Position = mvp * vec4(position.x, position.y, position.z, 1.0f);

	float test = (position.y + 1) / 2; // normalization

	if (color == 1 && y_gradient == 1)
		smooth_color = vec4(position.y * 2, position.y * 2, 0.75f, 1.0f);
	else if (color == 1 && y_gradient == 0)
		smooth_color = vec4(merged_position * 1.1f, merged_position, merged_position, 1.0f);
	else if (color == 0 && y_gradient == 1)
		smooth_color = vec4(test, test, test, 1.0f);
	else
		smooth_color = vec4(merged_position, merged_position, merged_position, 1.0f);
		flat_color = smooth_color;
}