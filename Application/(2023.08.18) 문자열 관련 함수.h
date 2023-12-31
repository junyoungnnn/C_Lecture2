#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77

int seed = 0;

struct Student
{
	int x;
	int y;
	const char* shape;
};

struct Enemy
{
	int x, y;
	const char* shape;
};

int Random()
{
	srand(time(NULL));
	seed = rand() % 31 + 0;

	if (seed % 2 == 1)
	{
		seed += 1;
	}
	return seed;
}


void Keyboard(Student* player)
{
	char key = 0;
	if (_kbhit())
	{
		key = _getch();
		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case LEFT: if ((player->x <= 0)) return;
			player->x -= 2;
			break;
		case RIGHT: if ((player->x >= 28)) return;
			player->x += 2;
			break;
		}
	}
}

void gotoXY(int x, int y)
{
	// x, y 좌표 설정
	COORD position = { x,y };

	// 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
#pragma region  문자열 관련 함수

	// 문자열 길이 함수
	/*
	const char* name = "James";
	int result = strlen(name);

	printf("result의 값 : %d", result);
	*/

	// 문자열 연결 함수
	/*
	char firstArr[20] = "First";
	char secondArr[] = "Second";

	strcat(firstArr, secondArr);

	printf("firstArr의 값 : %s\n", firstArr);
	*/

	// 문자열 복사 함수
	/*
	char a[10] = {"String"};
	char b[10];

	// 첫 번째 매개변수 : 복사받을 문자 배열
	// 두 번쨰 매개변수 : 복사할 문자 배열
	strcpy(b, a);

	printf("a의 문자열 : %s\n", a);
	printf("b의 문자열 : %s\n", b);
	*/

	// 문자열 비교 함수
	/*
	char firstA[] = { "ABC" };
	char secondB[] = { "ABC" };

	// 서로 같으면 "0"
	// 앞 쪽에 있는 값이 크면 "1"
	// 뒤 쪽에 있는 값이 크면 "-1"

	printf("두 문자열을 비교한 결과 : %d\n", strcmp(firstA, secondB));
	*/
#pragma endregion

	system("mode con cols=30 lines=25");

	Random();

	Student player = { 16, 23, "★" };
	Enemy enemy = { seed, 0, "●" };

	while (1)
	{
		Keyboard(&player);

		if (enemy.y >= 24)
		{
			enemy.y = 0;
			enemy.x = Random();
		}

		if (player.x == enemy.x && player.y == enemy.y)
		{
			break;
		}

		gotoXY(enemy.x, enemy.y++);
		printf("%s", enemy.shape);

		gotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");

	}

	return 0;
}