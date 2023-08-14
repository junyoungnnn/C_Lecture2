#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seed = 0;
int number = 0;
int hp = 0;


void Init()
{
	srand(time(NULL));

	hp = 5;
	seed = rand() % 50 + 1;
}

void Update()
{
	printf("���� �Է����ּ���. ");
	scanf_s("%d", &number);
}

void Rander()
{
	if (seed == number)
	{
		printf("�����Դϴ�\n");
		exit(1);
	}
	else if (seed < number)
	{
		printf("DOWN\n");
		hp--;
	}
	else
	{
		printf("UP\n");
		hp--;
	}
}

void Defeat()
{
	if (hp <= 0)
	{
		printf("\n");
		printf("���ӿ��� �й��Ͽ����ϴ�\n");
		printf("������ %d�Դϴ�\n", seed);
		exit(1);
	}
}

void Life()
{
	printf("ü���� %d���ҽ��ϴ�\n", hp);
	printf("\n");
}




int main()
{
#pragma region ���� �Լ�
	// 0~32767 ������ ���� ���� ��ȯ�ϴ� �Լ��Դϴ�.

	//	int seed = 0;
	//	// 1970�� 1�� 1��~
	//	srand(time(NULL));
	//	
	//	for (int i = 0; i < 10; i++)
	//	{
	//		seed = rand() % 10 + 1;
	//		printf("seed�� �� : %d\n", seed);
	//	}

#pragma endregion



#pragma region UP-DOWN GAME

	//���� ������ �ʰ�ȭ
	Init();

	while (1)
	{
		// ���� ������Ʈ �Լ�
		Update();

		// ���� ������ �Լ�
		Rander();

		// ���� �й� �Լ�
		Defeat();

		// ü�� ǥ��
		Life();
	}

#pragma endregion


	return 0;
}