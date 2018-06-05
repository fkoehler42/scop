/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/05 18:11:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
* Include <OpenGL/gl3.h> instead of <OpenGL/gl.h> in GLFW
*/
# define GLFW_INCLUDE_GLCOREARB

/*
* Include <OpenGL/gl3ext.h> in GLFW
*/
//# define GLFW_INCLUDE_GLEXT

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <GLFW/glfw3.h>

# define WIN_W 800
# define WIN_H 600

# define VTX_SHADER "basic.vert"

typedef enum		e_errnum
{
	NB_ARG,
	OPEN,
	READ,
	CLOSE,
	ALLOC,
	MODEL_DATA,
	GLFW_INIT,
	WIN_CREAT,
	SH_COMPIL,
}					t_errnum;

typedef struct		s_file_buf
{
	FILE			*fs;
	char			*str;
	size_t			str_cap;
	ssize_t			str_len;
}					t_buffer;

typedef struct		s_vtx
{
	float			x;
	float			y;
	float			z;
}					t_vtx;

typedef struct		s_face
{
	unsigned int	*v_id;
	unsigned int	nb_vtx;
}					t_face;

typedef struct		s_model
{
	unsigned int	nb_vtx;
	unsigned int	nb_face;
	t_vtx			**v_array;
	t_face			**f_array;
	char			*name;
}					t_model;

typedef struct		s_gl_objs
{
	unsigned int	vbo_id;
	unsigned int	vao_id;
	unsigned int	ebo_id;
	unsigned int	vtx_sh_id;
}					t_gl_objs;

typedef struct		s_win
{
	GLFWwindow		*win;
	int				w;
	int				h;
}					t_win;


void				init_model(t_model *model);
void				init_window(t_win *win, char *model_name);

int					handle_file(char *path, t_model *model);
void				store_vertex(char **data, t_vtx **array, unsigned int *nb_vtx);
void				store_face(char **data, t_face **array, unsigned int *nb_face);

void				generate_gl_objs(t_model *model);
unsigned int		generate_shader(char *shader_file, int shader_type);

void				key_callback(GLFWwindow* win, int key, int scanc, int action,
					int mods);

void				put_error(t_errnum err, char *str);
void				exit_error(t_errnum err, char *str);


#endif