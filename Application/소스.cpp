#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 11
#define HEIGHT 11

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

struct Player {
	int x;
	int y;
	const char* shape;
};

// ��ǥ �̵� �Լ�
void gotoXY(int x, int y)
{
	// x, y ��ǥ ����
	COORD position = { x,y };

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// �̷� �� ������
char maze[WIDTH][HEIGHT];

// �̷� �� ����
void CreateMaze()
{
	// 0 : �� ����(" ")
	// 1 : ��     ("��")
	// 2 : Ż�ⱸ ("��")
	
		strcpy(maze[0], "1111111111" );
		strcpy(maze[1], "1000000001" );
		strcpy(maze[2], "1000011001" );
		strcpy(maze[3], "1110001111" );
		strcpy(maze[4], "1000001111" );
		strcpy(maze[5], "1000011001" );
		strcpy(maze[6], "1010000011" );
		strcpy(maze[7], "1010110011" );
		strcpy(maze[8], "1000000001" );
		strcpy(maze[9], "1100000111" );
		strcpy(maze[10],"1111211111" );

}

void Renderer()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (maze[i][j] == '0')
				printf("  ");
			else if (maze[i][j] == '1')
				printf("��");
			else if (maze[i][j] == '2')
				printf("��");
		}
		printf("\n");
	}
}

void KeyBoard(char map[WIDTH][HEIGHT], Player* player)
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
		case UP:
			if (map[player->y - 1][player->x / 2] != '1')
			{
				player->y--;
			}
			break;
		case LEFT:
			if (map[player->y][player->x / 2 - 1] != '1')
			{
				player->x -= 2;
			}
			break;
		case RIGHT:
			if (map[player->y][player->x / 2 + 1] != '1')
			{
				player->x += 2;
			}
			break;
		case DOWN:
			if (map[player->y + 1][player->x / 2] != '1')
			{
				player->y++;
			}
			break;
		}
	}
}

int main()
{
	Player player = { 2, 1, "��" };
	CreateMaze();

	while (1)
	{
		Renderer();
		KeyBoard(maze, &player);
		gotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");
	}
	
	return 0;
}