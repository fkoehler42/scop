/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:27:37 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/04 12:16:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	store_vertex(char **data, t_vtx **v_array, unsigned int *nb_vtx) {
	static int	vtx_idx = 0;
	int			i;

	while (data[i++]);
	if (i != 4) {
		ft_putendl_fd("scop: Vertex from file not well formatted", 2);
		free(v_array[*nb_vtx - 1]);
		*nb_vtx--;
		return ;
	}
	if (!(v_array[vtx_idx] = (t_vtx*)malloc(sizeof(t_vtx)))) {
		put_error(ALLOC, NULL);
		exit(EXIT_FAILURE);
	}
	v_array[vtx_idx]->x = strtof(data[1], NULL);
	v_array[vtx_idx]->y = strtof(data[2], NULL);
	v_array[vtx_idx]->z = strtof(data[3], NULL);
	vtx_idx++;
}