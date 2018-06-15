/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/15 18:31:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_model			*init_model(void)
{
	t_model	*model;

	if (!(model = (t_model*)malloc(sizeof(*model))))
		exit_error(ALLOC, NULL);
	model->nb_vtx = 0;
	model->nb_face = 0;
	model->v_array = NULL;
	model->f_array = NULL;
	model->name = NULL;
	return (model);
}

t_matrices	*init_matrices(int win_w, int win_h)
{
	t_matrices	*matrices;

	if (!(matrices = (t_matrices*)malloc(sizeof(*matrices))))
		exit_error(ALLOC, NULL);
	matrices->fov = 90.0f;
	matrices->r_angle = 0.0f;
	matrices->translate = new_mat4(MAT_IDENTITY);
	matrices->rotate = new_mat4(MAT_IDENTITY);
	matrices->scale = mat4_scale(new_mat4(MAT_IDENTITY), 0.25f);
	matrices->model = matrices->scale;
	matrices->view = mat4_translate(new_mat4(MAT_IDENTITY),
	new_vec3(-3.0f, 0.0f, 0.0f));
	matrices->proj = new_projection_mat4(matrices->fov, win_w / win_h, 0.1f, 100.0f);
	matrices->mvp = mat4_mul(mat4_mul(matrices->model, matrices->view), matrices->proj);
	matrices->mvp.m[15] = 1; // dirty trick to keep mvp[15] to 1
	// for (int i = 0; i < 16; i++)
	// 	printf("%f, ", matrices->mvp.m[i]);
	return (matrices);
}

void			init_window(GLFWwindow **win, int *win_w, int *win_h, char *model_name)
{
	int width;
	int height;
	
	if (!glfwInit())
		exit_error(GLFW_INIT, NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(*win = glfwCreateWindow(WIN_W, WIN_H, model_name, NULL, NULL)))
		exit_error(WIN_CREAT, NULL);
	glfwSetKeyCallback(*win, &key_callback);
	glfwMakeContextCurrent(*win);
	glfwGetFramebufferSize(*win, &width, &height);
	glViewport(0, 0, width, height);
	*win_w = WIN_W;
	*win_h = WIN_H;
	glEnable(GL_DEPTH_TEST);
}