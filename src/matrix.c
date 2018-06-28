/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/28 15:12:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mvp_update(t_matrices *matrices)
{
	matrices->model = mat4_mul(mat4_mul(matrices->translate, matrices->rotate),
	matrices->scale);
	matrices->mvp = mat4_mul(mat4_mul(matrices->model, matrices->view),
	matrices->proj);
	matrices->mvp.m[15] = 1;
}