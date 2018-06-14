/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:46:09 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/14 14:02:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"
#include <stdlib.h>

t_mat4		*mat4_dup(t_mat4 src)
{
	int		i;
	t_mat4	*dst;

	i = -1;
	if (!(dst = (t_mat4*)malloc(sizeof(*dst))))
		return (NULL);
	while (++i < 16)
		dst->m[i] = src.m[i];
	return (dst);
}