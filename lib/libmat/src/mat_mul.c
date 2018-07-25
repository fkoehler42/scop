/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:30:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 14:03:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

#include <stdio.h>

t_mat4		mat4_mul(t_mat4 m1, t_mat4 m2)
{
	int		x;
	int		y;
	int		z;
	t_mat4	new;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			new.m[x * 4 + y] = 0;
			z = -1;
			while (++z < 4)
				new.m[x * 4 + y] += m1.m[x * 4 + z] * m2.m[z * 4 + y];
		}
	}
	return (new);
}
