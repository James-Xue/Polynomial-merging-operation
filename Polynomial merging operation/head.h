#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct prepol
{
	double coe;
	double ide;
	struct prepol *next;
}pol;//存放系数和指数

int menu(int *n);//显示菜单 
void add(pol **head);//添加多项式 
void printall(pol **head);//输出 
int correction(double *a,double *b, char *c);//输入
void deleteall(pol **head); 
