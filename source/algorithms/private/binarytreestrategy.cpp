#include "../public/binarytreestrategy.h"
#include "../../grid/public/grid.h"
#include "../../grid/public/cell.h"
#include "../../grid/public/utils.h"
#include <vector>

void BinaryTreeStrategy::GenerateMaze(Grid& grid)
{
	grid.EachCell([this](Cell* cell) // Pass lambda (internally a functor) as argument
		{
			ApplyAlgorithm(cell);
		});
}

void BinaryTreeStrategy::ApplyAlgorithm(Cell* cell)
{
	if (!cell) return;

	// Try to get the North and East cell neighbors
	std::vector<Cell*> neighbors;
	if (cell->GetNorthNeighbor()) neighbors.push_back(cell->GetNorthNeighbor());
	if (cell->GetEastNeighbor()) neighbors.push_back(cell->GetEastNeighbor());

	// Randomly choose to link one of the neighbors if possible
	if (neighbors.empty()) return;
	Cell* neighbor = neighbors.at((Utils::BoundedRand(neighbors.size())));
	if (neighbor) cell->Link(neighbor);
}