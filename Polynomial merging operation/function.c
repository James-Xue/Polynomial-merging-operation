#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("是否开始输入多项式？\n");
		printf("1.开始输入\t");
		printf("2.展示结果\t");
		printf("3.清空数据\t"); 
		printf("0.退出\n");
	}
	else
	{
		printf("是否继续输入第%d个多项式？\n",*n+1);
		printf("1.继续输入\t");
		printf("2.展示结果\t");
		printf("3.清空数据\t"); 
		printf("0.直接退出\n");
	}
	scanf("%d", &k);
	if (!k)exit(0);
	if(k==1)*n+=1;
	return k;
}

void add(pol **head)
{
	pol *p, *tail,*q;
	double a = 0, b = 0;
	char temp = '\0';
	getchar();
	while (correction(&a, &b, &temp))
	{
		tail = *head;
		p = (pol*)malloc(sizeof(pol));
		p->coe = a;
		p->ide = b;
		p->next = NULL;
		if (*head == NULL)
			*head = p;
		else if ((*head)->ide == b)
		{
			(*head)->coe += a;
			if ((*head)->coe == 0)
			{
				q = (*head);
				(*head) = q->next;
				free(q);
			}
		}
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
				else if (tail->next->ide < b)
				{
					p->next = tail->next;
					tail->next = p;
					break;
				}
				tail = tail->next;
			}
			if (tail->next == NULL)
				tail->next = p;
			else if (tail->next->coe == 0)
			{
				q = tail->next;
				tail->next = q->next;
				free(q);
			}
		}
		a = 0; b = 0;
	}
}

void printall(pol **head)
{
	pol *p = *head;
	int i = 0;
	printf("合并后的结果为：");
	if (p == NULL)printf("0.00\n");
	while (p != NULL)
	{
		if (!i)//首项 
		{
			if(p->ide&&p->ide!=1)//非 常数项 非一次项
			{
				if( p->coe!=1)//系数为1省略 
					printf("%.2f", p->coe);
				printf("x^%.2f",p->ide);
			} 
			else if( p->ide==1)//一次项 
			{ 
				if( p->coe!=1)//系数为1省略 
					printf("%.2f", p->coe);
				printf("x");
			} 
			else printf("%.2f", p->coe);//常数项 
		}
		else//非首项 
		{
			if(p->ide&&p->ide!=1)//非 常数项 非一次项
			{ 
				if ( p->coe!=1)
					printf(" %c%.2fx^%.2f", (p->coe < 0 ? '-' : '+'), fabs(p->coe), p->ide);
				else
					printf(" %cx^%.2f", (p->coe < 0 ? '-' : '+'), p->ide);
			} 
			else if( p->ide==1)//一次项 
			{ 
				if( p->coe!=1)
					printf("%c%.2fx",(p->coe < 0 ? '-' : '+'), fabs(p->coe));
				else
					printf("+x");
			} 
			else //常数项 
				printf("%c%.2f",(p->coe < 0 ? '-' : '+'), fabs(p->coe));
		}
		p = p->next;
		i++;
	}
}
void deleteall(pol **head) 
{
	pol *p = *head, *q;
	while(p)
	{
		q = p; //q保存当前的p
		p = p->next;
		free(q);
	}
}

int correction(double *a, double *b, char *c)//用于发现并 提示或改正错误,以指针返回系数和指数
{
	char temp;
	double tempnum, state = 1;//输入状态 
	int signa = 1, signb = 1;//a b 符号 
	int out = 0, flag = 0;
	if (*c >= '0'&&*c <= '9')
		*a = *c - '0';
	else if (*c == '+')
		signa = 1;
	else if (*c == '-')
		signa = -1;
	else if (*c == '\0' || *c == '.');
	else if (*c == '\n')
		return 0;
	else
	{
		printf("input error!\n");
		system("pause");
		exit(0);
	}
	while (1)
	{
		scanf("%c", &temp);
		switch (temp)
		{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			if (state == 2 || state == 1)
			{
				state = 2;
				*a = *a * 10 + (temp - '0');
			}
			else if (state == 4||state ==3 )
			{
				state=4;
				*b = *b * 10 + (temp - '0');
			}
			break;

		case '.':
			scanf("%lf", &tempnum);
			while (tempnum >= 1)
				tempnum /= 10.0;
			if (state == 2)
				*a += tempnum;
			else if (state == 4)
				*b += tempnum;
			break;

		case '+':
			if (state == 1 && *a == 0)
				signa = 1;
			out = 1; 
			break;

		case '-':
			if (state == 1 && *a == 0)
				signa = -1;
			else
				out = 1;
			break;

		case 'X':case 'x':
			if (state != 1 && state != 2&&state !=3)
			{
				printf("x is at a wrong place!!\n");
				system("pause");
				exit(0);
			}
			if (*a == 0)*a = 1;
			flag = 1;
			state = 3;
			break;

		case '*':
			if (state != 2)
			{
				printf("* is at a wrong place!!\n");
				system("pause");
				exit(0);
			}
			state=3;
			break;

		case '^':
			if (state !=3)
			{
				printf("^ is at a wrong place!\n");
				system("pause");
				exit(0);
			}
			state = 4;
			break;
		case ' ':
			if (state == 2)
				state = 3;
			break;
		case '\n':
			out = 1;
			break;
		default:
			printf("unknown char!\n");
			system("pause");
			exit(0);
		}
		if (out)break;
	}
	
	if (flag&&!*b) *b = 1;
		out = 1;
	*a *= signa; *b *= signb; *c = temp;
	return 1;
}
