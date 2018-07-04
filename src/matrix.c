/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/04 13:29:58 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mvp_update(t_matrices *matrices)
{
	matrices->model = mat4_mul(matrices->scale,
	mat4_mul(matrices->rotate, matrices->translate));
	matrices->mvp = mat4_mul(matrices->model,
	mat4_mul(matrices->view, matrices->proj));
}