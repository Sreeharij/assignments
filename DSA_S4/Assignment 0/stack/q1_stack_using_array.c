#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int *arr;
	int max_size;
};

void push(struct stack* s,int x){
	if(s->top+1 == s->max_size){
		printf("STACK OVERFLOW\n");
	}
	else{
		s->top += 1;
		s->arr[s->top] = x;
	}
};

int pop(struct stack* s){
	if(s->top == -1){
		printf("STACK UNDERFLOW\n");
		return -1;
	}
	else{
		s->top -= 1;
		return s->arr[s->top+1];
	}
}

void peek(struct stack* s){
	if(s->top == -1){
		printf("STACK EMPTY\n");
	}
	else{
		printf("%d\n",s->arr[s->top]);
	}
}

void display(struct stack* s){
	int k = s->top;
	while(k>=0){
		printf("%d ",s->arr[k]);
		k--;
	}printf("\n");
}

int main(){
	int max_size = 100;
	struct stack s1;
	s1.arr = (int *)malloc(max_size*sizeof(int));
	s1.top = -1;
	s1.max_size = max_size;
	push(&s1,10);
	push(&s1,20);
	push(&s1,30);
	peek(&s1);
	printf("%d\n",pop(&s1));
	display(&s1);
	

	return 0;
}
