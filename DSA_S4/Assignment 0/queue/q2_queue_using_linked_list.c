#include <stdio.h>
#include <stdlib.h>

struct node{
  int val;
  struct node* next;
};

struct linked_list{
  struct node* front;
  struct node* rear;
};

struct queue{
  struct linked_list* ll;
};

void enque(struct queue* q,int x){
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->val = x;
    t->next = NULL;
    if(q->ll->front == NULL){
        q->ll->front = t;
        q->ll->rear = t;
    }
    else{
        q->ll->rear->next = t;
        q->ll->rear = t;
    }
}

int deque(struct queue* q){
    if(q->ll->front == NULL){
        printf("QUEUE UNDERFLOW\n");
        return -1;
    }
    else{
        int val = q->ll->front->val;
        q->ll->front = q->ll->front->next;
        return val;
    }
}

void display(struct queue* q){
    struct node* ptr = q->ll->front;
    while(ptr){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }printf("\n");
}

void front(struct queue* q){
    if(q->ll->front == NULL){
        printf("QUEUE EMPTY\n");
    }
    else{
        printf("%d\n",q->ll->front->val);
    }
}

void rear(struct queue* q){
    if(q->ll->front == NULL){
        printf("QUEUE EMPTY\n");
    }
    else{
        printf("%d\n",q->ll->rear->val);
    }
}

int main(){
	struct queue q;
	q.ll = (struct linked_list*)malloc(sizeof(struct linked_list));
	q.ll->front = NULL;
	q.ll->rear = NULL;
	enque(&q,10);
	enque(&q,20);
	enque(&q,30);
	enque(&q,40);
	display(&q);
	deque(&q);
	deque(&q);
	front(&q);
	rear(&q);
	display(&q);
	return 0;
}
