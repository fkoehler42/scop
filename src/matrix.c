/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 15:01:39 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mvp_update(t_matrices *matrices)
{
	matrices->model = mat4_mul(matrices->scale,
	mat4_mul(matrices->rotate, matrices->translate));
	matrices->mvp = mat4_mul(matrices->model,
	mat4_mul(matrices->view, matrices->proj));
}

void	rotate(t_matrices *matrices, int key)
{
	if (key == GLFW_KEY_UP)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.025f, X_AXIS);
	if (key == GLFW_KEY_DOWN)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.025f, X_AXIS);
	if (key == GLFW_KEY_LEFT)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.025f, Y_AXIS);
	if (key == GLFW_KEY_RIGHT)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.025f, Y_AXIS);
	if (key == GLFW_KEY_PAGE_UP)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.025f, Z_AXIS);
	if (key == GLFW_KEY_PAGE_DOWN)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.025f, Z_AXIS);
	mvp_update(matrices);
}

void	translate(t_matrices *mat, int key)
{
	if (key == GLFW_KEY_A)
		mat->translate = mat4_translate(mat->translate, new_vec3(-0.07f, 0, 0));
	if (key == GLFW_KEY_D)
		mat->translate = mat4_translate(mat->translate, new_vec3(0.07f, 0, 0));
	if (key == GLFW_KEY_W)
		mat->translate = mat4_translate(mat->translate, new_vec3(0, 0.07f, 0));
	if (key == GLFW_KEY_S)
		mat->translate = mat4_translate(mat->translate, new_vec3(0, -0.07f, 0));
	if (key == GLFW_KEY_Q)
		mat->translate = mat4_translate(mat->translate, new_vec3(0, 0, 0.07f));
	if (key == GLFW_KEY_E)
		mat->translate = mat4_translate(mat->translate, new_vec3(0, 0, -0.07f));
	mvp_update(mat);
}
