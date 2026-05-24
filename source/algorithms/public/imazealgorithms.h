#pragma once

class Grid;
class Cell;

class IMazeAlgorithm
{
public:
	virtual void GenerateMaze(Grid& grid) = 0;
	virtual void ApplyAlgorithm(Grid& grid, Cell* cell) = 0;

	virtual void ResetAllCells(Grid& grid);

private:
	void ResetCell(Cell* cell);
};