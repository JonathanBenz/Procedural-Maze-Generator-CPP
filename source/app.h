#pragma once
#include "grid/public/grid.h"
#include "algorithms/public/algorithmcontext.h"
#include <iostream>

class App
{
public:
    App(Grid& grid, AlgorithmContext& algo) : m_Grid(grid), m_Algo(algo) {}
    void GenerateMaze()
    {
        m_Algo.ExecuteOn(m_Grid);
        m_Grid.UploadVertices();
        //std::cout << m_Grid << std::endl;
    }

private:
    Grid& m_Grid;
    AlgorithmContext& m_Algo;
};