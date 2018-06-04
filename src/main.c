/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:13:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/04 20:15:49 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int ac, char **av)
{
	t_model	model;
	t_win	win;

	if (ac != 2)
	{
		put_error(NB_ARG, NULL);
		return (EXIT_FAILURE);
	}
	init_model(&model);
	if (handle_file(av[1], &model) < 0)
		return (EXIT_FAILURE);
	init_window(&win, model.name);
	generate_buf_obj(&model);
	while (!glfwWindowShouldClose(win.win))
	{
		glfwSwapBuffers(win.win);
		glfwPollEvents();
	}
	// free allocated stuffs
	glfwDestroyWindow(win.win);
	glfwTerminate();
	return (0);
}
