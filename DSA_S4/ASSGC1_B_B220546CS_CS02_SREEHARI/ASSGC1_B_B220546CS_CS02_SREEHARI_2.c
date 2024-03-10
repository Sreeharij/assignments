#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define MAX_STRING_SIZE (11*10000-4) 
//MAXIMUM SIZE OF STRING (DERIVED FROM RIGHT SKEWED TREE WITH 10^4 NODES) 
//IS EQUAL TO 11 * 10^4 - 4

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct binary_tree{
    struct TreeNode* root;
    int size;
};

struct ll_node{
    struct TreeNode* ptr;
    struct ll_node* next;
};

struct stack_node{
    char val;
    struct stack_node* next;
};

struct queue{
    struct ll_node* head;
    struct ll_node* tail;
};

struct stack{
    struct stack_node* top;
};

bool stack_empty(struct stack* stk){
    if(stk->top == NULL){
        return true;
    }
    return false;
}

struct ll_node* create_ll_node(struct TreeNode* pointer){
    struct ll_node* t = (struct ll_node*)malloc(sizeof(struct ll_node));
    t->ptr = pointer;
    t->next = NULL;
    return t;
}

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

bool queue_empty(struct queue* q){
    if(q->head == NULL && q->tail == NULL){
        return true;
    }
    return false;
}

void queue_push(struct queue* q,struct TreeNode* pointer){
    struct ll_node* ptr = create_ll_node(pointer);
    if(q->tail == NULL){
        q->head = q->tail = ptr;
    }
    else{
        q->tail->next = ptr;
        q->tail = ptr;
    }
}

void queue_pop(struct queue* q){
    if(!queue_empty(q)){
        struct ll_node* ptr = q->head;
        if(q->head == q->tail){
            q->head = q->tail = NULL;
        }
        else{
            q->head = q->head->next;
        }
        free(ptr);
    }
    else{
        printf("QUEUE EMPTY\n");
    }
}

struct TreeNode* queue_front(struct queue* q){
    if(!queue_empty(q)){
        return q->head->ptr;
    }
    else{
        printf("QUEUE EMPTY\n");
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

void level_order_traversal(struct binary_tree* BST){
    struct TreeNode* temp_pointer = BST->root;
    if(!temp_pointer) return;  //IF FUNCTION IS CALLED ON EMPTY TREE IT WILL NOT PRINT EMPTY LINE
    struct queue q;
    q.head = q.tail = NULL;
    queue_push(&q,temp_pointer);
    while(!queue_empty(&q)){
        temp_pointer = queue_front(&q);
        queue_pop(&q);
        printf("%d ",temp_pointer->val);
        if(temp_pointer->left){
            queue_push(&q,temp_pointer->left);
        }
        if(temp_pointer->right){
            queue_push(&q,temp_pointer->right);
        }
    }
    printf("\n");
}

struct return_data{
    bool is_bst;
    int max_val;
    int min_val;
    int bst_sum;
};

struct return_data maximum_sum_bst(struct TreeNode* root,int * max_sum){
    struct return_data result;
    if(!root){
        result.is_bst = true;
        result.max_val = INT_MIN;
        result.min_val = INT_MAX;
        result.bst_sum = 0;
        return result;
    }
    struct return_data left_data = maximum_sum_bst(root->left,max_sum);
    struct return_data right_data = maximum_sum_bst(root->right,max_sum);
    result.is_bst = false;
    if(left_data.is_bst && right_data.is_bst){
        if((root->val > left_data.max_val) && (root->val < right_data.min_val)){
            result.is_bst = true;
        }
    }
    result.bst_sum = left_data.bst_sum + right_data.bst_sum;
    result.bst_sum = result.is_bst ? result.bst_sum + root->val : 0;
    *max_sum = (*max_sum) > result.bst_sum ? (*max_sum) : result.bst_sum;
    result.max_val = max(root->val,right_data.max_val);
    result.min_val = min(root->val,left_data.min_val);
    return result;   
}

void right_view_helper(struct TreeNode* root,int right_view_arr[],int * idx, int current_level){
    if(!root || (!root->right && !root->left) ){
        return;
    }
    if(current_level + 1 > (*idx) ){
        *idx = (*idx)+1;
        if(root->right){
            right_view_arr[*idx]  = root->right->val;
        }
        else{
            right_view_arr[*idx]  = root->left->val;
        }
        
    }
    right_view_helper(root->right,right_view_arr,idx,current_level+1);
    right_view_helper(root->left,right_view_arr,idx,current_level+1);
}

void right_side_view(struct binary_tree* BST){
    struct TreeNode* root = BST->root;
    if(!root) return;
    int right_view_arr[BST->size];
    int idx = 0;
    right_view_arr[idx] = root->val;
    right_view_helper(root,right_view_arr,&idx,0);
    for(int i=0;i<=idx;i++){
        printf("%d ",right_view_arr[i]);
    }printf("\n");
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
        if(strcmp(choice,"l") == 0){
            level_order_traversal(&BST);
        }
        else if(strcmp(choice,"m") == 0){
            int max_sum = 0;
            maximum_sum_bst(BST.root,&max_sum);
            printf("%d\n",max_sum);
            
        }
        else if(strcmp(choice,"r") == 0){
            right_side_view(&BST);
        }
    }while(strcmp(choice,"e") != 0);

    return 0;
}