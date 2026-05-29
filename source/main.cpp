#include <iostream>
#include "app.h"
#include "utils.h"
#include "grid/public/cell.h"
#include "grid/public/grid.h"
#include "grid/public/distance_grid.h"
#include "grid/public/distances.h"
#include "graphics/public/graphics.h"
#include "algorithms/public/algorithmcontext.h"

int main()
{
	if (Graphics::InitOpenGL() == -1) return -1;

	DistanceGrid grid(8, 8);
	Cell* StartingCell = grid.GetCell(0, 0);
	Cell* GoalCell = grid.GetCell(grid.GetTotalRows() - 1, 0);
	AlgorithmContext randomMazeGenerator;
	App app(grid, randomMazeGenerator);
	glfwSetWindowUserPointer(Graphics::Window, &app);

	randomMazeGenerator.SetStrategy(MazeAlgorithm::Sidewinder);
	app.GenerateMaze();

	Distances distances = StartingCell->GetDistancesFromThisCell();
	grid.SetDistances(distances.PathTo(GoalCell));
	std::cout << grid << std::endl;

	Graphics::InitShader();
	Graphics::UpdateLoop();
    Graphics::CleanUp();
}