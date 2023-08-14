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
	printf("값을 입력해주세요. ");
	scanf_s("%d", &number);
}

void Rander()
{
	if (seed == number)
	{
		printf("정답입니다\n");
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
		printf("게임에서 패배하였습니다\n");
		printf("정답은 %d입니다\n", seed);
		exit(1);
	}
}

void Life()
{
	printf("체력이 %d남았습니다\n", hp);
	printf("\n");
}




int main()
{
#pragma region 랜덤 함수
	// 0~32767 사이의 난수 값을 반환하는 함수입니다.

	//	int seed = 0;
	//	// 1970년 1월 1일~
	//	srand(time(NULL));
	//	
	//	for (int i = 0; i < 10; i++)
	//	{
	//		seed = rand() % 10 + 1;
	//		printf("seed의 값 : %d\n", seed);
	//	}

#pragma endregion



#pragma region UP-DOWN GAME

	//게임 데이터 초가화
	Init();

	while (1)
	{
		// 게임 업데이트 함수
		Update();

		// 게임 렌더링 함수
		Rander();

		// 게임 패배 함수
		Defeat();

		// 체력 표시
		Life();
	}

#pragma endregion


	return 0;
}