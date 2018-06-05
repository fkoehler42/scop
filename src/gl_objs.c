/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_objs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:53:26 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/05 18:20:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


static unsigned int	generate_vbo(t_vtx **vtx, unsigned int nb_vtx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	vbo_id;
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
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return (vbo_id);
}

void				generate_gl_objs(t_model *model)
{
	t_gl_objs	gl_objs;

	gl_objs.vbo_id = generate_vbo(model->v_array, model->nb_vtx);
	gl_objs.vtx_sh_id = generate_shader(VTX_SHADER, GL_VERTEX_SHADER);
	gl_objs.frag_sh_id = generate_shader(FRAG_SHADER, GL_FRAGMENT_SHADER);
}