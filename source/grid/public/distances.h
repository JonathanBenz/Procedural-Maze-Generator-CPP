#pragma once
#include <map>
#include <vector>

class Cell;

class Distances
{
public:
	Distances(Cell* root);
	Distances PathTo(Cell* goal);

public: // Getters and Setters
	std::vector<Cell*> GetCells();
	int GetDistanceFrom(Cell* cell);
	int GetDistanceFrom(const Cell* cell) const;

	Cell* GetMaxCell() const;
	int GetMaxDistance() const;

	void SetDistance(Cell* cell, unsigned int distance);

private:
	Cell* m_Root = nullptr;
	std::map<Cell*, unsigned int> m_Cells;
};