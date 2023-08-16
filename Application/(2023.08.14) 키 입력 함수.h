#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void gotoXY(int x, int y)
{
	// x, y 좌표 설정
	COORD position = { x,y };

	// 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
#pragma region _kbhit() 함수

	//	char key = 0;
	//	int x = 5;
	//	int y = 5;
	//	
	//	// Update()
	//	while (1)
	//	
	//		gotoXY(x, y);
	//		printf("★");
	//	
	//		// 좌표계의 원점이 왼쪽상단에 있기 때문에 
	//		// 아래로 움직이려면 +, 위로 올라가려면 -를 해줘야한다.
	//		
	//	
	//		if (_kbhit()) // 키보드 함수를 확인하는 함수
	//		{
	//			key = _getch();
	//	
	//			if (key == -32)
	//			{
	//				key = _getch();
	//			}
	//	
	//			switch (key)
	//			{
	//			case UP:
	//				if (y <= 0) break;
	//				y--;
	//				break;
	//			case LEFT:
	//				if (x <= 0) break;
	//				x--;
	//				break;
	//			case RIGHT: x++;
	//				break;
	//			case DOWN: y++;
	//				break;
	//			}
	//			// 화면을 지우는 함수
	//			system("cls");
	//		}
	//		// gotoXY(15, 15);
	//		// printf("게임중...\n");
	//		// 
	//		// // Sleep(1) : 1/1000로 계산됩니다.
	//		// Sleep(100);
	//	

#pragma endregion


	return 0;
}