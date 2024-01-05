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

void make_loop(struct linked_list* ll,int x,int y){
    struct node* first = ll->head;
    struct node* second = ll->head;
    while(first->val != x){
        first = first->next;
    }
    while(second->val != y){
        second = second->next;
    }
    first->next = second;
}

void detect_loop(struct linked_list* ll){
    struct node* slow = ll->head;
    struct node* fast = ll->head;
    do{
        slow = slow->next;
        fast = fast->next;
        if(fast){
            fast = fast->next;
        }
    }while(fast!= NULL && slow != fast);
    if(slow == fast){
        slow = ll->head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        printf("Loop present\n");
        printf("Loop starts at %d",slow->val);
        return;
    }
    else{
        printf("No Loop\n");
        return;
    }
}

void alternate_merge(struct linked_list* ll1,struct linked_list* ll2){
    //ALTERNATE MERGE ASSUMES THAT THE LINKED LISTS ARE OF EQUAL SIZE
    
    struct node* ptr1 = ll1->head->next;
    struct node* ptr2 = ll2->head->next;
    struct node* third = ll1->head;
    struct node* fourth = ll2->head;
    
    while(third){  //SINCE LL ARE OF EQUAL SIZE, LL2 WILL GET EXHAUSTED FIRST
        third->next = fourth;
        fourth->next = ptr1;
        third = ptr1;
        fourth = ptr2;
        if(ptr1){
            ptr1 = ptr1->next;    
            ptr2 = ptr2->next;
        }
    }
}

int main()
{   
    struct linked_list ll1;
    ll1.head = NULL;
    insert(&ll1,10);
    insert(&ll1,20);
    insert(&ll1,30);
    insert(&ll1,40);
    insert(&ll1,50);
    insert(&ll1,60);
    display(&ll1);
    
    struct linked_list ll2;
    ll2.head = NULL;
    insert(&ll2,100);
    insert(&ll2,200);
    insert(&ll2,300);
    insert(&ll2,400);
    insert(&ll2,500);
    insert(&ll2,600);
    display(&ll2);
    
    alternate_merge(&ll1,&ll2);
    display(&ll1);
    
    
    return 0;
}

