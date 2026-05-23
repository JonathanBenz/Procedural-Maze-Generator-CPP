#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Utils
{
public:
	/* ========================================================= */
	/* RANDOM NUMBER GENERATION UTILITIES*/
	static std::mt19937& GetRNG()
	{
		static std::mt19937 rng(std::random_device{}());
		return rng;
	}

	// Return a random number in the domain of (0, Range]. 
	template <typename T>
	static T BoundedRand(T Range)
	{
		std::uniform_int_distribution<T> dist(0, Range - 1);
		return dist(GetRNG());
	}

	// 50/50 chance to return true.
	static bool FlipCoin()
	{
		return BoundedRand(2) == 0;
	}

	// Randomly pick an element from a vector of pointers
	template <typename T>
	static T* Sample(const std::vector<T*>& vec)
	{
		if (vec.empty()) return nullptr;
		return vec.at((Utils::BoundedRand(vec.size())));
	}
	/* END OF RANDOM NUMBER GENERATION UTILITIES*/
	/* ========================================================= */

	/* ========================================================= */
	/* GRAPHICS RENDERING UTILITIES */
	static int InitOpenGL()
	{
		// Initialize GLFW, tell it we are using OpenGL 4.3 Core
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Procedural Maze Generator", NULL, NULL);

		// Handle Errors if window fails to be created
		if (window == NULL)
		{
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		// Make sure GLAD is initialized so that it can manage OpenGL Function Pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		// Initialize the viewport
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		// Set a callback function for resizing the window
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		return 1;
	}

	static void UpdateLoop()
	{
		while (!glfwWindowShouldClose(window))
		{
			// Get user input
			ProcessInput(window);

			// Render stuff here... 
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Check and call events/ callback functions, then swap the buffer
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}
	/* END OF GRAPHICS RENDERING UTILITIES */
	/* ========================================================= */

public:
	static const unsigned int SCR_WIDTH = 960;
	static const unsigned int SCR_HEIGHT = 540;
	inline static GLFWwindow* window = nullptr;

private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	static void ProcessInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // ESC
			glfwSetWindowShouldClose(window, true);
	}
};