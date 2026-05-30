#pragma once
#include "grid.h"
#include <memory>

class Distances;

class DistanceGrid : public Grid
{
public:
	DistanceGrid() = default;
	DistanceGrid(unsigned int rows, unsigned int columns) : Grid(rows, columns) {}

	void SetDistances(const Distances& distances);

protected:
	virtual std::string GetContentsOf(const Cell* cell) const override;

private:
	std::unique_ptr<Distances> m_Distances;
};