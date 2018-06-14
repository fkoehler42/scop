/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/14 17:33:38 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
* Include <OpenGL/gl3.h> instead of <OpenGL/gl.h> in GLFW
*/
# define GLFW_INCLUDE_GLCOREARB

# include "../lib/libft/includes/libft.h"
# include "../lib/libmat/include/libmat.h"
# include <stdio.h>
# include <GLFW/glfw3.h>

# define WIN_W 1024
# define WIN_H 768

# define FRAG_SHADER "simple.frag"
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
	SHADER_CREAT
}					t_errnum;

typedef struct		s_file_buf
{
	FILE			*fs;
	char			*str;
	size_t			str_cap;
	ssize_t			str_len;
}					t_buffer;

typedef struct		s_face
{
	unsigned int	*v_id;
	unsigned int	nb_vtx;
}					t_face;

typedef struct		s_model
{
	unsigned int	nb_vtx;
	unsigned int	nb_face;
	t_vec3			**v_array;
	t_face			**f_array;
	t_mat4			translate;
	t_mat4			rotate;
	t_mat4			scale;
	t_mat4			mvp;
	char			*name;
}					t_model;

typedef struct		s_gl_objs
{
	unsigned int	vao;
	unsigned int	vbo;
	unsigned int	ebo;
	unsigned int	vtx_shader;
	unsigned int	frag_shader;
	unsigned int	shader_prog;
	unsigned int	nb_elems;
	GLuint			mvp;
}					t_gl_objs;

typedef struct		s_env
{
	t_model			*model;
	t_gl_objs		*gl_objs;
	GLFWwindow		*window;
	int				win_w;
	int				win_h;
}					t_env;

t_model				*init_model(void);
// void				init_matrices(t_env env);
void				init_window(GLFWwindow **win, int *win_w, int *win_h,
					char *model_name);

int					handle_file(char *path, t_model *model);
void				store_vertex(char **data, t_vec3 **array, unsigned int *nb_vtx);
void				store_face(char **data, t_face **array, unsigned int *nb_face);

t_gl_objs			*generate_gl_objs(t_model *model);
unsigned int		generate_shader_program(unsigned int vertex_shader,
					unsigned int fragment_shader);
unsigned int		generate_shader(char *shader_file, int shader_type);
void				compute_mvp_matrix(t_model *model);

void				key_callback(GLFWwindow* win, int key, int scanc, int action,
					int mods);

void				put_error(t_errnum err, char *str);
void				exit_error(t_errnum err, char *str);


#endif