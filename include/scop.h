/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/05/31 19:03:01 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "../lib/libft/includes/libft.h"
# include <GLFW/glfw3.h>
# include <stdio.h>

typedef enum		e_errnum {
	NB_ARG,
	OPEN,
	ALLOC,
	MODEL_DATA,
}					t_errnum;

typedef struct		s_file_buf {
	FILE			*fs;
	char			*str;
	size_t			str_cap;
	ssize_t			str_len;
}					t_buffer;

typedef struct		s_vtx {
	float			x;
	float			y;
	float			z;
}					t_vtx;

typedef struct		s_face {
	unsigned int	v_idx[4];
}					t_face;

typedef struct		s_model {
	unsigned int	nb_vtx;
	unsigned int	nb_face;
	t_vtx			**v_array;
	t_face			**f_array;
	char			*name;
}					t_model;

typedef struct		s_win {
	GLFWwindow		*win;
	int				w;
	int				h;
}					t_win;


void				init_model(t_model *model);

int					handle_file(char *path, t_model *model);

void				put_error(t_errnum err);


#endif