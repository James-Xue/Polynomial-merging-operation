#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct prepol
{
	double coe;
	double ide;
	struct prepol *next;
}pol;//���ϵ����ָ��

int menu(int *n);//��ʾ�˵� 
void add(pol **head);//��Ӷ���ʽ 
void printall(pol **head);//��� 
int correction(double *a,double *b, char *c);//����
void deleteall(pol **head); 
