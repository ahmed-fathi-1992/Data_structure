#ifndef STACK__H_INCLUDED
#define STACK__H_INCLUDED


#define STACK_BOTTOM 0


typedef enum ERROR{
	OK,
	FAILED
}ERROR;


typedef struct ST_stackInfo{
int *arr_stack;
int stack_ize;
int top_of_stack;

}ST_stackInfo;


ST_stackInfo* createStack(int Size);

ERROR push(ST_stackInfo *info, int data);
ERROR pop (ST_stackInfo *info, int* data);

ERROR checkForBalancedParantheses(char* String);
/*
void createStack(ST_stackInfo *info, int size);
void push(ST_stackInfo *info, int data);
void pop(ST_stackInfo *info, int* data);
*/


#endif // STACK__H_INCLUDED
