/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:53:26 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/04 20:28:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


// rewrite the file reading part elsewhere
static void	generate_vtx_shader(unsigned int *vertex_shader_id)
{
	char	*shader_src;
	FILE	*fs;
	long	size;
	int		sh_compil_success;
	char	error_log[512];

	if (!(fs = fopen(".."VTX_SHADER, "r")))
	{
		put_error(OPEN, ".."VTX_SHADER);
		exit(EXIT_FAILURE);
	}
	fseek(fs, 0, SEEK_END);
	size = ftell(fs); // handle empty file
	if (!(shader_src = (char *)malloc(sizeof(*shader_src) * size + 1)))
	{
		put_error(ALLOC, NULL);
		exit(EXIT_FAILURE);
	}
	rewind(fs);
	if (fread(shader_src, size, 1, fs) != 1)
	{
		free(shader_src);
		put_error(ALLOC, NULL); // write proper errnum
		exit(EXIT_FAILURE);
	}
	fclose(fs);
	*vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertex_shader_id, 1, (const char **)&shader_src, NULL);
	glCompileShader(*vertex_shader_id);
	glGetShaderiv(*vertex_shader_id, GL_COMPILE_STATUS, &sh_compil_success);
	free(shader_src);
	if (!(sh_compil_success))
	{
		glGetShaderInfoLog(*vertex_shader_id, 512, NULL, error_log);
		put_error(SH_COMPIL, error_log);
	}
}

static void	generate_vbo(t_vtx **vtx, unsigned int nb_vtx, unsigned int *vbo_id)
{
	unsigned int	i;
	unsigned int	j;
	float			vertices[nb_vtx * 3];

	i = 0;
	j = 0;
	while (i < nb_vtx)
	{
		vertices[j] = vtx[i]->x;
		j++;
		vertices[j] = vtx[i]->y;
		j++;
		vertices[j] = vtx[i]->z;
		j++;
		i++;
	}
	glGenBuffers(1, vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
}

void		generate_buf_obj(t_model *model)
{
	t_buf_obj	buf_obj;
	
	generate_vbo(model->v_array, model->nb_vtx, &(buf_obj.vbo_id));
	generate_vtx_shader(&(buf_obj.vtx_sh_id));
}