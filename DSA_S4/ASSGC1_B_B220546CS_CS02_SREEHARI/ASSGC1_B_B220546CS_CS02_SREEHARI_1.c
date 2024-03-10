#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct binary_tree{
    struct TreeNode* root;
};

struct ll_node{
    struct TreeNode* ptr;
    struct ll_node* next;
};

struct queue{
    struct ll_node* head;
    struct ll_node* tail;
};

struct ll_node* create_ll_node(struct TreeNode* pointer){
    struct ll_node* t = (struct ll_node*)malloc(sizeof(struct ll_node));
    t->ptr = pointer;
    t->next = NULL;
    return t;
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

void zig_zag_level_order(struct TreeNode* root,int zig_zag_arr[]){
    if(!root) return;                         //IF FUNCTION IS CALLED ON EMPTY TREE IT WILL NOT PRINT EMPTY LINE
    struct queue q;
    q.head = q.tail = NULL;
    queue_push(&q,root);
    int current = 1,next = 0;
    struct TreeNode* temp_pointer;
    int required_idx = 0;
    bool flag = true;
    int level_length = 1;

    while(!queue_empty(&q)){
        if(current == 0){
            current = next;
            next = 0;
            required_idx = flag ? current - 1 : 0;  //DO THIS BEFORE COMPLEMENTING FLAG VALUE IN NEXT LINE
            flag = !flag;

            for(int i=0;i<level_length;i++){
                printf("%d ",zig_zag_arr[i]);
            }
            level_length = current;
        }
        temp_pointer = queue_front(&q);
        queue_pop(&q);
        current -= 1;
        if(flag){
            zig_zag_arr[required_idx++] = temp_pointer->val;
        }
        else{
            zig_zag_arr[required_idx--] = temp_pointer->val;
        }
        if(temp_pointer->left){
            queue_push(&q,temp_pointer->left);
            next += 1;
        }
        if(temp_pointer->right){
            queue_push(&q,temp_pointer->right);
            next += 1;
        }
    }
    for(int i=0;i<level_length;i++){
        printf("%d ",zig_zag_arr[i]);
    }printf("\n");
}

void level_max(struct TreeNode* root){
    if(!root) return;                         //IF FUNCTION IS CALLED ON EMPTY TREE IT WILL NOT PRINT EMPTY LINE
    struct queue q;
    q.head = q.tail = NULL;
    queue_push(&q,root);
    int current = 1,next = 0;
    struct TreeNode* temp_pointer;    
    int max_val = root->val;
    while(!queue_empty(&q)){
        if(current == 0){
            current = next;
            next = 0;
            printf("%d ",max_val);
            max_val = INT_MIN;
        }
        temp_pointer = queue_front(&q);
        queue_pop(&q);
        current -= 1;
        max_val = max_val > temp_pointer->val ? max_val : temp_pointer->val;
        if(temp_pointer->left){
            queue_push(&q,temp_pointer->left);
            next += 1;
        }
        if(temp_pointer->right){
            queue_push(&q,temp_pointer->right);
            next += 1;
        }
    }
    printf("%d\n",max_val);
} 

void preorder_print(struct TreeNode* root){
    if(!root) return;
    printf("%d ",root->val);
    preorder_print(root->left);
    preorder_print(root->right);
}

void inorder_print(struct TreeNode* root){
    if(!root) return;
    inorder_print(root->left);
    printf("%d ",root->val);
    inorder_print(root->right);
}

void postorder_print(struct TreeNode* root){
    if(!root) return;
    postorder_print(root->left);
    postorder_print(root->right);
    printf("%d ",root->val);
}

int max_diameter(struct TreeNode* root,int * diameter_val){
    if(!root) return 0;
    int left = max_diameter(root->left,diameter_val);
    int right = max_diameter(root->right,diameter_val);
    *diameter_val = max(*diameter_val,left + right + 1);
    return max(left,right) + 1;
}

int left_leaf_sum(struct TreeNode* root, bool flag){
    if(!root) return 0;
    if(!root->left && !root->right){
        if(flag){
            return root->val;
        }
        return 0;
    }
    int left=0,right=0;
    if(root->left){
        left = left_leaf_sum(root->left,true);
    }
    if(root->right){
        right = left_leaf_sum(root->right,false);
    }
    return left + right;
}

int search(int * inorder,int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i] == key){
            return i;
        }
    }
    return -1;
}

struct TreeNode* create_tree_node(int x){
    struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = x;
    t->left = t->right = NULL;
    return t;
}

struct TreeNode* make_tree(int * preorder, int * inorder,int * pre_idx,int in_start,int in_end){
    if(in_start > in_end){
        return NULL;
    }
    struct TreeNode* root = create_tree_node(preorder[*pre_idx]);
    
    int current_inorder_idx = search(inorder,in_start,in_end,preorder[*pre_idx]);
    *pre_idx += 1;
    root->left = make_tree(preorder,inorder,pre_idx,in_start,current_inorder_idx-1);
    root->right = make_tree(preorder,inorder,pre_idx,current_inorder_idx+1,in_end);
    return root;
}


int main(){
    int n;
    scanf("%d",&n);
    int inorder[n],preorder[n];
    for(int i=0;i<n;i++){
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&preorder[i]);
    }

    //MAX NUMBER OF NODES = 1000000 
    //MAX NUMBER OF NODES IN A LEVEL = 2^(log2(1000000 + 1) - 1) = 2^(19.93-1) < 524288
    int zig_zag_arr[524288] = {0};  

    struct binary_tree BST;
    int pre_idx = 0;
    BST.root = make_tree(preorder,inorder,&pre_idx,0,n-1);
    
    char choice[2] = "e";
    do{
        scanf("%s",choice);
        if(strcmp(choice,"p") == 0){
            postorder_print(BST.root);
            printf("\n");
        }
        else if(strcmp(choice,"z") == 0){
            zig_zag_level_order(BST.root,zig_zag_arr);
        }
        else if(strcmp(choice,"m") == 0){
            level_max(BST.root);
        }
        else if(strcmp(choice,"d") == 0){
            int diameter_val = 0;
            max_diameter(BST.root,&diameter_val);
            printf("%d\n",diameter_val);
        }
        else if(strcmp(choice,"s") == 0){
		if(BST.root){
			if(!BST.root->left && !BST.root->right){
            			printf("0\n");
            		}
            		else{
            			printf("%d\n",left_leaf_sum(BST.root,true));
            		}
		}
		else{
			printf("0\n");
		}
            //printf("%d\n",left_leaf_sum(BST.root,true)); // THE INITIAL TRUE HANDLES THE CASE WHERE THERE IS ONLY 1 NODE IN TREE AND IT IS CONSIDERED AS LEFT LEAF
        }
    }while(strcmp(choice,"e") != 0);

    return 0;
}
