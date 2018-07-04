/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:18:23 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/04 17:36:46 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	switch_demo_state(t_env *env)
{
	if (env->render_opts->demo == 1)
		env->render_opts->demo = 0;
	else
		env->render_opts->demo = 1;
}

void		key_callback(GLFWwindow* win, int key, int scanc, int action, int mods)
{
	t_matrices	*matrices;

	(void)scanc;
	(void)mods;
	matrices = get_matrices(NULL);
	if (action == GLFW_RELEASE)
		return ;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
	if (key == GLFW_KEY_UP)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.04f, X_AXIS);
	if (key == GLFW_KEY_DOWN)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.04f, X_AXIS);
	if (key == GLFW_KEY_LEFT)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.04f, Y_AXIS);
	if (key == GLFW_KEY_RIGHT)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.04f, Y_AXIS);
	if (key == GLFW_KEY_PAGE_UP)
		matrices->rotate = mat4_rotate(matrices->rotate, 0.04f, Z_AXIS);
	if (key == GLFW_KEY_PAGE_DOWN)
		matrices->rotate = mat4_rotate(matrices->rotate, -0.04f, Z_AXIS);
	if (key == GLFW_KEY_A)
		matrices->view = mat4_translate(matrices->view, new_vec3(-0.1f, 0, 0));
	if (key == GLFW_KEY_D)
		matrices->view = mat4_translate(matrices->view, new_vec3(0.1f, 0, 0));
	if (key == GLFW_KEY_W)
		matrices->view = mat4_translate(matrices->view, new_vec3(0, 0.1f, 0));
	if (key == GLFW_KEY_S)
		matrices->view = mat4_translate(matrices->view, new_vec3(0, -0.1f, 0));
	if (key == GLFW_KEY_Q)
		matrices->view = mat4_translate(matrices->view, new_vec3(0, 0, 0.1f));
	if (key == GLFW_KEY_E)
		matrices->view = mat4_translate(matrices->view, new_vec3(0, 0, -0.1f));
	mvp_update(matrices);
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		switch_demo_state(get_env_struct(NULL));
}