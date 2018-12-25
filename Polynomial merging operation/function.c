#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("�Ƿ�ʼ�������ʽ��\n");
		printf("1.��\t");
		printf("0.�˳�\n");
	}
	else
	{
		printf("�Ƿ���������%d������ʽ��\n",*n+1);
		printf("1.��������\t");
		printf("2.��������\t");
		printf("0.ֱ���˳�\n");
	}
	scanf("%d", &k);
	if (!k)exit(0);
	*n+=1;
	return k;
}

void add(pol **head)
{
	pol *p, *tail;
	int a,b;
	
	while (correction(&a, &b))
	{
		tail = *head;
		p = (pol*)malloc(sizeof(pol));
		p->coe = a;
		p->ide = b;
		p->next = NULL;
		if (*head == NULL)
			*head = p;
		else if(tail->ide==b)
			tail->coe += a;
		else if (tail->ide < b)
		{
			p->next = tail;
			*head = p;
		}
		else
		{
			while (tail->next != NULL)
			{
				if (tail->next->ide == b)
				{
					tail->next->coe += a;
					break;
				}
				if (tail->next->ide < b)
				{
					p->next = tail->next;
					tail->next = p;
					break;
				}
				tail = tail->next;
			}
			if (tail->next == NULL)
				tail->next = p;
		}
	}
}

void printall(pol **head)
{
	pol *p = *head;
	int i = 0;
	if (p == NULL)printf("�û�δ���롣\n");
	else printf("�ϲ���Ľ��Ϊ��");
	while (p != NULL)
	{
		if (!i)
		{
			if(p->ide)//�� ������
				printf("%dx^%d", p->coe, p->ide);
			else printf("%d", p->coe);
		}
		else
		{
			if(p->ide)//�� ������
			printf(" %c%dx^%d", (p->coe < 0 ? '-' : '+'), p->coe, p->ide);
			else printf("%c%d", (p->coe < 0 ? '-' : '+'), p->coe);
		}
		p = p->next;
		i++;
	}
}

int correction(int *a, int *b)//���ڷ��ֲ� ��ʾ���������,��ָ�뷵��ϵ����ָ��
{
	scanf("%dX^%d", a, b);
	return *a;
}