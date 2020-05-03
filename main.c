#include<stdio.h>
#include<stdlib.h>

struct ArrayStack{
	int top;		//スタックのトップの位置
	int capacity;	//スタックの段数
	int *array;
};

struct ArrayStack *CreateStack(void);

int main(void){
	struct ArrayStack *S;

	S = CreateStack();
	if(S==NULL){
		printf("Stack can not be created\n");
		return 0;
	}
	return 0;
}

struct ArrayStack *CreateStack(void){
	struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
	if(!S) return NULL;
	S->capacity = 5;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if(!S->array) return NULL;
	return S;
}
