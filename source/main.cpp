#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "grid/public/grid.h"
#include "algorithms/public/algorithmcontext.h"

int main()
{
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    /* ========================================================= */
    // Insert Main Code Here
    {
        Grid grid(5, 5);

        AlgorithmContext RandomMazeGenerator;
        RandomMazeGenerator.SetStrategy(MazeAlgorithm::Sidewinder);
        RandomMazeGenerator.ExecuteOn(grid);

        std::cout << grid << std::endl;
    }
    // End Of Program
    /* ========================================================= */
    _CrtDumpMemoryLeaks();
}