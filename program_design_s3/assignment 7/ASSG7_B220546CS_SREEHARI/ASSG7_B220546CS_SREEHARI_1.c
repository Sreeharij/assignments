#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int top;
    char* array;
};

int is_empty(struct Stack* stk){
    if(stk->top == -1){
        return 1;
    }
    return 0;
}

void push(struct Stack* stk,char symbol){
    stk->array[++stk->top] = symbol;
}

char pop(struct Stack* stk){
    if(!is_empty(stk)){
        return stk->array[stk->top--];
    }
    return '#';
}

char peek(struct Stack* stk){
    if(!is_empty(stk)){
        return stk->array[stk->top];
    }
    return '#';
}

int get_precedence(char x){
    //THIS SAME FUNCTION CAN BE USED TO CHECK WHETHER INPUT IS AN OPERATOR OR NOT
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/' || x == '%'){
        return 2;
    }
    return 0;
}

void infix_to_postfix(char* arr,int length,struct Stack* stk,char* postfix_arr){
    int j=0;
    for(int i=0;i<length;i++){
        if(arr[i] == '('){
            push(stk,'(');
        }
        else if(arr[i] == ')'){
            while(!is_empty(stk) && peek(stk) != '('){
                postfix_arr[j++] = pop(stk);
            }
            pop(stk);
        }
        else if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%'){
            while(!is_empty(stk) && get_precedence(peek(stk)) >= get_precedence(arr[i])){
                postfix_arr[j++] = pop(stk);
            }
            push(stk,arr[i]);
        }
        else{
            postfix_arr[j++] = arr[i];
        }
    }

    while(!is_empty(stk)){
        postfix_arr[j++] = pop(stk);
    }

    for(int i=0;i<length;i++){
        printf("%c ",postfix_arr[i]);
    }printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }

    char postfix_arr[n];
    struct Stack stk;
    stk.top = -1;
    stk.array = (char *)malloc(n*sizeof(char));


    infix_to_postfix(arr,n,&stk,postfix_arr);
    return 1;
}