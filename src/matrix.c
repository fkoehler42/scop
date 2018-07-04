/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/04 12:53:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mvp_update(t_matrices *matrices)
{
	matrices->mvp = mat4_mul(matrices->view, matrices->proj);
	matrices->model = mat4_mul(matrices->translate, matrices->rotate);
	matrices->model = mat4_mul(matrices->model, matrices->scale);
	matrices->mvp = mat4_mul(matrices->model, matrices->mvp);
}