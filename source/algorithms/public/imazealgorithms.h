#pragma once

class Grid;
class Cell;

class IMazeAlgorithm
{
public:
	virtual void GenerateMaze(Grid& grid) = 0;
	virtual void ApplyAlgorithm(Cell* cell) = 0;
};