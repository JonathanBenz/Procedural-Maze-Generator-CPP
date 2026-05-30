#pragma once
#include <iostream>
#include "app.h"
#include "grid/public/cell.h"
#include "grid/public/grid.h"
#include "grid/public/distance_grid.h"
#include "grid/public/distances.h"
#include "algorithms/public/algorithmcontext.h"

enum class PathType 
{ 
	Shortest, 
	Longest 
};

class DijkstraDemo
{
public:
	void SetGridSize(unsigned int rows, unsigned int columns)
	{
		m_Grid.InitGrid(rows, columns);
	}

	void SetMazeGenAlgorithm(MazeAlgorithm algo)
	{
		m_RandomMazeGenerator.SetStrategy(algo);
	}

	void SetStartCell(int row, int column)
	{
		m_StartingCell = m_Grid.GetCell(row, column);
	}

	void SetGoalCell(int row, int column)
	{
		m_GoalCell = m_Grid.GetCell(row, column);
	}

	void RunShortestPathDemo()
	{
		if (!m_StartingCell || !m_GoalCell) return;
		if (!bIsAppInitialized) InitApp();
		
		m_App.GenerateMaze();

		Distances distances = m_StartingCell->GetDistancesFromThisCell();
		m_Grid.SetDistances(distances.PathTo(m_GoalCell));
		std::cout << m_Grid << std::endl;
	}

	void RunLongestPathDemo()
	{
		if (!m_StartingCell) return;
		if (!bIsAppInitialized) InitApp();

		m_App.GenerateMaze();

		Distances distances = m_StartingCell->GetDistancesFromThisCell();
		Cell* newStartCell = distances.GetMaxCell();

		Distances newDistances = newStartCell->GetDistancesFromThisCell();
		Cell* goalCell = newDistances.GetMaxCell();

		m_Grid.SetDistances(newDistances.PathTo(goalCell));
		std::cout << m_Grid << std::endl;
	}

private:
	DistanceGrid m_Grid;
	AlgorithmContext m_RandomMazeGenerator;
	App m_App;
	Cell* m_StartingCell = nullptr;
	Cell* m_GoalCell = nullptr;
	bool bIsAppInitialized = false;

private:
	void InitApp()
	{
		m_App.InitApp(&m_Grid, &m_RandomMazeGenerator);
		glfwSetWindowUserPointer(Graphics::Window, &m_App);
		bIsAppInitialized = true;
	}
};