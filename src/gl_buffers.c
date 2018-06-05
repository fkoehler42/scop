/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_buffers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:53:26 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/05 12:19:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


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

void		generate_buf_objs(t_model *model)
{
	t_gl_bufs	gl_bufs;
	
	generate_vbo(model->v_array, model->nb_vtx, &(gl_bufs.vbo_id));
	gl_bufs.vtx_sh_id = generate_shader(VTX_SHADER, );
}