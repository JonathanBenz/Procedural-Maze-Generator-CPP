#include "../public/algorithmcontext.h"
#include "../../grid/public/grid.h"
#include "../public/imazealgorithms.h"
#include "../public/binarytreestrategy.h"

void AlgorithmContext::SetStrategy(MazeAlgorithm algorithm)
{
	switch (algorithm)
	{
	case MazeAlgorithm::BinaryTree:
		m_Strategy = std::make_unique<BinaryTreeStrategy>();
		break;

	case MazeAlgorithm::SideWinder:

		break;
	}
}

void AlgorithmContext::ExecuteOn(Grid& grid)
{
	m_Strategy->GenerateMaze(grid);
}