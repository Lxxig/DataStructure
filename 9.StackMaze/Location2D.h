#pragma once

class Locatin2D
{
public:
	Locatin2D(int row = 0, int column = 0)
		: row(row), column(column)
	{

	}

public:
	int row;  // y
	int column;  // x
};

