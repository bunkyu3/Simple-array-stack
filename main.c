#include<stdio.h>
#include<stdlib.h>

struct ArrayStack{
	int top;		//スタックのトップの位置
	int capacity;	//スタックの段数
	int *array;
};

struct ArrayStack *CreateStack(void);
int IsFullStack(struct ArrayStack *S);
void Push(struct ArrayStack *S, int data);
void PrintStack(struct ArrayStack *S);

int main(void){
	struct ArrayStack *S;

	S = CreateStack();
	if(S==NULL){
		printf("Stack can not be created\n");
		return 0;
	}
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	Push(S, 6);
	PrintStack(S);
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

int IsFullStack(struct ArrayStack *S){
	return (S->top == S->capacity-1);
}

void Push(struct ArrayStack *S, int data){
	if(IsFullStack(S)){
		printf("Stack Overflow\n");
	}else{
		S->top++;
		S->array[S->top] = data;
	}
}

void PrintStack(struct ArrayStack *S){
	int i;
	for(i=0; i<=S->top; i++){
		printf("%d\n", S->array[i]);
	}
}

