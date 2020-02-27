#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctime>
typedef struct NODE NODE;
typedef struct STACK
{
	NODE* pTop;
	NODE* pBottom;
}STACK;

struct NODE
{
	int data;
	struct NODE* pNext;
};
void init_stack(STACK* s);
void push_stack(STACK* s,int num);
void pop_stack(STACK* s);
void show_stack(STACK s);
void test01()
{
	STACK s;
	init_stack(&s);
	for (int i = 0; i < 5; i++)
	{
		push_stack(&s, rand()%10);
	}
	show_stack(s);
	printf("-------------\r\n");
	pop_stack(&s);
	show_stack(s);
	printf("-------------\r\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();
	return 0;
}
void init_stack(STACK* s)
{
	s->pTop = (NODE*)malloc(sizeof(NODE));
	if (s->pTop == NULL)
	{
		printf("分配内存错误\r\n");
		exit(-1);
	}
	s->pTop->pNext = NULL;
	s->pBottom = s->pTop;
}
void push_stack(STACK* s,int num)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("分配内存错误\r\n");
		exit(-1);
	}
	temp->data = num;
	temp->pNext = s->pTop;
	s->pTop = temp;
}
void pop_stack(STACK* s)
{
	NODE* temp = s->pTop;
	s->pTop = s->pTop->pNext;
	free(temp);
}
void show_stack(STACK s)
{
	NODE* temp = s.pTop;
	while (temp->pNext != s.pBottom->pNext)
	{
		printf("数据为：%d\r\n", temp->data);
		temp = temp->pNext;
	}
}












