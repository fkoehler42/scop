/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:04:25 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 14:03:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4		new_mat4(float f)
{
	int		i;
	t_mat4	new;

	i = -1;
	while (++i < 16)
	{
		if (f == MAT_IDENTITY)
			new.m[i] = i % 5 == 0 ? 1 : 0;
		else
			new.m[i] = f;
	}
	return (new);
}
