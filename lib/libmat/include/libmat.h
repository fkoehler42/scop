/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:03:06 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/11 18:39:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H

#include <math.h>

# define MAT_IDENTITY 0x7FFFFFFF

typedef enum	e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}				t_axis;

typedef struct	s_vec3
{
	float		v[3];
}				t_vec3;

typedef struct	s_vec4
{
	float		v[4];
}				t_vec4;

typedef struct	s_mat4
{
	float		m[16];
}				t_mat4;


t_vec3			new_vec3(float x, float y, float z);
t_vec4			new_vec4(float x, float y, float z, float w);

t_mat4			new_mat4(float f);

t_mat4			mat4_mul(t_mat4 m1, t_mat4 m2);
t_mat4			mat4_rotate(t_mat4 m, float angle, t_axis axis);

#endif