#include <stdio.h>
#include <stdlib.h>

int is_operator(char x){
  if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '(' || x==')' || x == '^') return 1;
  return 0;
}

int func(int n,char arr[n]){
  if(n == 1) return 0;

  char stack[n];
  int stack_top = 0;
  for(int i=0;i<n;i++){
    if(arr[i] != ')'){
      if(is_operator(arr[i]) == 1){
        stack[stack_top++] = arr[i]; 
      }
    }
    else{
      if(stack_top == 0 || stack[stack_top-1] == '('){
        return 1;
      }
      else{
        while(stack_top >0 && stack[stack_top-1] != '(') stack_top--;
        if(stack_top >0){
          stack_top--;
        }
        else{
          return 1;
        }
      }
    }
  }
  if(stack_top > 0 && stack[stack_top-1] == '(') return 1;
  return 0;

}

int main(){
    int n;
    scanf("%d",&n);
    char arr[n];
    
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    printf("%d\n",func(n,arr));

    return 1;
}
