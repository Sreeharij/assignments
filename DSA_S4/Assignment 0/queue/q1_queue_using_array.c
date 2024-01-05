#include <stdio.h>
#include <stdlib.h>

struct queue{
  int front;
  int rear;
  int* arr;
  int max_size;
};

void enque(struct queue* q,int x){
    if(q->rear+1 == q->max_size){
        printf("QUEUE FULL\n");
        return;
    }
    q->arr[++q->rear] = x;
}

int deque(struct queue* q){
    if(q->front == q->rear){
        return -1;
    }
    else{
        return q->arr[++q->front];
    }
}

void display(struct queue* q){
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }printf("\n");
}

void front(struct queue* q){
    if(q->front+1 <= q->rear){
        printf("front: %d\n",q->arr[q->front+1]);
    }
    else{
        printf("QUEUE EMPTY\n");
    }
}

void rear(struct queue* q){
    if(q->front == q->rear){
        printf("QUEUE EMPTY\n");
    }
    else{
        printf("rear: %d\n",q->arr[q->rear]);
    }
}

int main(){
	int max_size = 100;
	struct queue q;
	q.front = q.rear = -1;
    q.max_size = max_size;
    q.arr = (int *)malloc(max_size * sizeof(int));
    
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    enque(&q,40);
    display(&q);
    deque(&q);
    front(&q);
    rear(&q);
    deque(&q);
    display(&q);
    deque(&q);
    deque(&q);
    display(&q);
    
	
	return 0;
}
