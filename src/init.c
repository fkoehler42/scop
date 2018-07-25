/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 13:00:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_render_opts	*init_render_opts(void)
{
	t_render_opts	*render_opts;

	if (!(render_opts = (t_render_opts*)malloc(sizeof(*render_opts))))
		exit_error(ALLOC, NULL);
	render_opts->demo = 1;
	render_opts->interpolate = 0;
	render_opts->wireframe = 0;
	render_opts->color = 0;
	render_opts->gradient = 1;
	render_opts->texture = 0;
	render_opts->ambient_light = 1.0f;
	return (render_opts);
}

static t_model			*init_model(void)
{
	t_model	*model;

	if (!(model = (t_model*)malloc(sizeof(*model))))
		exit_error(ALLOC, NULL);
	model->nb_vtx = 0;
	model->nb_face = 0;
	model->v_array = NULL;
	model->f_array = NULL;
	model->name = NULL;
	model->center_points[0] = 0.0f;
	model->center_points[1] = 0.0f;
	model->center_points[2] = 0.0f;
	model->max_coord_interval = 0.0f;
	return (model);
}

t_env					*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(*env))))
		exit_error(ALLOC, NULL);
	get_env_struct(env);
	env->model = init_model();
	env->render_opts = init_render_opts();
	return (env);
}

t_matrices				*init_matrices(float coord_interval)
{
	t_matrices	*matrices;

	// printf("interval : %f\n", coord_interval);
	if (!(matrices = (t_matrices*)malloc(sizeof(*matrices))))
		exit_error(ALLOC, NULL);
	matrices->fov = 90.0f;
	matrices->translate = mat4_translate(new_mat4(MAT_IDENTITY), new_vec3(0, 0, (coord_interval * -0.75f)));
	matrices->rotate = new_mat4(MAT_IDENTITY);
	matrices->scale = new_mat4(MAT_IDENTITY);
	matrices->view = new_mat4(MAT_IDENTITY);
	matrices->proj = new_projection_mat4(matrices->fov, (float)WIN_W / (float)WIN_H, 0.1f, 100.0f);
	mvp_update(matrices);
	// for (int i = 0; i < 16; i++)
	// 	printf("%f, ", matrices->mvp.m[i]);
	return (matrices);
}

void					init_window(GLFWwindow **win, char *model_name)
{
	if (!glfwInit())
		exit_error(GLFW_INIT, NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(*win = glfwCreateWindow(WIN_W, WIN_H, model_name, NULL, NULL)))
		exit_error(WIN_CREAT, NULL);
	glfwSetKeyCallback(*win, &key_callback);
	glfwMakeContextCurrent(*win);
	glfwGetFramebufferSize(*win, NULL, NULL);
	glViewport(0, 0, WIN_W, WIN_H);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}