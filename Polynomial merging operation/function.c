#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("�Ƿ�ʼ�������ʽ��\n");
		printf("1.��\n");
		printf("0.�˳�\n");
	}
	else
	{
		printf("�Ƿ�����������ʽ��\n");
		printf("1.��������\n");
		printf("2.��������\n");
		printf("0.ֱ���˳�\n");
	}
	scanf("%d", &k);
	if (!k)exit(0);
	*n+=1;
	return k;
}