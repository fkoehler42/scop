/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:13:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 12:24:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	rendering_loop(t_env *env)
{
	while (!glfwWindowShouldClose(env->window))
	{
		glfwPollEvents();
		glClearColor(0.05f, 0.15f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(env->gl_objs->vao);
		gl_objs_update(env->gl_objs, env->render_opts, env->matrices->mvp.m);
		glDrawElements(GL_TRIANGLES, env->model->nb_face * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env->window);
		if (env->render_opts->demo == 1)
		{
			env->matrices->rotate = mat4_rotate(env->matrices->rotate,
			-0.01f, Y_AXIS);
			mvp_update(env->matrices);
		}
	}
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		exit_error(NB_ARG, NULL);
	env = init_env();
	handle_file(av[1], env->model);
	set_model_pos_infos(env->model);
	init_window(&(env->window), env->model->name);
	env->matrices = init_matrices(env->model->max_coord_interval);
	env->gl_objs = generate_gl_objs(env->model);
	rendering_loop(env);
	glfwDestroyWindow(env->window);
	glfwTerminate();
	return (0);
}
