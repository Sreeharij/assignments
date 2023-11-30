#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int top;
    char *arr;
};

int STACK_EMPTY(struct Stack* object){
    if(object->top == -1){
        return -1;
    }
    return 1;
}

int STACK_FULL(struct Stack* object,int max_size){
    if(object->top >= (max_size-1)){
        return -1;
    }
    return 1;
}

void push(struct Stack* object,int max_size,char k){
    if(STACK_FULL(object,max_size) == -1){
        printf("-1\n");
        return;
    }
    object->top += 1;
    object->arr[object->top] = k;
}

void pop(struct Stack* object){
    if(STACK_EMPTY(object) == -1){
        printf("-1\n");
        return;
    }
    printf("%c\n",object->arr[object->top]);
    object->top -= 1;
}

void peek(struct Stack* object){
    if(STACK_EMPTY(object) == -1){
        printf("-1\n");
        return;
    }
    printf("%c\n",object->arr[object->top]);
}

int main(){
    int n;
    scanf("%d",&n);
    struct Stack stk;
    stk.top = -1;
    stk.arr = (char *)malloc(n*sizeof(char));

    char choice[3];
    char k;
    do{
        scanf("%s",choice);
        if(strcmp(choice,"i") == 0){
            scanf(" %c",&k);
            push(&stk,n,k);
        }
        else if(strcmp(choice,"d") == 0){
            pop(&stk);
        }
        else if(strcmp(choice,"p") == 0){
            peek(&stk);
        }
    }while(strcmp(choice,"t") != 0);

    return 1;
}