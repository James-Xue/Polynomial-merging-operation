#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("是否开始输入多项式？\n");
		printf("1.是\n");
		printf("0.退出\n");
	}
	else
	{
		printf("是否继续输入多项式？\n");
		printf("1.继续输入\n");
		printf("2.结束输入\n");
		printf("0.直接退出\n");
	}
	scanf("%d", &k);
	if (!k)exit(0);
	*n+=1;
	return k;
}