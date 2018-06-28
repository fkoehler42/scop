/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:18:23 by fkoehler          #+#    #+#             */
/*   Updated: 2018/06/28 16:08:23 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	switch_demo_state(t_env *env)
{
	if (env->demo == 1)
		env->demo = 0;
	else
		env->demo = 1;
}

void		key_callback(GLFWwindow* win, int key, int scanc, int action, int mods)
{
	t_matrices	*matrices;

	(void)scanc;
	(void)mods;
	matrices = get_matrices(NULL);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
	if (key == GLFW_KEY_RIGHT &&
	(action == GLFW_PRESS || action == GLFW_REPEAT))
		matrices->rotate = mat4_rotate(matrices->rotate, -0.04f, Y_AXIS);
	if (key == GLFW_KEY_LEFT &&
	(action == GLFW_PRESS || action == GLFW_REPEAT))
		matrices->rotate = mat4_rotate(matrices->rotate, 0.04f, Y_AXIS);
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		switch_demo_state(get_env_struct(NULL));
	mvp_update(matrices);
}