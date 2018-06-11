/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:13:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/11 17:27:30 by fkoehler         ###   ########.fr       */
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
	init_matrices(env.model);
	init_window(&(env.window), &(env.win_w), &(env.win_h), env.model->name);
	env.gl_objs = generate_gl_objs(env.model);
	while (!glfwWindowShouldClose(env.window))
	{
		glUseProgram(env.gl_objs->shader_prog);
		glBindVertexArray(env.gl_objs->vao);
		glDrawElements(GL_TRIANGLES, env.gl_objs->nb_elems, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	// free allocated stuffs
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return (0);
}
