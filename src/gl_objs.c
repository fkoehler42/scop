/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_objs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:53:26 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/07 17:55:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static unsigned int	generate_ebo(t_face **faces, unsigned int nb_faces,
unsigned int nb_elems)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	ebo;
	unsigned int	indices[nb_elems];

	i = 0;
	j = 0;
	while (i < nb_faces)
	{
		k = 0;
		while (k < faces[i]->nb_vtx)
		{
			indices[j] = faces[i]->v_id[k];
			j++;
			k++;
		}
		i++;
	}
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 
	return (ebo);
}


static unsigned int	compute_ebo_size(t_face **faces, unsigned int nb_faces)
{
	unsigned int	i;
	unsigned int	nb_elems;

	i = 0;
	nb_elems = 0;
	while (i < nb_faces)
	{
		nb_elems += faces[i]->nb_vtx;
		i++;
	}
	return (nb_elems);
}

static unsigned int	generate_vbo(t_vec3 **vec, unsigned int nb_vtx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	vbo;
	float			vertices[nb_vtx * 3];

	i = 0;
	j = 0;
	while (i < nb_vtx)
	{
		k = 0;
		while (k < 3)
		{
			vertices[j] = vec[i]->v[k];
			j++;
			k++;
		}
		i++;
	}
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return (vbo);
}

t_gl_objs			*generate_gl_objs(t_model *model)
{
	t_gl_objs	*gl_objs;

	if (!(gl_objs = (t_gl_objs *)malloc(sizeof(*gl_objs))))
		exit_error(ALLOC, NULL);
	glGenVertexArrays(1, &(gl_objs->vao));
	glBindVertexArray(gl_objs->vao);
	gl_objs->vbo = generate_vbo(model->v_array, model->nb_vtx);
	gl_objs->nb_elems = compute_ebo_size(model->f_array, model->nb_face);
	gl_objs->ebo = generate_ebo(model->f_array, model->nb_face, gl_objs->nb_elems);
	gl_objs->vtx_shader = generate_shader(VTX_SHADER, GL_VERTEX_SHADER);
	gl_objs->frag_shader = generate_shader(FRAG_SHADER, GL_FRAGMENT_SHADER);
	gl_objs->shader_prog = generate_shader_program(gl_objs->vtx_shader,
	gl_objs->frag_shader);
	gl_objs->vtx_shader = 0;
	gl_objs->frag_shader = 0;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0); // normalization needed ? (GL_TRUE)
	glEnableVertexAttribArray(0);
	return (gl_objs);
}