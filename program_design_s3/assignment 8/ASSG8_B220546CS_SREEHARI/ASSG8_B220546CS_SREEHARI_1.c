#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
};

struct special_bst{
    struct node* root;
};

struct node* create_node(int k){
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->val = k;
    t->left = t->right = t->parent = NULL;
    return t;
}

struct node* insert(struct node* root,int k){
    if(root == NULL){
        return create_node(k);
    }
    if (k > root->val) {
        root->left = insert(root->left, k);
        root->left->parent = root;
    } else if (k < root->val) {
        root->right = insert(root->right, k);
        root->right->parent = root;
    }
    return root;
}

struct node* search(struct node* root, int k) {
    if (root == NULL){
        return NULL;
    }
    if(root->val == k) {
        return root;
    }

    if (k > root->val) {
        return search(root->left, k);
    }else{
        return search(root->right, k);
    }
}

int find_max(struct special_bst* bst) {
    if (bst->root == NULL) {
        return -1; //the specil case when tree is empty  
    }
    struct node* ptr = bst->root;

    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr->val;
}

int find_min(struct special_bst* bst) {
    if (bst->root == NULL) {
        return -1; //the specil case when tree is empty  
    }
    struct node* ptr = bst->root;

    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr->val;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

int main()
{
    char choice[2];
    int x;
    struct node* result;
    int answer;
    
    struct special_bst bst;
    bst.root = NULL;
    
    do{
        scanf("%s",choice);
        if(strcmp(choice,"a") == 0){
            scanf("%d",&x);
            bst.root = insert(bst.root,x);
        }
        else if(strcmp(choice,"s") == 0){
            scanf("%d",&x);
            if(bst.root == NULL){
                //printf("\n");
            }
            else{
                result = search(bst.root,x);
                if(result == NULL){
                    printf("N\n");
                }
                else{
                    printf("F\n");
                }
            }
        }
        else if(strcmp(choice,"x") == 0){
            answer = find_max(&bst);
            if(answer == -1){
                //printf("\n");
            }
            else{
                printf("%d\n",answer);
            }
        }
        else if(strcmp(choice,"n") == 0){
            answer = find_min(&bst);
            if(answer == -1){
                //printf("\n");
            }
            else{
                printf("%d\n",answer);
            }
        }
        else if(strcmp(choice,"i") == 0){
            inorder(bst.root);
            if(bst.root != NULL){
                printf("\n");    
            }
        }
        else if(strcmp(choice,"p") == 0){
            preorder(bst.root);
            if(bst.root != NULL){
                printf("\n");    
            }
        }
        else if(strcmp(choice,"t") == 0){
            postorder(bst.root);
            if(bst.root != NULL){
                printf("\n");    
            }
        }
    }while(strcmp(choice,"e") != 0);
    return 0;
}
