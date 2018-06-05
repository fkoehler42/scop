#include <GLFW/glfw3.h>
#include <stdio.h>

static void	key_callback(GLFWwindow* win, int key, int scanc, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, 1);
}

int			main(void) {
	if (!glfwInit()) {
		puts("GLFW Init error!");
		return (1);
	}
	GLFWwindow*	win = glfwCreateWindow(640, 480, "Test", NULL, NULL);
	if (!win)
		puts("Window creation error!");
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetKeyCallback(win, key_callback);
	glfwMakeContextCurrent(win);
	int i = 0;
	while (!glfwWindowShouldClose(win)) {
		++i;
		if (i % 3 == 0)
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		else if (i % 3 == 1)
			glClearColor(0.3f, 0.1f, 0.1f, 1.0f);
		else
			glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
