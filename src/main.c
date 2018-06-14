/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:13:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/14 19:57:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		put_error(NB_ARG, NULL);
		return (EXIT_FAILURE);
	}
	env.model = init_model();
	if (handle_file(av[1], env.model) < 0)
		return (EXIT_FAILURE);
	// init_matrices(env);
	init_window(&(env.window), &(env.win_w), &(env.win_h), env.model->name);
	env.gl_objs = generate_gl_objs(env.model);
	compute_mvp_matrix(env.model);
	// for (int i = 0; i < 16; i++)
	// 	printf("%f, ", env.model->mvp.m[i]);
	while (!glfwWindowShouldClose(env.window))
	{
		glfwPollEvents();
		glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(env.gl_objs->shader_prog);
		glUniformMatrix4fv(env.gl_objs->mvp, 1, GL_FALSE, env.model->mvp.m);
		glBindVertexArray(env.gl_objs->vao);
		glDrawElements(GL_TRIANGLES, env.model->nb_face * 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env.window);
	}
	// free allocated stuffs
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return (0);
}
