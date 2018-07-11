/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:18:23 by fkoehler          #+#    #+#             */
/*   Updated: 2018/07/10 16:56:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	switch_option_state(t_env *env, int key)
{
	if (key == GLFW_KEY_1)
		env->render_opts->demo = env->render_opts->demo == 1 ? 0 : 1;
	if (key == GLFW_KEY_2)
	{
		env->render_opts->wireframe = env->render_opts->wireframe == 1 ? 0 : 1;
		if (env->render_opts->wireframe == 1)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (key == GLFW_KEY_3)
		env->render_opts->interpolate = env->render_opts->interpolate == 1 ? 0 : 1;
	if (key == GLFW_KEY_4)
		env->render_opts->color = env->render_opts->color == 1 ? 0 : 1;
	if (key == GLFW_KEY_5)
		env->render_opts->gradient = env->render_opts->gradient == 1 ? 0 : 1;
	if (key == GLFW_KEY_6)
		env->render_opts->texture = env->render_opts->texture == 1 ? 0 : 1;
}

static void	rotate(t_matrices *matrices, int key)
{
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
}

void		key_callback(GLFWwindow* win, int key, int scanc, int action, int mods)
{
	t_matrices	*matrices;

	(void)scanc;
	(void)mods;
	matrices = get_matrices();
	if (action == GLFW_RELEASE)
		return ;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
	if (key >= GLFW_KEY_RIGHT && key <= GLFW_KEY_PAGE_DOWN)
		rotate(get_matrices(), key);
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
	if (key >= GLFW_KEY_1 && key <= GLFW_KEY_6)
		switch_option_state(get_env_struct(NULL), key);
}
