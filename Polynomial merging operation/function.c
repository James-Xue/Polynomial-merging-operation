#include "head.h"

int menu(int *n)
{
	int k;
	if (!*n)
	{
		printf("�Ƿ�ʼ�������ʽ��\n");
		printf("1.��ʼ����\t");
		printf("2.չʾ���\t");
		printf("3.�������\t"); 
		printf("0.�˳�\n");
	}
	else
	{
		printf("�Ƿ���������%d������ʽ��\n",*n+1);
		printf("1.��������\t");
		printf("2.չʾ���\t");
		printf("3.�������\t"); 
		printf("0.ֱ���˳�\n");
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
	printf("�ϲ���Ľ��Ϊ��");
	if (p == NULL)printf("0.00\n");
	while (p != NULL)
	{
		if (!i)//���� 
		{
			if(p->ide&&p->ide!=1)//�� ������ ��һ����
			{
				if( p->coe!=1)//ϵ��Ϊ1ʡ�� 
					printf("%.2f", p->coe);
				printf("x^%.2f",p->ide);
			} 
			else if( p->ide==1)//һ���� 
			{ 
				if( p->coe!=1)//ϵ��Ϊ1ʡ�� 
					printf("%.2f", p->coe);
				printf("x");
			} 
			else printf("%.2f", p->coe);//������ 
		}
		else//������ 
		{
			if(p->ide&&p->ide!=1)//�� ������ ��һ����
			{ 
				if ( p->coe!=1)
					printf(" %c%.2fx^%.2f", (p->coe < 0 ? '-' : '+'), fabs(p->coe), p->ide);
				else
					printf(" %cx^%.2f", (p->coe < 0 ? '-' : '+'), p->ide);
			} 
			else if( p->ide==1)//һ���� 
			{ 
				if( p->coe!=1)
					printf("%c%.2fx",(p->coe < 0 ? '-' : '+'), fabs(p->coe));
				else
					printf("+x");
			} 
			else //������ 
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
		q = p; //q���浱ǰ��p
		p = p->next;
		free(q);
	}
}

int correction(double *a, double *b, char *c)//���ڷ��ֲ� ��ʾ���������,��ָ�뷵��ϵ����ָ��
{
	char temp;
	double tempnum, state = 1;//����״̬ 
	int signa = 1, signb = 1;//a b ���� 
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
