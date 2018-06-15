/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/15 12:00:06 by fkoehler         ###   ########.fr       */
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

typedef struct		s_model
{
	unsigned int	nb_vtx;
	unsigned int	nb_face;
	t_vec3			**v_array;
	unsigned int	**f_array;
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

typedef struct		s_view_space
{
	t_mat4			translate;
	t_mat4			rotate;
	t_mat4			scale;
	t_mat4			model;
	t_mat4			view;
	t_mat4			proj;
	t_mat4			mvp;
	float			fov;
}					t_view_space;

typedef struct		s_env
{
	t_model			*model;
	t_gl_objs		*gl_objs;
	t_view_space	*view_space;
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
void				store_face(char **data, unsigned int **array, unsigned int *nb_face);

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