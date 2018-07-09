/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:54:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/09 13:59:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	put_error(t_errnum err, char *str)
{
	ft_putstr_fd("scop: ", 2);
	if (err == NB_ARG)
		ft_putendl_fd("One (and only one) argument is expected", 2);
	else if (err == OPEN || err == READ || err == CLOSE || err == ALLOC)
		perror(str);
	else if (err == MODEL_DATA)
		ft_putendl_fd("Not enough data to build a model", 2);
	else if (err == GLFW_INIT)
		ft_putendl_fd("An error has occured during GLFW initialization", 2);
	else if (err == WIN_CREAT)
		ft_putendl_fd("An error has occured during GLFW Window creation", 2);
	else if (err == SHADER_CREAT)
	{
		ft_putstr_fd("Shader compilation / linkage error: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (err == UNIFORM_VAR)
	{
		ft_putstr_fd("An error has occured during ", 2);
		ft_putendl_fd("OpenGL uniform variables binding", 2);
	}
	else if (err == TEXTURE_LOAD)
	{
		ft_putstr_fd("Texture loading error: ", 2);
		ft_putendl_fd("source is a not a well formated .bmp file", 2);
	}
}

void	exit_error(t_errnum err, char *str)
{
	put_error(err, str);
	exit(EXIT_FAILURE);
}