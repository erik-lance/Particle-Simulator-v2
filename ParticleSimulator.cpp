﻿// Particle Simulator.cpp : Defines the entry point for the application.
//

#include "ParticleSimulator.h"
#include "SimulatorGUI.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
	// Setup Window
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1600, 900, "Particle Simulator", NULL, NULL);
	if (window == NULL)
			return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// Initialize OpenGL loader
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // the window context to glad's opengl loader
		throw("Unable to context OpenGL");

	// Get screen size
	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	SimulatorGUI gui;
	gui.Init(window, glsl_version);

	while (1) {
		glfwPollEvents(); // Checks for keyboard input (and closes window if needed)
		gui.NewFrame();
		gui.Update();
		gui.Render();
	}

	gui.Shutdown();

	return 0;
}