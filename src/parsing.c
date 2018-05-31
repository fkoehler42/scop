/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:14:47 by fkoehler          #+#    #+#             */
/*   Updated: 2018/05/31 19:03:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"


static void	parse_data(FILE *fs, t_model *model) {
	char	*buf;
	size_t	buf_cap;
	ssize_t	buf_len;

	buf = NULL;
	buf_cap = 0;
	while ((buf_len = getline(&buf, &buf_cap, fs)) > 0) {
		if (buf_len > 1 && buf[0] == 'v' && buf[1] == ' ')
			model->nb_vtx++;
		else if (buf_len > 1 && buf[0] == 'f' && buf[1] == ' ')
			model->nb_face++;
	}
	free(buf);
	if (model->nb_vtx < 3 || !model->nb_face) {
		put_error(MODEL_DATA);
		return (-1);
	}
}

static int	parse_file(FILE *fs, t_model *model) {
	char	*buf;
	size_t	buf_cap;
	ssize_t	buf_len;

	buf = NULL;
	buf_cap = 0;
	while ((buf_len = getline(&buf, &buf_cap, fs)) > 0) {
		if (buf_len > 1 && buf[0] == 'v' && buf[1] == ' ')
			model->nb_vtx++;
		else if (buf_len > 1 && buf[0] == 'f' && buf[1] == ' ')
			model->nb_face++;
	}
	free(buf);
	if (model->nb_vtx < 3 || !model->nb_face) {
		put_error(MODEL_DATA);
		return (-1);
	}
	return (0);
}

int			handle_file(char *path, t_model *model) {
	FILE	*fs;

	if (!(fs = fopen(arg, "r")) {
		put_error(OPEN, arg);
		return (-1);
	}
	if (parse_file(fs, model) < 0) {
		fclose(fs);
		return (-1);
	}
	model->name = strrchr(path, '/');
	model->v_array = (t_vtx **)malloc(sizeof(t_vtx *) * model->nb_vtx));
	model->f_array = (t_face **)malloc(sizeof(t_face *) * model->nb_face));
	if (!model->v_array || !model->f_array) {
		put_error(ALLOC);
		fclose(fs);
		return (-1);
	}
	parse_data(fs, &model);
	return (0);
}