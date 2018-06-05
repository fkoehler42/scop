/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/05 16:59:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_model(t_model *model)
{
	model->nb_vtx = 0;
	model->nb_face = 0;
	model->v_array = NULL;
	model->f_array = NULL;
	model->name = NULL;
}

void	init_window(t_win *win, char *model_name)
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
	if (!(win->win = glfwCreateWindow(WIN_W, WIN_H, model_name, NULL, NULL)))
		exit_error(WIN_CREAT, NULL);
	glfwSetKeyCallback(win->win, &key_callback);
	glfwMakeContextCurrent(win->win);
	glfwGetFramebufferSize(win->win, &width, &height);
	glViewport(0, 0, width, height);
	win->w = WIN_W;
	win->h = WIN_H;
}