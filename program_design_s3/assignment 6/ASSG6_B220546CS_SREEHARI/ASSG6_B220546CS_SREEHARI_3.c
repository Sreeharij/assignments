#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int head;
    int tail;
    int size;
    char** words_array;
};

int QUEUE_EMPTY(struct Queue* current_queue){
    if(current_queue->head == -1){
        return -1;
    }
    return 1;
}

int QUEUE_FULL(struct Queue* current_queue){
    if((current_queue->tail + 1)%current_queue->size == current_queue->head){
        return -1;
    }
    return 1;
}

void enqueue(struct Queue* current_queue,char* word){
    if(QUEUE_FULL(current_queue) == -1){
        printf("-1\n");
        return;
    }
    if(QUEUE_EMPTY(current_queue) == -1){
        current_queue->head = 0;
    }
    current_queue->tail = (current_queue->tail + 1) % current_queue->size;
    strcpy(current_queue->words_array[current_queue->tail],word);
}

void dequeue(struct Queue* current_queue){
    if(QUEUE_EMPTY(current_queue) == -1){
        printf("-1\n");
        return;
    }
    char* word = current_queue->words_array[current_queue->head];
    if(current_queue->head == current_queue->tail){
        current_queue->head = -1;
        current_queue->tail = -1;
    }
    else{
        current_queue->head = (current_queue->head + 1)%current_queue->size;
    }
    printf("%s\n",word);
}

int main(){
    int n;
    scanf("%d",&n);
    struct Queue current_queue;
    current_queue.head = -1;
    current_queue.tail = -1;
    current_queue.size = n;
    current_queue.words_array = (char **)malloc(n * sizeof(char *));
    for(int i=0;i<n;i++){
        current_queue.words_array[i] = (char *)malloc(21*sizeof(char));
    }

    char choice[2];
    char word[21];
    do{
        scanf("%s",choice);
        if(strcmp(choice,"i") == 0){
            scanf("%s",word);
            enqueue(&current_queue,word);
        }
        else if(strcmp(choice,"d") == 0){
            dequeue(&current_queue);
        }
        else if(strcmp(choice,"f") == 0){
            printf("%d\n",QUEUE_FULL(&current_queue));
        }
        else if(strcmp(choice,"e") == 0){
            printf("%d\n",QUEUE_EMPTY(&current_queue));
        }
    }while(strcmp(choice,"t") != 0);

    return 1;
}