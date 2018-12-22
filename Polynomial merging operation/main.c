#include "head.h"

int main(int argc, int *argv[])
{
	system("title 多项式合并运算系统");
	pol *firstPol = NULL;
	int cnt = 0;
	while (1)
	{
		switch (menu(&cnt))
		{
			case 1:add(&firstPol); break;
			case 2:printall(&firstPol); exit(0);
		}
		system("cls");
	}
	system("pause");
	return 0;
}