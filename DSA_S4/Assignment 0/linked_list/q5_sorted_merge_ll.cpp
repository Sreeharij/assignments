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

void sorted_merge(struct linked_list* ll1,struct linked_list* ll2){
    //THIS FUNCTION MERGES THE 2 LINKED LISTS WITH THE HEAD AS HEAD OF 1ST LINKED LIST
    struct node* ptr1 = ll1->head;
    struct node* ptr2 = ll2->head;
    struct node* final_start;
    struct node* main_ptr;
    if(ptr1->val <= ptr2->val){
        final_start = ptr1;
        ptr1 = ptr1->next;
    }
    else{
        final_start = ptr2;
        ptr2 = ptr2->next;
    }
    main_ptr = final_start;
    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            main_ptr->next = ptr1;
            main_ptr = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            main_ptr->next = ptr2;
            main_ptr = ptr2;
            ptr2 = ptr2->next;
        }
    }
    if(ptr1){
        main_ptr->next = ptr1;
    }
    if(ptr2){
        main_ptr->next = ptr2;
    }
    ll1->head = final_start;
}

int main()
{   
    struct linked_list ll1;
    ll1.head = NULL;
    insert(&ll1,15);
    insert(&ll1,25);
    insert(&ll1,28);
    insert(&ll1,35);
    insert(&ll1,38);
    insert(&ll1,55);
    display(&ll1);
    
    struct linked_list ll2;
    ll2.head = NULL;
    insert(&ll2,10);
    insert(&ll2,20);
    insert(&ll2,30);
    insert(&ll2,40);
    insert(&ll2,50);
    insert(&ll2,60);
    display(&ll2);
    
    sorted_merge(&ll1,&ll2);
    display(&ll1);
    
    
    return 0;
}

