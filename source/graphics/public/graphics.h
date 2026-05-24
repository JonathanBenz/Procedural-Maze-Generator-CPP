#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>
#include "../../app.h"
#include "shader.h"

struct Vertex
{
	Vertex(float x, float y) : position(x, y) {}
	glm::vec2 position;
};

class Graphics
{
public:
	static int InitOpenGL()
	{
		// Initialize GLFW, tell it we are using OpenGL 4.3 Core
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Procedural Maze Generator", NULL, NULL);

		// Handle Errors if window fails to be created
		if (Window == NULL)
		{
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(Window);

		// Make sure GLAD is initialized so that it can manage OpenGL Function Pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		// Initialize the viewport
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

		// Set a callback function for resizing the window
		glfwSetFramebufferSizeCallback(Window, FramebufferSizeCallback);
		glfwSetKeyCallback(Window, KeyCallback);
		
		// Enable depth testing 
		glEnable(GL_DEPTH_TEST);

		return 1;
	}

	static void InitShader()
	{
		Shader shader;
		shader.SetupShader("shaders/vertex.vert", "shaders/fragment.frag");
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), Vertices.data(), GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);
		shader.use();
	}

	static void UpdateLoop()
	{
		while (!glfwWindowShouldClose(Window))
		{
			// Get user input
			ProcessInput(Window);

			// Render stuff here... 
			glClearColor(0.f, 0.f, 0.f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), Vertices.data(), GL_DYNAMIC_DRAW);
			glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(Vertices.size()));

			// Check and call events/ callback functions, then swap the buffer
			glfwPollEvents();
			glfwSwapBuffers(Window);
		}
	}

	static void AddLine(float x1, float y1, float x2, float y2)
	{
		Vertices.emplace_back(NormalizeX(x1), NormalizeY(y1));
		Vertices.emplace_back(NormalizeX(x2), NormalizeY(y2));
	}

	static void CleanUp()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glfwDestroyWindow(Window);
		glfwTerminate();
	}

public:
	static const unsigned int SCR_WIDTH = 720;
	static const unsigned int SCR_HEIGHT = 720;
	inline static GLFWwindow* Window = nullptr;
	inline static unsigned int VAO = 0;
	inline static unsigned int VBO = 0;
	inline static float Rows = -1;
	inline static float Columns = -1;
	inline static std::vector<Vertex> Vertices;

private:
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
			app->RegenerateMaze();
		}
	}

	static void ProcessInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // ESC
			glfwSetWindowShouldClose(window, true);
	}

	static float NormalizeX(float x)
	{
		return MinClip + (x / Columns) * (MaxClip - MinClip);
	}

	static float NormalizeY(float y)
	{
		return MaxClip - (y / Rows) * (MaxClip - MinClip);
	}

private:
	static constexpr float MinClip = -0.9f;
	static constexpr float MaxClip = 0.9f;
};