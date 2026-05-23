#include "../public/algorithmcontext.h"
#include "../../grid/public/grid.h"
#include "../public/imazealgorithms.h"
#include "../public/binarytreestrategy.h"
#include "../public/sidewinderstrategy.h"

void AlgorithmContext::SetStrategy(MazeAlgorithm algorithm)
{
	switch (algorithm)
	{
	case MazeAlgorithm::BinaryTree:
		m_Strategy = std::make_unique<BinaryTreeStrategy>();
		break;

	case MazeAlgorithm::Sidewinder:
		m_Strategy = std::make_unique<SidewinderStrategy>();
		break;
	}
}

void AlgorithmContext::ExecuteOn(Grid& grid)
{
	m_Strategy->GenerateMaze(grid);
}