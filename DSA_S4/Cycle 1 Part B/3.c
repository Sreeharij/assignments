#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STRING_SIZE (11*1000-4) 
//MAXIMUM SIZE OF STRING (DERIVED FROM RIGHT SKEWED TREE WITH 10^4 NODES) 

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct binary_tree{
    struct TreeNode* root;
    int size;
};

struct stack_node{
    char val;
    struct stack_node* next;
};

struct stack{
    struct stack_node* top;
};

struct stack_node* create_stack_node(char x){
    struct stack_node* t = (struct stack_node*)malloc(sizeof(struct stack_node));
    t->val = x;
    t->next = NULL;
    return t;
}

struct TreeNode* create_tree_node(int x){
    struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = x;
    t->left = t->right = NULL;
    return t;
}

bool stack_empty(struct stack* stk){
    if(stk->top == NULL){
        return true;
    }
    return false;
}

void stack_push(struct stack* stk,char x){
    struct stack_node* ptr = create_stack_node(x);
    ptr->next = stk->top;
    stk->top = ptr;
}

void stack_pop(struct stack* stk){
    if(!stack_empty(stk)){
        struct stack_node* ptr = stk->top;
        stk->top = stk->top->next;
        free(ptr);
    }
    else{
        printf("STACK EMPTY\n");
    }
}

char stack_top(struct stack* stk){
    if(!stack_empty(stk)){
        return stk->top->val;
    }
    else{
        printf("STACK EMPTY\n");
    }
}

struct TreeNode* make_tree(char string_arr[],int idx,int * count){
    struct stack stk;
    stk.top = NULL;
    if(string_arr[idx] == ')'){
        return NULL;
    }
    int number = 0;
    while(string_arr[idx] != '(' && string_arr[idx] != ')' && string_arr[idx] != '\0'){
        number = number*10 + (int)(string_arr[idx]-'0');
        idx++;
    }
    int first,second;
    struct TreeNode* t = create_tree_node(number);
    *count += 1;
    if(string_arr[idx] == '('){
        idx++;
        first = idx;
        stack_push(&stk,'(');
        while(!stack_empty(&stk)){
            if(string_arr[idx] == '('){
                stack_push(&stk,'(');
            }
            else if(string_arr[idx] == ')'){
                stack_pop(&stk);
            }
            idx++;
        }
        if(string_arr[idx] == ')' || string_arr[idx] == '\0'){
            t->left = make_tree(string_arr,first,count);
            return t;
        }
        idx++;
        second = idx;
        t->left = make_tree(string_arr,first,count);
        t->right = make_tree(string_arr,second,count);
    }
    return t;
}

void print_range_values(struct TreeNode* root,int low,int high){
    if(!root) return;
    if(root->val < low){
        print_range_values(root->right,low,high);
    }
    else{
        if(root->val > high){
            print_range_values(root->left,low,high);
        }
        else{
            print_range_values(root->left,low,high);
            printf("%d ",root->val);
            print_range_values(root->right,low,high);
        }
    }
}

bool ancestors(struct TreeNode* root,int k){
    if(!root) return false;
    if(root->val == k){
        printf("%d ",root->val);
        return true;
    }
    if(ancestors(root->left,k) || ancestors(root->right,k)){
        printf("%d ",root->val);
        return true;
    }
    return false;
}

int main(){
    char string_arr[MAX_STRING_SIZE];
    scanf("%s",string_arr);
    struct binary_tree BST;
    BST.root = NULL;
    BST.size = 0;
    BST.root = make_tree(string_arr,0,&BST.size);
    
    char choice[2] = "e";
    do{
        scanf("%s",choice);
        if(strcmp(choice,"p") == 0){
            int low,high;
            scanf("%d %d",&low,&high);
            print_range_values(BST.root,low,high);
            printf("\n");
        }
        else if(strcmp(choice,"a") == 0){
            int k;
            scanf("%d",&k);
            ancestors(BST.root,k);
            printf("\n");
        }
    }while(strcmp(choice,"e") != 0);
    return 0;
}