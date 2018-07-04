/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:13:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/04 13:01:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	rendering_loop(t_env *env)
{
	while (!glfwWindowShouldClose(env->window))
	{
		glfwPollEvents();
		glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(env->gl_objs->shader_prog);
		glUniformMatrix4fv(env->gl_objs->mvp, 1, GL_FALSE,
		env->matrices->mvp.m);
		glBindVertexArray(env->gl_objs->vao);
		glDrawElements(GL_TRIANGLES, env->model->nb_face * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env->window);
		if (env->demo == 1)
		{
			env->matrices->rotate = mat4_rotate(env->matrices->rotate,
			-0.02f, Y_AXIS);
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
	if (handle_file(av[1], env->model) < 0)
		return (EXIT_FAILURE);
	center_model(env->model->v_array, env->model->nb_vtx, env->model->center_point);
	init_window(&(env->window), &(env->win_w), &(env->win_h), env->model->name);
	env->matrices = init_matrices(env->win_w, env->win_h);
	env->gl_objs = generate_gl_objs(env->model);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // nice debug display
	rendering_loop(env);
	// free allocated stuffs
	glfwDestroyWindow(env->window);
	glfwTerminate();
	return (0);
}
