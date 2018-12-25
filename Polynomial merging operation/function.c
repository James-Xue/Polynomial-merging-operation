#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("是否开始输入多项式？\n");
		printf("1.是\t");
		printf("0.退出\n");
	}
	else
	{
		printf("是否继续输入第%d个多项式？\n",*n+1);
		printf("1.继续输入\t");
		printf("2.结束输入\t");
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
	if (p == NULL)printf("用户未输入。\n");
	else printf("合并后的结果为：");
	while (p != NULL)
	{
		if (!i)
		{
			if(p->ide)//非 常数项
				printf("%dx^%d", p->coe, p->ide);
			else printf("%d", p->coe);
		}
		else
		{
			if(p->ide)//非 常数项
			printf(" %c%dx^%d", (p->coe < 0 ? '-' : '+'), p->coe, p->ide);
			else printf("%c%d", (p->coe < 0 ? '-' : '+'), p->coe);
		}
		p = p->next;
		i++;
	}
}

int correction(int *a, int *b)//用于发现并 提示或改正错误,以指针返回系数和指数
{
	scanf("%dX^%d", a, b);
	return *a;
}