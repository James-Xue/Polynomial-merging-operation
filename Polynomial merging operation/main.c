#include "head.h"

int main(int argc, int *argv[])
{
	system("title 多项式合并运算系统");
	pol *firstPol = NULL;
	int cnt = 0;
	while (1)
	{
		system("cls");
		if (menu(&cnt) == 1)
		{
			printf("请输入：");
			add(&firstPol);
		}
		else
		{
			printall(&firstPol);
			printf("\n");
			break;
		}
	}
	free(firstPol);
	system("pause");
	return 0;
}