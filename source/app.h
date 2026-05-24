#pragma once
#include "grid/public/grid.h"
#include "algorithms/public/algorithmcontext.h"

class App
{
public:
    App(Grid& grid, AlgorithmContext& algo) : m_Grid(grid), m_Algo(algo) {}
    void RegenerateMaze()
    {
        m_Algo.ExecuteOn(m_Grid);
        m_Grid.UploadVertices();
    }

private:
    Grid& m_Grid;
    AlgorithmContext& m_Algo;
};