#include <stdio.h>
#include <string.h>

#pragma region 함수 포인터
// 함수의 주소값을 저장하고 가리킬 수 있는 변수입니다.

void Delegate()
{
	printf("대리자~\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Multiple(int x, int y)
{
	return x * y;
}

int Substract(int x, int y)
{
	return x - y;
}

int Divide(int x, int y)
{
	return x / y;
}

void Calculator(int x, int y, int(*cptr)(int, int))
{
	printf("cptr함수의 결과 : %d\n", cptr(x, y));
}

#pragma endregion

int main()
{
#pragma region 함수 포인터

	// 함수 포인터는 함수의 반환형과 매개 변수의 타입이 일치해야 하며,
	// 함수 포인터를 사용하여 동적으로 메모리를 할당할 수 없습니다.
	// void (*fptr)();
	// fptr = Delegate;
	// fptr();

	//int (*cptr)(int, int);
	// cptr = Add;
	// printf("Add함수의 결과: %d\n", cptr(10, 20));
	// 
	// cptr = Substract;
	// printf("Add함수의 결과: %d\n", cptr(10, 20));
	// 
	// cptr = Multiple;
	// printf("Add함수의 결과: %d\n", cptr(10, 20));
	// 
	// cptr = Divide;
	// printf("Add함수의 결과: %d\n", cptr(20, 20));

	// Calculator(10, 20, Substract);
	// Calculator(10, 20, Add);

#pragma endregion

#pragma region 소수 판별 알고리즘
	//	int n;
	//	scanf_s("%d", &n);
	//	bool check = false;
	//	
	//	if (n == 1) check = true;
	//	for (int i = 2; i < n; i++)
	//	{
	//		if (n % i == 0) check = true;
	//	}
	//	if (check == true) printf("소수가 아닙니다.");
	//	else printf("소수 입니다.");

#pragma endregion
#pragma region 회문 판별 알고리즘

	const char* content = "level";
	bool check = false;
	int size = strlen(content);

	for (int i = 0; i < size / 2; i++)
	{
		if (content[i] != content[size - 1 - i])
		{
			check = true;
			break;
		}
	}
	if (check == true) printf("회문이 아닙니다");
	else printf("회문 입니다");
#pragma endregion


	return 0;
}