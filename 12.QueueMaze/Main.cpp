#include <iostream>
#include "Queue.h"
#include "Location2D.h"

// Sleep(밀리 세컨드)
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

// 이동하려는 위치가 유효한 위치인지 확인.
bool IsValidLocation(int row, int column)
{
	// 맵의 범위를 벗어났는지 확인.
	// 벗어 났으면 오류.
	if (row >= MAZE_SIZE || column >= MAZE_SIZE || row < 0 || column < 0) return false;

	// 유효성 확인.
	return map[row][column] == '0' || map[row][column] == 'e';
}

// 화면 지우는 함수. -> cls를 사용해도 되지만, 빈문자열을 사용해서 해봄.
void ClearScreen()
{
	// 커서 정보 설정을 위한 구조체 변수.
	CONSOLE_CURSOR_INFO info = { };
	info.dwSize = 1;
	info.bVisible = FALSE;

	// 콘솔 제어를 위한 핸들(포인터) 가져오기.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 가리기(안보이게 하기).
	SetConsoleCursorInfo(handle, & info);

	// 화면 좌표 옮기기.
	SetConsoleCursorPosition(handle, { 0, 0 });

	// 빈 문자 찍기.
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

// 맵 출력 함수.
void PrintLocation(int row, int column, int delay)
{
	// 딜레이. delay/1000 초
	Sleep(delay);

	// 화면 지우기;
	ClearScreen();

	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			// 현재 방문중인 위치를 특정 문자로 출력. 
			if (i == row && j == column)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "p ";
				continue;
			}

			// 마지막에 설정된 색상으로 됨.
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			// 출력.
			// 형광 녹색 배경에 하얀 텍스트
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int main()
{
	// 시작 위치 검색.
	int startRow = 0;
	int startColumn = 0;

	// 미로의 시작 위치 찾기.
	for (int i = 0; i < MAZE_SIZE; ++i)
	{
		for (int j = 0; j < MAZE_SIZE; ++j)
		{
			std::cout << map[i][j] << " ";
			// 시작 위치 저장
			if (map[i][j] == 's')
			{
				startRow = i;
				startColumn = j;
			}
		}
		std::cout << "\n";
	}

	// 시작 지점부터 탐색하기 위해 큐에 삽입.
	Queue<Locatin2D> queue;
	queue.Enqueue(Locatin2D(startRow, startColumn));

	// 미로 탐색.
	while (!queue.IsEmpty())
	{
		// 큐 맨앞에 있는 위치 반환.
		Locatin2D current;
		queue.Dequeue(current);

		int row = current.row;
		int column = current.column;

		// 탐색한 위치를 출력.
		/*std::cout << "(" << row << ","  << column << ") ";*/
		PrintLocation(row, column, 300);

		// 도착했는지 확인.
		if (map[row][column] == 'e')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
			std::cout << "\n미로 탐색 성공\n";
			return 0;
		}

		// 방문한 곳은 문자로 설정.
		map[row][column] = '.';

		// 상 / 하 / 좌 / 우 위치 중 이동 가능한 위치를 큐에 삽입.
		if (IsValidLocation(row - 1, column))
		{
			queue.Enqueue(Locatin2D(row - 1, column));
		}
		if (IsValidLocation(row + 1, column))
		{
			queue.Enqueue(Locatin2D(row + 1, column));
		}
		if (IsValidLocation(row, column - 1))
		{
			queue.Enqueue(Locatin2D(row, column - 1));
		}
		if (IsValidLocation(row, column + 1))
		{
			queue.Enqueue(Locatin2D(row, column + 1));
		}

	}

	std::cout << "미로 탐색 실패\n";
}