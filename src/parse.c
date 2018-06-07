/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:14:47 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/07 17:26:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	parse_data(FILE *fs, t_model *model)
{
	char	**split;
	char	*buf;
	size_t	buf_cap;
	ssize_t	buf_len;

	buf = NULL;
	buf_cap = 0;
	while ((buf_len = getline(&buf, &buf_cap, fs)) > 0)
	{
		if (buf_len > 1 && buf[0] == 'v' && buf[1] == ' ')
		{
			split = ft_strsplit(buf, ' ');
			store_vertex(split, model->v_array, &(model->nb_vtx));
			free_tab(split);
		}
		else if (buf_len > 1 && buf[0] == 'f' && buf[1] == ' ')
		{
			split = ft_strsplit(buf, ' ');
			store_face(split, model->f_array, &(model->nb_face));
			free_tab(split);
		}
	}
	free(buf);
}

static int	parse_file(FILE *fs, unsigned int *nb_vtx, unsigned int *nb_face)
{
	char	*buf;
	size_t	buf_cap;
	ssize_t	buf_len;

	buf = NULL;
	buf_cap = 0;
	while ((buf_len = getline(&buf, &buf_cap, fs)) > 0)
	{
		if (buf_len > 1 && buf[0] == 'v' && buf[1] == ' ')
			(*nb_vtx)++;
		else if (buf_len > 1 && buf[0] == 'f' && buf[1] == ' ')
			(*nb_face)++;
	}
	free(buf);
	if (*nb_vtx < 3 || *nb_face == 0)
	{
		put_error(MODEL_DATA, NULL);
		return (-1);
	}
	return (0);
}

int			handle_file(char *path, t_model *model)
{
	FILE	*fs;

	if (!(fs = fopen(path, "r")))
	{
		put_error(OPEN, path);
		return (-1);
	}
	if (parse_file(fs, &(model->nb_vtx), &(model->nb_face)) < 0)
	{
		fclose(fs);
		return (-1);
	}
	model->name = strrchr(path, '/') + 1;
	model->v_array = (t_vec3 **)malloc(sizeof(t_vec3 *) * model->nb_vtx);
	model->f_array = (t_face **)malloc(sizeof(t_face *) * model->nb_face);
	if (!model->v_array || !model->f_array)
	{
		put_error(ALLOC, NULL);
		fclose(fs);
		return (-1);
	}
	rewind(fs);
	parse_data(fs, model);
	fclose(fs);
	return (0);
}