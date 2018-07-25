/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:27:37 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 15:02:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	store_vertex(char **data, t_vec3 **array, unsigned int *nb_vtx)
{
	static unsigned int	vtx_idx = 0;
	int					i;

	i = 0;
	while (data[i])
		i++;
	if (i != 4)
	{
		put_error(UNSUPPORTED, "A vertex");
		free(array[*nb_vtx - 1]);
		(*nb_vtx)--;
		return ;
	}
	if (!(array[vtx_idx] = (t_vec3*)malloc(sizeof(t_vec3))))
		exit_error(ALLOC, NULL);
	*(array[vtx_idx]) = new_vec3(strtof(data[1], NULL),
	strtof(data[2], NULL), strtof(data[3], NULL));
	vtx_idx++;
}

void	store_face(char **data, unsigned int **array, unsigned int *nb_face)
{
	static unsigned int	f_idx = 0;
	int					i;

	i = 0;
	while (data[i])
		i++;
	if (i < 4 || i > 5)
	{
		put_error(UNSUPPORTED, "A face");
		return ;
	}
	if (!(array[f_idx] = (unsigned int*)malloc(sizeof(unsigned int) * 3)))
		exit_error(ALLOC, NULL);
	if (--i == 4)
	{
		array[f_idx][0] = ft_strtoui(data[4]) - 1;
		array[f_idx][1] = ft_strtoui(data[1]) - 1;
		array[f_idx][2] = ft_strtoui(data[2]) - 1;
		f_idx++;
		store_face(&(data[1]), array, nb_face);
		return ;
	}
	while (--i >= 0)
		array[f_idx][i] = ft_strtoui(data[i + 1]) - 1;
	f_idx++;
}
