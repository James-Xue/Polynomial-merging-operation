#include "head.h"

int main(int argc, int *argv[])
{
	system("title ����ʽ�ϲ�����ϵͳ");
	pol *firstPol = NULL;
	int cnt = 0,k;//cnt���� 
	while (1)
	{
		system("cls");
		if ((k = menu(&cnt)) == 1)
		{
			printf("������(���磺2x^5+100x^75)��");
			add(&firstPol);//��� 
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
			printf("ָʾ����\n");
			system("pause");
		}
	}
	
	system("pause");
	return 0;
}
