/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/14 18:59:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			compute_mvp_matrix(t_model *model)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	model->scale = new_mat4(MAT_IDENTITY);
	model->scale.m[0] = 0.5f;
	model->scale.m[5] = 0.5f;
	model->scale.m[10] = 0.5f;
	model->rotate = mat4_rotate(new_mat4(MAT_IDENTITY), 80, Y_AXIS);
	model->translate = new_mat4(MAT_IDENTITY);
	model->mvp = mat4_mul(mat4_mul(model->scale, model->rotate), model->translate);
}