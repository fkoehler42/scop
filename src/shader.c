/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:55:02 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 16:38:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char		*get_shader_src(char *src_file)
{
	FILE				*fs;
	long				size;
	static const char	shader_dir[] = "./shaders/";
	char				*final_path;
	char				*shader_src;

	if (!(final_path = ft_strjoin(shader_dir, src_file)))
		exit_error(ALLOC, NULL);
	if (!(fs = fopen(final_path, "r")))
		exit_error(OPEN, final_path);
	fseek(fs, 0, SEEK_END);
	if ((size = ftell(fs)) < 0)
		exit_error(READ, final_path);
	if (!(shader_src = (char *)malloc(sizeof(*shader_src) * size + 1)))
		exit_error(ALLOC, NULL);
	rewind(fs);
	if (fread(shader_src, size, 1, fs) != 1)
		exit_error(READ, final_path);
	shader_src[size] = '\0';
	if (fclose(fs) != 0)
		put_error(CLOSE, final_path);
	free(final_path);
	return (shader_src);
}

unsigned int	generate_shader(char *shader_file, int shader_type)
{
	unsigned int	shader_id;
	int				sh_compil_success;
	char			error_log[512];
	const GLchar	*shader_src;

	shader_src = get_shader_src(shader_file);
	shader_id = glCreateShader(shader_type);
	glShaderSource(shader_id, 1, &shader_src, NULL);
	glCompileShader(shader_id);
	free((void *)shader_src);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &sh_compil_success);
	if (!(sh_compil_success))
	{
		glGetShaderInfoLog(shader_id, 512, NULL, error_log);
		exit_error(SHADER_CREAT, error_log);
	}
	return (shader_id);
}

unsigned int	generate_shader_program(unsigned int vertex_shader,
unsigned int fragment_shader)
{
	int				shader_link_success;
	char			error_log[512];
	unsigned int	shader_program_id;

	shader_program_id = glCreateProgram();
	glAttachShader(shader_program_id, vertex_shader);
	glAttachShader(shader_program_id, fragment_shader);
	glLinkProgram(shader_program_id);
	glGetProgramiv(shader_program_id, GL_LINK_STATUS, &shader_link_success);
	if (!(shader_link_success))
	{
		glGetProgramInfoLog(shader_program_id, 512, NULL, error_log);
		exit_error(SHADER_CREAT, error_log);
	}
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return (shader_program_id);
}
