#include <iostream>
#include "Stack.h"
#include "Location2D.h"

// Sleep(�и� ������)
#include <Windows.h>

const size_t MAZE_SIZE = 20;
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
	{'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// �̵��Ϸ��� ��ġ�� ��ȿ�� ��ġ���� Ȯ��.
bool IsValidLocation(int row, int column)
{
	// ���� ������ ������� Ȯ��.
	// ���� ������ ����.
	if (row >= MAZE_SIZE || column >= MAZE_SIZE || row < 0 || column < 0) return false;

	// ��ȿ�� Ȯ��.
	return map[row][column] == '0' || map[row][column] == 'e';
}

// ȭ�� ����� �Լ�. -> cls�� ����ص� ������, ���ڿ��� ����ؼ� �غ�.
void ClearScreen()
{
	// Ŀ�� ���� ������ ���� ����ü ����.
	CONSOLE_CURSOR_INFO info = { };
	info.dwSize = 1;
	info.bVisible = FALSE;

	// �ܼ� ��� ���� �ڵ�(������) ��������.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� ������(�Ⱥ��̰� �ϱ�).
	SetConsoleCursorInfo(handle, & info);

	// ȭ�� ��ǥ �ű��.
	SetConsoleCursorPosition(handle, { 0, 0 });

	// �� ���� ���.
	for (int y = 0; y < MAZE_SIZE; ++y)
	{
		for (int x = 0; x < MAZE_SIZE; ++x)
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
	SetConsoleCursorPosition(handle, { 0, 0 });
}

// �� ��� �Լ�.
void PrintLocation(int row, int column, int delay)
{
	// ������. delay/1000 ��
	Sleep(delay);

	// ȭ�� �����;
	ClearScreen();

	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// ���� �湮���� ��ġ�� Ư�� ���ڷ� ���. 
			if (i == row && j == column)
			{
				std::cout << "p ";
				continue;
			}

			// ���.
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	// ���� ��ġ �˻�.
	int startRow = 0;
	int startColumn = 0;

	// �̷��� ���� ��ġ ã��.
	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			std::cout << map[i][j] << " ";
			// ���� ��ġ ����
			if (map[i][j] == 's')
			{
				startRow = i;
				startColumn = j;
			}
		}
		std::cout << "\n";
	}

	// ���� �������� Ž���ϱ� ���� ���ÿ� ����.
	Stack<Locatin2D> stack;
	stack.Push(Locatin2D(startRow, startColumn));

	// �̷� Ž��.
	while (!stack.IsEmpty())
	{
		// ���� �ֻ����� �ִ� ��ġ ��ȯ.
		Locatin2D current;
		stack.Pop(current);

		int row = current.row;
		int column = current.column;

		// Ž���� ��ġ�� ���.
		/*std::cout << "(" << row << ","  << column << ") ";*/
		PrintLocation(row, column, 300);

		// �����ߴ��� Ȯ��.
		if (map[row][column] == 'e')
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return 0;
		}

		// �湮�� ���� ���ڷ� ����.
		map[row][column] = '.';

		// �� / �� / �� / �� ��ġ �� �̵� ������ ��ġ�� ���ÿ� ����.
		if (IsValidLocation(row - 1, column))
		{
			stack.Push(Locatin2D(row - 1, column));
		}
		if (IsValidLocation(row + 1, column))
		{
			stack.Push(Locatin2D(row + 1, column));
		}
		if (IsValidLocation(row, column - 1))
		{
			stack.Push(Locatin2D(row, column - 1));
		}
		if (IsValidLocation(row, column + 1))
		{
			stack.Push(Locatin2D(row, column + 1));
		}

	}

	std::cout << "�̷� Ž�� ����\n";
}