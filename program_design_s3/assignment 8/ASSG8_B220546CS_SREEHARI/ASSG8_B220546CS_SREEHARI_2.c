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

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* find_left_leaf(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* find_right_leaf(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* find_node(struct node* root, int k) {
    if (root == NULL){ 
        return NULL;
    }
    if(root->val == k){
        return root;
    }
    if (k < root->val) {
        return find_node(root->right, k);
    } else {
        return find_node(root->left, k);
    }
}

void successor(struct special_bst* bst, int k) {
    struct node* node = find_node(bst->root, k);
    if (node == NULL) {
        printf("-1\n");
        return;
    }

    if (node->right != NULL) {
        struct node* successor_node = find_left_leaf(node->right);
        printf("%d\n",successor_node->val);
    } else {
        struct node* parent = node->parent;
        while (parent != NULL && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        if (parent != NULL) {
            printf("%d\n",parent->val);
        } else {
            printf("-1\n");
        }
    }
}

void predecessor(struct special_bst* bst, int k) {
    struct node* node = find_node(bst->root, k);
    if (node == NULL) {
        printf("-1\n", k);
        return;
    }

    if (node->left != NULL) {
        struct node* predecessor_node = find_right_leaf(node->left);
        printf("%d\n",predecessor_node->val);
    } else {
        struct node* parent = node->parent;
        while (parent != NULL && node == parent->left) {
            node = parent;
            parent = parent->parent;
        }
        if (parent != NULL) {
            printf("%d\n",parent->val);
        } else {
            printf("-1\n");
        }
    }
}

int main()
{
    char choice[2];
    int x;
    
    struct special_bst bst;
    bst.root = NULL;
    
    do{
        scanf("%s",choice);
        if(strcmp(choice,"a") == 0){
            scanf("%d",&x);
            bst.root = insert(bst.root,x);
        }
        else if(strcmp(choice,"c") == 0){
            scanf("%d",&x);
            successor(&bst,x);
        }
        else if(strcmp(choice,"r") == 0){
            scanf("%d",&x);
            predecessor(&bst,x);
        }
        else if(strcmp(choice,"p") == 0){
            if(bst.root == NULL){
                printf("-1\n");
            }
            else{
                preorder(bst.root);
                printf("\n");
            }
        }
    }while(strcmp(choice,"e") != 0);

    return 0;
}
