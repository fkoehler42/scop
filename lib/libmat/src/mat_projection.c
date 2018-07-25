/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:32:54 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/25 14:00:50 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_mat4		new_projection_mat4(float fov, float aspect_ratio, float near,
float far)
{
	t_mat4			new;
	static float	deg_to_rad = PI_VALUE / 180;
	float			x_scale;
	float			y_scale;

	new = new_mat4(0);
	y_scale = 1.0 / tan(deg_to_rad * fov / 2);
	x_scale = y_scale / aspect_ratio;
	new.m[0] = x_scale;
	new.m[5] = y_scale;
	new.m[10] = (far + near) / (near - far);
	new.m[11] = -1;
	new.m[14] = 2 * far * near / (near - far);
	return (new);
}
