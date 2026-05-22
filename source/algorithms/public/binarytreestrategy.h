#pragma once
#include "../public/imazealgorithms.h"

class BinaryTreeStrategy : public IMazeAlgorithm
{
public:
	virtual void GenerateMaze(Grid& grid) override;
	virtual void ApplyAlgorithm(Cell* cell) override;
};