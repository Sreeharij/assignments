#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int *arr;
    int size;
};

int is_empty(struct Stack* stk){
    if(stk->top == -1){
        return -1;
    }
    return 1;
}

int is_full(struct Stack* stk){
    if(stk->top >= (stk->size)-1){
        return -1;
    }
    return 1;
}

void push(struct Stack* stk,int x){
    if(is_full(stk) == -1){
        return;
    }
    stk->top += 1;
    stk->arr[stk->top] = x;
}

void pop(struct Stack* stk){
    if(is_empty(stk) == -1){
        return;
    }
    stk->top -= 1;
}

void find_greater(struct Stack* stk,int arr[]){
    int result[stk->size];
    for(int i=0;i<stk->size;i++){
        result[i] = -1;
    }
    for(int i=0;i<stk->size;i++){
        while(is_empty(stk)==1 && arr[i] > arr[stk->arr[stk->top]]){
            result[stk->arr[stk->top]] = arr[i];
            pop(stk);
        }
        push(stk,i);
    }
    for(int i=0;i<stk->size;i++){
        printf("%d ",result[i]);
    }printf("\n");
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Stack stk;
    stk.top = -1;
    stk.size = n;
    stk.arr = (int *)malloc(n * sizeof(int));
    find_greater(&stk,arr);

    return 1;
}

