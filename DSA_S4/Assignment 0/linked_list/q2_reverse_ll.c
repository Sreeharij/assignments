#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct linked_list{
    struct node* head;
};

void insert(struct linked_list* ll,int x){
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->val = x;
    t->next = NULL;
    if(ll->head == NULL){
        ll->head = t;
    }
    else{
        struct node* ptr = ll->head;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = t;
    }
}

void delete(struct linked_list* ll,int x){
    if(ll->head == NULL){
        printf("-1");
        return;
    }
    else if(ll->head->val == x){
        struct node* ptr = ll->head;
        ll->head = ll->head->next;
        free(ptr);
    }
    else{
        struct node* ptr = ll->head;
        struct node* trail = NULL;
        while(ptr->next && ptr->val != x){
            trail = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){
            printf("-1");
        }
        else{
            trail->next = ptr->next;
            free(ptr);
        }
    }
}

void display(struct linked_list* ll){
    struct node* ptr = ll->head;
    while(ptr){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }printf("\n");
}

void reverse(struct linked_list* ll){
    struct node* p = ll->head;
    struct node* q = NULL;
    struct node* r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    ll->head = q;
}

int main()
{   
    struct linked_list ll1;
    ll1.head = NULL;
    insert(&ll1,10);
    insert(&ll1,20);
    insert(&ll1,30);
    insert(&ll1,40);
    display(&ll1);
    reverse(&ll1);
    display(&ll1);
    

    return 0;
}

