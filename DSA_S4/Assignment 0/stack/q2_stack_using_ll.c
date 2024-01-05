#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct linked_list{
	struct node* head;
};

struct stack{
	struct linked_list* ll;
};

void push(struct stack* s,int x){
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->val = x;
	t->next = NULL;
	if(s->ll->head == NULL){
		s->ll->head = t;
	}
	else{
		t->next = s->ll->head;
		s->ll->head = t;
	}
}

void display(struct stack* s){
	struct node* ptr = s->ll->head;
	while(ptr){
		printf("%d ",ptr->val);
		ptr = ptr->next;
	}printf("\n");
}

int pop(struct stack* s){
    if(s->ll->head == NULL){
        printf("STACK UNDERFLOW\n");
        return -1;
    }    
    else{
        int val = s->ll->head->val;
        s->ll->head = s->ll->head->next;
        return val;
    }
}

void peek(struct stack* s){
    if(s->ll->head == NULL){
        printf("STACK EMPTY\n");
    }
    else{
        printf("%d\n",s->ll->head->val);
    }
}

int main(){
	struct stack s;
	s.ll = (struct linked_list*)malloc(sizeof(struct linked_list));
	s.ll->head = NULL;
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	push(&s,50);
	display(&s);
	pop(&s);
	pop(&s);
	peek(&s);

	
	return 0;
}
