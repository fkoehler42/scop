/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 13:25:33 by fkoehler         ###   ########.fr       */
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

# define BMP_HEADER_SIZE 54

# define WIN_W 1600
# define WIN_H 1200

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
	UNSUPPORTED,
	GLFW_INIT,
	WIN_CREAT,
	SHADER_CREAT,
	UNIFORM_VAR,
	TEXTURE_LOAD
}					t_errnum;

typedef struct		s_texture
{
	int				width;
	int				height;
	unsigned int	img_size;
	unsigned short	bpp;
	unsigned char	*buff_data;
	unsigned char	*img_data;
	unsigned int	data_offset;
}					t_texture;

typedef struct		s_model
{
	unsigned int	nb_vtx;
	unsigned int	nb_face;
	t_vec3			**v_array;
	unsigned int	**f_array;
	float			center_points[3];
	float			max_coord_interval;
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
	GLuint			tex_id[2];
	GLint			mvp;
	GLint			interpolate;
	GLint			color;
	GLint			gradient;
	GLint			tex_loc;
	GLint			light_loc;
}					t_gl_objs;

typedef struct		s_render_opts
{
	int				demo;
	int				interpolate;
	int				wireframe;
	int				color;
	int				gradient;
	int				texture;
	float			ambient_light;
}					t_render_opts;

typedef struct		s_matrices
{
	t_mat4			translate;
	t_mat4			rotate;
	t_mat4			scale;
	t_mat4			model;
	t_mat4			view;
	t_mat4			proj;
	t_mat4			mvp;
	float			fov;
}					t_matrices;

typedef struct		s_env
{
	t_model			*model;
	t_gl_objs		*gl_objs;
	t_matrices		*matrices;
	GLFWwindow		*window;
	t_render_opts	*render_opts;
}					t_env;

t_env				*init_env(void);
t_matrices			*init_matrices(float coord_interval);
void				init_window(GLFWwindow **win, char *model_name);

void				handle_file(char *path, t_model *model);
void				store_vertex(char **data, t_vec3 **array, unsigned int *nb_vtx);
void				store_face(char **data, unsigned int **array, unsigned int *nb_face);

t_gl_objs			*generate_gl_objs(t_model *model);
unsigned int		generate_shader_program(unsigned int vertex_shader,
					unsigned int fragment_shader);
unsigned int		generate_shader(char *shader_file, int shader_type);
GLuint				load_texture(const char *filename);

void				set_model_pos_infos(t_model *model);
void				mvp_update(t_matrices *matrices);
void				gl_objs_update(t_gl_objs *gl_objs,
					t_render_opts *render_opts, GLfloat *mvp_address);

void				key_callback(GLFWwindow* win, int key, int scanc, int action,
					int mods);

void				rotate(t_matrices *matrices, int key);
void				translate(t_matrices *mat, int key);

t_matrices			*get_matrices(void);
t_env				*get_env_struct(t_env *env);
unsigned int		ft_strtoui(char *str);

void				put_error(t_errnum err, const char *str);
void				exit_error(t_errnum err, const char *str);

#endif
