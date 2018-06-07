/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:03:06 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/07 17:36:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H

#include <math.h>

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

#endif