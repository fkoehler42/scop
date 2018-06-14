/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:27:37 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/14 19:56:50 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	store_vertex(char **data, t_vec3 **array, unsigned int *nb_vtx)
{
	static unsigned int	vtx_idx = 0;
	int			i;

	// printf("nb de vertex : %u, index : %u\n", *nb_vtx, vtx_idx);
	i = 0;
	while (data[i])
		i++;
	if (i != 4) {
		ft_putendl_fd("scop: A vertex has been ignored (bad format)", 2);
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
	int			i;

	i = 0;
	while (data[i])
		i++;
	if (i < 4 || i > 5)
	{
		ft_putendl_fd("scop: A face has been ignored (bad format)", 2);
		return ;
	}
	if (!(array[f_idx] = (unsigned int*)malloc(sizeof(unsigned int) * 3)))
		exit_error(ALLOC, NULL);
	if (--i == 4)
	{
		array[f_idx][0] = ft_atoi(data[4]) - 1;
		array[f_idx][1] = ft_atoi(data[1]) - 1;
		array[f_idx][2] = ft_atoi(data[2]) - 1;
		f_idx++;
		store_face(&(data[1]), array, nb_face);
		return ;
	}
	while (--i >= 0)
		array[f_idx][i] = ft_atoi(data[i + 1]) - 1;
	// printf("nb de faces : %1$u, index : %2$u, nb vtx sur face[%2$u] : %3$u\n", *nb_face, f_idx, array[f_idx]->nb_vtx);
	f_idx++;
}