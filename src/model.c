/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:06:51 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/02 11:07:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	center_model(t_vec3 **v_array, unsigned int nb_vtx, float *center_point)
{
	unsigned int	i;
	unsigned int	j;
	float			min;
	float			max;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		min = v_array[0]->v[i];
		max = v_array[0]->v[i];
		while (++j < nb_vtx)
		{
			if (v_array[j]->v[i] < min)
				min = v_array[j]->v[i];
			else if (v_array[j]->v[i] > max)
				max = v_array[j]->v[i];
		}
		center_point[i] = median_float(min, max);
	}
	j = -1;
	while (++j < nb_vtx)
	{
		i = -1;
		while (++i < 3)
			v_array[j]->v[i] -= center_point[i];
	}
}