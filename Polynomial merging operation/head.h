#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct prepol
{
	int coe;
	int ide;
	struct prepol *next;
}pol;//存放系数和指数

int menu(int *n);
void add(pol **head);
void printall(pol **head);
int correction(int *a,int *b);