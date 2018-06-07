/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:27:37 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/07 17:48:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	store_vertex(char **data, t_vec3 **array, unsigned int *nb_vtx)
{
	static unsigned int	vtx_idx = 0;
	int			i;

	//printf("nb de vertex : %u, index : %u\n", *nb_vtx, vtx_idx);
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
	{
		put_error(ALLOC, NULL);
		exit(EXIT_FAILURE);
	}
	while (--i > 0)
		array[vtx_idx]->v[i - 1] = strtof(data[i], NULL);
	vtx_idx++;
}

void	store_face(char **data, t_face **array, unsigned int *nb_face)
{
	static unsigned int	f_idx = 0;
	int			i;

	i = 0;
	while (data[i])
		i++;
	if (i < 4 || i > 5)
	{
		ft_putendl_fd("scop: A face has been ignored (bad format)", 2);
		free(array[*nb_face - 1]);
		(*nb_face)--;
		return ;
	}
	--i;
	if (!(array[f_idx] = (t_face*)malloc(sizeof(t_face))) ||
	!(array[f_idx]->v_id = (unsigned int *)malloc(sizeof(unsigned int) * i)))
	{
		put_error(ALLOC, NULL);
		exit(EXIT_FAILURE);
	}
	array[f_idx]->nb_vtx = i;
	while (--i >= 0)
		array[f_idx]->v_id[i] = ft_atoi(data[i + 1]);
	// printf("nb de faces : %1$u, index : %2$u, nb vtx sur face[%2$u] : %3$u\n", *nb_face, f_idx, array[f_idx]->nb_vtx);
	f_idx++;
}