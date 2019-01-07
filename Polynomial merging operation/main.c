#include "head.h"

int main(int argc, int *argv[])
{
	system("title 多项式合并运算系统");
	pol *firstPol = NULL;
	int cnt = 0,k;//cnt计数 
	while (1)
	{
		system("cls");
		if ((k = menu(&cnt)) == 1)
		{
			printf("请输入(例如：2x^5+100x^75)：");
			add(&firstPol);//添加 
			system("pause");
		}
		else if (k == 3)
		{
			deleteall(&firstPol);//free
			firstPol = NULL;
		}
		else if (k == 0)
		{
			deleteall(&firstPol);//free 
			exit(0);
		}
		else if (k == 2)
		{
			printall(&firstPol);
			printf("\n");
			system("pause");
		}
		else
		{
			printf("指示错误！\n");
			system("pause");
		}
	}
	
	system("pause");
	return 0;
}
