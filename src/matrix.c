/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/15 18:33:36 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	demo_update(t_matrices *matrices)
{
	if (matrices->r_angle >= 359.99f)
		matrices->r_angle = 0;
	else
		matrices->r_angle += 0.01f;
	matrices->rotate = mat4_rotate(new_mat4(MAT_IDENTITY), matrices->r_angle,
	Y_AXIS);
	matrices->model = mat4_mul(mat4_mul(matrices->translate, matrices->rotate),
	matrices->scale);
	matrices->mvp = mat4_mul(mat4_mul(matrices->model, matrices->view),
	matrices->proj);
	matrices->mvp.m[15] = 1;
}