#include <windows.h>
#include <iostream>

using namespace std;

HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
COORD coord;
WORD wColors[10];

int main()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	/*
	//Cloth
	wColors[0] = BACKGROUND_BLUE;
	wColors[1] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	wColors[2] = 0;
	wColors[3] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	wColors[4] = 0;
	wColors[5] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	wColors[6] = 0;
	wColors[7] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	wColors[8] = BACKGROUND_BLUE;

	//§JÃ¹IC¨È
	wColors[0] = BACKGROUND_RED;
	wColors[1] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	*/

	//France
	wColors[0] = BACKGROUND_BLUE;	
	wColors[1] = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	wColors[2] = BACKGROUND_RED;

	DWORD dwWritten;

	int colorIndex = 0;
	for (int rowIndex = 0; rowIndex < 40; rowIndex++)
		for (int colIndex = 0; colIndex < 120; colIndex += 3)
		{
			/* IC
			if (rowIndex % 2 == 0)
			{
				coord.X = colIndex;
				coord.Y = rowIndex;
				
			}
			else
			{
				if (colIndex == 0)
				{
					coord.X = colIndex;
					coord.Y = rowIndex;
					WriteConsoleOutputAttribute(hStdout, &wColors[1], 1, coord, &dwWritten);
				}
				coord.X = colIndex + 1;
				coord.Y = rowIndex;
			}
			*/

			coord.X = colIndex;
			coord.Y = rowIndex;
			WriteConsoleOutputAttribute(hStdout, wColors, 3, coord, &dwWritten);
			Sleep(10);
		}
	system("pause");
	return 1;
}
