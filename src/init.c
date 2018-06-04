/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/04 18:05:25 by fkoehler         ###   ########.fr       */
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
	if (!glfwInit())
	{
		put_error(GLFW_INIT, NULL);
		exit(EXIT_FAILURE);
	}
	if (!(win->win = glfwCreateWindow(WIN_W, WIN_H, model_name, NULL, NULL)))
	{
		put_error(WIN_CREAT, NULL);
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetKeyCallback(win->win, &key_callback);
	glfwMakeContextCurrent(win->win);
	glViewport(0, 0, WIN_W, WIN_H);
	win->w = WIN_W;
	win->h = WIN_H;
}