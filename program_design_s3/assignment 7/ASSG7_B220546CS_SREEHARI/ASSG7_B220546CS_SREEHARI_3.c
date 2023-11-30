#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
    int top;
    int* array;
};

int is_empty(struct stack* stk){
    if(stk->top == -1){
        return 1;
    }
    return 0;
}

void push(struct stack* stk,int val){
    stk->array[++stk->top] = val;
}

int pop(struct stack* stk){
    if(!is_empty(stk)){
        return stk->array[stk->top--];
    }
    return -1;
}

int peek(struct stack* stk){
    if(is_empty(stk)){
        return -1;
    }
    return stk->array[stk->top];
}

void func(char* arr, struct stack* stk) {
    int i;
    int first, second;
    for (i = 0; arr[i]; i++) {
        if(arr[i] == ' '){
            continue;
        }
        if (isdigit(arr[i])) {
            push(stk, arr[i] - '0');
        }
        else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%') {
            first = pop(stk);
            second = pop(stk);
            if (arr[i] == '+') {
                push(stk, first + second);
            }
            else if (arr[i] == '-') {
                push(stk, second - first);
            }
            else if (arr[i] == '*') {
                push(stk, first * second);
            }
            else if (arr[i] == '/') {
                if (first != 0) {
                    push(stk, second / first);
                }
                else {
                    printf("-1\n");
                    return;
                }
            }
            else if (arr[i] == '%') {
                if (first != 0) {
                    push(stk, second % first);
                }
                else {
                    printf("-1\n");
                    return;
                }
            }
        }
        else if (arr[i] == '(' || arr[i] == ')') {
        }
        else {
            printf("-1\n");
            return;
        }
    }
    int answer = pop(stk);
    if (!is_empty(stk)) {
        printf("-1\n");
        return;
    }
    printf("%d", answer);
    return;
}


int main(){
    char arr[10000];
    gets(arr);

    struct stack stk;
    stk.top = -1;
    stk.array = (int *)malloc(10000 * sizeof(int));

    func(arr,&stk);
    
    return 1;
}