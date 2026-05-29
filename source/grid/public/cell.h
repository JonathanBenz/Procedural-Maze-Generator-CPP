#pragma once
#include <ostream>
#include <unordered_set>
#include <vector>

class Distances;

class Cell
{
public:
	Cell() = default;                                                     // Default Constructor
	Cell(int row, int column);                                            // Parameterized Constructor
	Cell(const Cell& other) = default;                                    // Copy Constructor
	Cell& operator=(const Cell& other) = default;                         // Copy Assignment
	Cell(Cell&&) noexcept = default;                                      // Move Constructor
	Cell& operator=(Cell&&) noexcept = default;                           // Move Assignment
	~Cell() = default;                                                    // Destructor
	bool operator==(const Cell& other) const;                             // Equality Operator Overload (Required For std::unordered_set)
	friend std::ostream& operator<<(std::ostream& os, const Cell& cell);  // Stream Insertion Operator Overload

	Cell* Link(Cell* cell, bool bidirectional = true);
	Cell* Unlink(Cell* cell, bool bidirectional = true);
	void PrintLinks() const;

public: // GETTERS & SETTERS
	bool IsLinked(Cell* cell) const;
	std::unordered_set<Cell*> GetLinks() { return m_Links; }
	int GetRow() const { return m_Row; }
	int GetColumn() const { return m_Column; }

	Cell* GetNorthNeighbor() const { return m_North; }
	Cell* GetSouthNeighbor() const { return m_South; }
	Cell* GetEastNeighbor() const { return m_East; }
	Cell* GetWestNeighbor() const { return m_West; }
	std::vector<Cell*> GetNeighbors() const;

	Distances GetDistancesFromThisCell();

	void SetNorthNeighbor(Cell* cell) { m_North = cell; }
	void SetSouthNeighbor(Cell* cell) { m_South = cell; }
	void SetEastNeighbor(Cell* cell) { m_East = cell; }
	void SetWestNeighbor(Cell* cell) { m_West = cell; }

private:
	int m_Row{};
	int m_Column{};

	Cell* m_North = nullptr;
	Cell* m_South = nullptr;
	Cell* m_East = nullptr;
	Cell* m_West = nullptr;

	// Using Cell* because pointers already have their own custom hash function for std::unordered_set to use.
	std::unordered_set<Cell*> m_Links; 
};