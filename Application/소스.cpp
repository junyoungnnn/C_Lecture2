#include <stdio.h>
#include <string.h>

#pragma region �Լ� ������
// �Լ��� �ּҰ��� �����ϰ� ����ų �� �ִ� �����Դϴ�.

void Delegate()
{
	printf("�븮��~\n");
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
	printf("cptr�Լ��� ��� : %d\n", cptr(x, y));
}

#pragma endregion

int main()
{
#pragma region �Լ� ������

	// �Լ� �����ʹ� �Լ��� ��ȯ���� �Ű� ������ Ÿ���� ��ġ�ؾ� �ϸ�,
	// �Լ� �����͸� ����Ͽ� �������� �޸𸮸� �Ҵ��� �� �����ϴ�.
	// void (*fptr)();
	// fptr = Delegate;
	// fptr();

	//int (*cptr)(int, int);
	// cptr = Add;
	// printf("Add�Լ��� ���: %d\n", cptr(10, 20));
	// 
	// cptr = Substract;
	// printf("Add�Լ��� ���: %d\n", cptr(10, 20));
	// 
	// cptr = Multiple;
	// printf("Add�Լ��� ���: %d\n", cptr(10, 20));
	// 
	// cptr = Divide;
	// printf("Add�Լ��� ���: %d\n", cptr(20, 20));

	// Calculator(10, 20, Substract);
	// Calculator(10, 20, Add);

#pragma endregion

#pragma region �Ҽ� �Ǻ� �˰���
	//	int n;
	//	scanf_s("%d", &n);
	//	bool check = false;
	//	
	//	if (n == 1) check = true;
	//	for (int i = 2; i < n; i++)
	//	{
	//		if (n % i == 0) check = true;
	//	}
	//	if (check == true) printf("�Ҽ��� �ƴմϴ�.");
	//	else printf("�Ҽ� �Դϴ�.");

#pragma endregion
#pragma region ȸ�� �Ǻ� �˰���

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
	if (check == true) printf("ȸ���� �ƴմϴ�");
	else printf("ȸ�� �Դϴ�");
#pragma endregion


	return 0;
}