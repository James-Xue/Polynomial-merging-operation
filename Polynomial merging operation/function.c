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

void add(pol **head)
{
	pol *p, *tail;
	int a,b;
	
	while (~scanf("%dx^%d", &a, &b))
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
	while (p != NULL)
	{
		if (!i)
			printf("%dx^%d", p->coe, p->ide);
		else
			printf(" %c%dx^%d", (p->coe < 0 ? '-' : '+'), p->coe, p->ide);
		p = p->next;
	}
}