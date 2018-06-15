/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/15 12:00:37 by fkoehler         ###   ########.fr       */
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

t_view_space	init_view_space(void)
{
	t_view_space	*view_space;

	if (!(view_space = (t_view_space*)malloc(sizeof(*view_space))))
		exit_error(ALLOC, NULL);
	view->space.fov = 60;
	view_space->translate = new_mat4(MAT_IDENTITY);
	view_space->rotate = new_mat4(MAT_IDENTITY);
	view_space->scale = new_mat4(MAT_IDENTITY);
	view_space->model = new_mat4(MAT_IDENTITY);
	view_space->view = mat4_translate(new_mat4(MAT_IDENTITY),
	new_vec3(-3.0f, 0.0f, 0.0f));
	view_space->proj = new_mat4(MAT_IDENTITY);
	view_space->mvp = new_mat4(MAT_IDENTITY);
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