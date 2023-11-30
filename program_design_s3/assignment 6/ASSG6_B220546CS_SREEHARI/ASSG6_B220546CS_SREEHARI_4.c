//INEFFICIENT IMPLEMENTATION SINCE QUEUE DOESNT HAVE MUCH RELEVENCE HERE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int head,tail,size;
    int *array;
};

int queue_empty(struct Queue* current_queue){
    if(current_queue->head == -1){
        return -1;
    }
    return 1;
}

int queue_full(struct Queue* current_queue){
    if((current_queue->tail + 1)%current_queue->size == current_queue->head){
        return -1;
    }
    return 1;
}

void enqueue(struct Queue* current_queue,int val){
    if(queue_full(current_queue) == -1){
        return;
    }
    if(queue_empty(current_queue) == -1){
        current_queue->head = 0;
    }

    current_queue->tail = (current_queue->tail + 1) % current_queue->size;
    current_queue->array[current_queue->tail] = val;
}

int dequeue(struct Queue* current_queue){
    if(queue_empty(current_queue) == -1){
        return -1;
    }
    int val = current_queue->array[current_queue->head];
    if(current_queue->head == current_queue->tail){
        current_queue->head = current_queue->tail = -1;
    }
    else{
        current_queue->head = (current_queue->head + 1) % current_queue->size;
    }
    return val;
}

void reverse_k(struct Queue* current_queue,int k){
    int temp_arr[k];
    for(int i=k-1;i>=0;i--){
        temp_arr[i] = dequeue(current_queue);
    }
    for(int i=0;i<k;i++){
        enqueue(current_queue,temp_arr[i]);
    }
    current_queue->head = 0;
    current_queue->tail = current_queue->size - 1;
    for(int i=0;i<current_queue->size;i++){
        printf("%d ",current_queue->array[i]);
    }printf("\n");
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct Queue current_queue;
    current_queue.head = current_queue.tail = -1;
    current_queue.size = n;
    current_queue.array = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        enqueue(&current_queue,arr[i]);
    }
    reverse_k(&current_queue,k);

    return 1;
}