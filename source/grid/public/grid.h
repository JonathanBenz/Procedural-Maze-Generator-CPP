#pragma once
#include <vector>
#include<ostream>

class Cell;

class Grid
{
public:
	Grid();
	Grid(unsigned int rows, unsigned int columns);
	virtual ~Grid();
	friend std::ostream& operator<<(std::ostream& os, const Grid& grid);

	template <typename Func>
	void EachRow(Func&& fn)
	{
		for (unsigned int row = 0; row < m_Rows; row++)
		{
			fn(GetCell(row, 0));
		}
	}

	template <typename Func>
	void EachCell(Func&& fn)
	{
		for (Cell* cell : m_Grid)
		{
			fn(cell);
		}
	}

public: // GETTERS & SETTERS
	unsigned int GetTotalRows() const { return m_Rows; }
	unsigned int GetTotalColumns() const { return m_Columns; }
	unsigned int GetSize() const { return m_Rows * m_Columns; }

	Cell* GetRandomCell();
	const Cell* GetRandomCell() const;

protected:
	virtual void PrepareGrid();
	virtual void ConfigureCells();

	virtual Cell* GetCell(int row, int column);
	virtual const Cell* GetCell(int row, int column) const;

private:
	unsigned int m_Rows{};
	unsigned int m_Columns{};

	// Flattened 2D Dynamic Array
	std::vector<Cell*> m_Grid;
};