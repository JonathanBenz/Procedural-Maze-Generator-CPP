#include <iostream>
#include "app.h"
#include "utils.h"
#include "grid/public/grid.h"
#include "graphics/public/graphics.h"
#include "algorithms/public/algorithmcontext.h"

int main()
{
	if (Graphics::InitOpenGL() == -1) return -1;

	Grid grid(16, 16);

	AlgorithmContext randomMazeGenerator;
	randomMazeGenerator.SetStrategy(MazeAlgorithm::Sidewinder);
	App app(grid, randomMazeGenerator);
	app.RegenerateMaze();
	glfwSetWindowUserPointer(Graphics::Window, &app);
	
	//std::cout << grid << std::endl;

	Graphics::InitShader();
	Graphics::UpdateLoop();
    Graphics::CleanUp();
}