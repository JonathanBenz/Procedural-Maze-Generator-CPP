#include "../public/cell.h"
#include <iostream>

Cell::Cell(int row, int column)
{
	m_Row = row;
	m_Column = column;
}

bool Cell::operator==(const Cell& other) const
{
	return m_Row == other.m_Row 
		&& m_Column == other.m_Column;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
	os << "(" << cell.m_Row << ", " << cell.m_Column << ")";
	return os;
}

Cell* Cell::Link(Cell* cell, bool bidirectional)
{
	if (!cell) return nullptr;

	m_Links.insert(cell);
	if (bidirectional) cell->Link(this, false);
	return this;
}

Cell* Cell::Unlink(Cell* cell, bool bidirectional)
{
	if (!cell) return nullptr;

	m_Links.erase(cell);
	if (bidirectional) cell->Unlink(this, false);
	return this;
}

std::vector<Cell*> Cell::GetNeighbors() const
{
	std::vector<Cell*> list;
	if (m_North) list.push_back(m_North);
	if (m_South) list.push_back(m_South);
	if (m_East) list.push_back(m_East);
	if (m_West) list.push_back(m_West);

	return list;
}

void Cell::GetLinks() const
{
	std::cout << "<";
	for (const Cell* cell : m_Links) std::cout << cell << ", ";
	std::cout << ">" << std::endl;
}

bool Cell::IsLinked(Cell* cell) const
{
	// The find() method returns an iterator to the element if it exists. 
	// If it does not exist, it returns the end() iterator. 
	return m_Links.find(cell) != m_Links.end();
}