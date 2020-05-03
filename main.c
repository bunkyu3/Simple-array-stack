#include<stdio.h>
#include<stdlib.h>

struct ArrayStack{
	int top;		//スタックのトップの位置
	int capacity;	//スタックの段数
	int *array;
};

struct ArrayStack *CreateStack(void);
int IsEmptyStack(struct ArrayStack *S);
int IsFullStack(struct ArrayStack *S);
void Push(struct ArrayStack *S, int data);
int Pop(struct ArrayStack *S);
void PrintStack(struct ArrayStack *S);
void DeleteStack(struct ArrayStack *S);

int main(void){
	struct ArrayStack *S;
	int data;

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
	data = Pop(S);
	printf("data %d is removed\n", data);
	PrintStack(S);
	DeleteStack(S);
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

int IsEmptyStack(struct ArrayStack *S){
	return (S->top == -1);
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

int Pop(struct ArrayStack *S){
	if(IsEmptyStack(S)){
		printf("Stack is empty\n");
	}else{
		S->top--;
		return S->array[S->top+1];
	}
}

void PrintStack(struct ArrayStack *S){
	int i;
	if(S->capacity == 0){
		printf("There is no stack\n");
	}else{
		for(i=0; i<=S->top; i++){
			printf("%d\n", S->array[i]);
		}
	}
}

void DeleteStack(struct ArrayStack *S){
	if(S){
		if(S->array){
			free(S->array);
		}
		free(S);
	}
}
