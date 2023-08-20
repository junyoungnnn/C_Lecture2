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
			player -> x -= 2;
			break;
		case RIGHT: if ((player->x >= 28)) return;
			player->x += 2;
			break;
		}
	}
}

void gotoXY(int x, int y)
{
	// x, y ��ǥ ����
	COORD position = { x,y };

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
#pragma region  ���ڿ� ���� �Լ�

	// ���ڿ� ���� �Լ�
	/*
	const char* name = "James";
	int result = strlen(name);

	printf("result�� �� : %d", result);
	*/

	// ���ڿ� ���� �Լ�
	/*
	char firstArr[20] = "First";
	char secondArr[] = "Second";

	strcat(firstArr, secondArr);

	printf("firstArr�� �� : %s\n", firstArr);
	*/

	// ���ڿ� ���� �Լ�
	/*
	char a[10] = {"String"};
	char b[10];

	// ù ��° �Ű����� : ������� ���� �迭
	// �� ���� �Ű����� : ������ ���� �迭
	strcpy(b, a);

	printf("a�� ���ڿ� : %s\n", a);
	printf("b�� ���ڿ� : %s\n", b);
	*/

	// ���ڿ� �� �Լ�
	/*
	char firstA[] = { "ABC" };
	char secondB[] = { "ABC" };

	// ���� ������ "0"
	// �� �ʿ� �ִ� ���� ũ�� "1"
	// �� �ʿ� �ִ� ���� ũ�� "-1"

	printf("�� ���ڿ��� ���� ��� : %d\n", strcmp(firstA, secondB));
	*/
#pragma endregion

	system("mode con cols=30 lines=25");

	Random();

	Student player = { 16, 23, "��" };
	Enemy enemy = { seed, 0, "��" };

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