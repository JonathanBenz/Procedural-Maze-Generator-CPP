#include "../public/imazealgorithms.h"
#include "../../grid/public/grid.h"
#include "../../grid/public/cell.h"

void IMazeAlgorithm::ResetAllCells(Grid& grid)
{
	grid.EachCell([this](Grid& grid, Cell* cell)
		{
			ResetCell(cell);
		});
}

void IMazeAlgorithm::ResetCell(Cell* cell)
{
	cell->Unlink(cell->GetNorthNeighbor());
	cell->Unlink(cell->GetSouthNeighbor());
	cell->Unlink(cell->GetEastNeighbor());
	cell->Unlink(cell->GetWestNeighbor());
}