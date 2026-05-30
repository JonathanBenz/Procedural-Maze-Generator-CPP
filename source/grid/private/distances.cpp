#include "../public/distances.h"
#include "../public/cell.h"

Distances::Distances(Cell* root)
{
	if (root)
	{
		m_Root = root;
		m_Cells[root] = 0;
	}
}

Distances Distances::PathTo(Cell* goal)
{
	if (!goal) return nullptr;
	Cell* currentCell = goal;

	Distances breadcrumbs(m_Root);
	breadcrumbs.SetDistance(currentCell, m_Cells[currentCell]);

	while (currentCell != m_Root)
	{
		for (Cell* neighbor : currentCell->GetLinks())
		{
			if (m_Cells[neighbor] < m_Cells[currentCell])
			{
				breadcrumbs.SetDistance(neighbor, m_Cells[neighbor]);
				currentCell = neighbor;
				break;
			}
		}
	}

	return breadcrumbs;
}

std::vector<Cell*> Distances::GetCells()
{
	std::vector<Cell*> cells;
	for (auto& e : m_Cells) 
		cells.push_back(e.first);

	return cells;
}

// return -1 if key does not exist
int Distances::GetDistanceFrom(Cell* cell)
{
	return m_Cells.find(cell) != m_Cells.end() ? static_cast<int>(m_Cells[cell]) : -1;
}

int Distances::GetDistanceFrom(const Cell* cell) const
{
	// For the const version of this method we cannot use the [] operator for the map. That is why we get the iterator instead. 
	auto it = m_Cells.find(const_cast<Cell*>(cell));
	return it != m_Cells.end() ? static_cast<int>(it->second) : -1;
}

Cell* Distances::GetMaxCell() const
{
	return m_Cells.rbegin()->first;
}

int Distances::GetMaxDistance() const
{
	return m_Cells.rbegin()->second;
}

void Distances::SetDistance(Cell* cell, unsigned int distance)
{
	m_Cells[cell] = distance;
}