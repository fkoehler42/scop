/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:19:44 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/11 15:25:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdlib.h>

t_vec3		new_vec3(float x, float y, float z)
{
	t_vec3	new;

	new.v[0] = x;
	new.v[1] = y;
	new.v[2] = z;
	return (new);
}

t_vec4		new_vec4(float x, float y, float z, float w)
{
	t_vec4	new;

	new.v[0] = x;
	new.v[1] = y;
	new.v[2] = z;
	new.v[3] = w;
	return (new);
}