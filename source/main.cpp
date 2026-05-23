#include <iostream>
#define _CRTDBG_MAP_ALLOC  // For dumping memory leaks
#include <stdlib.h>        // For dumping memory leaks
#include <crtdbg.h>        // For dumping memory leaks
#include "utils.h"
#include "grid/public/grid.h"
#include "algorithms/public/algorithmcontext.h"

int main()
{
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);

	if (Utils::InitOpenGL() == -1) return -1;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FRAMEBUFFER_SRGB);

    /* ========================================================= */
    /* Insert Main Code Here */
    {
        Grid grid(5, 5);

        AlgorithmContext RandomMazeGenerator;
        RandomMazeGenerator.SetStrategy(MazeAlgorithm::Sidewinder);
        RandomMazeGenerator.ExecuteOn(grid);

        std::cout << grid << std::endl;

        Utils::UpdateLoop();
    }
    /* End Of Program */
    /* ========================================================= */
    glfwTerminate();
    _CrtDumpMemoryLeaks();
}