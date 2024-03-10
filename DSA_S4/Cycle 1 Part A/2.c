#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int val;
    struct Node* next;
};

struct linked_list{
    struct Node* head;
};

struct Node* create_node(int k){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->val = k;
    t->next = NULL;
    return t;
}

void LIST_INSERT(struct linked_list* ll,int x){
    struct Node* t = create_node(x);

    struct Node* ptr = ll->head;
    if(ll->head == NULL){
        ll->head = t;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = t;
    }
}

void LIST_DELETE(struct linked_list* ll,int i){
    struct Node* ptr = ll->head;
    struct Node* trail = NULL;
    int idx = 0;
    while(ptr){
        idx++;
        if(idx == i){
            break;
        }
        trail = ptr;
        ptr = ptr->next;
    }
    if(idx == i){
        if(i == 1){
            ll->head = ll->head->next;
        }
        else{
            trail->next = ptr->next;
        }
        printf("%d\n",ptr->val);
        free(ptr);
    }
    else{
        printf("-1\n");
    }
}

void LIST_DISPLAY(struct linked_list* ll){
    struct Node* ptr = ll->head;
    if(ll->head == NULL){
    	printf("-1\n");
    	return;
    }
    while(ptr){
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }printf("\n");
}

void remove_duplicates(struct linked_list* ll){
    if(ll->head == NULL){
        return;
    }
    struct Node* current = ll->head;
    struct Node* temp;
    while(current != NULL){
        temp = current;
        while(temp->next != NULL){
            if(temp->next->val == current->val){
                struct Node* extra = temp->next;
                temp->next = temp->next->next;
                free(extra);
            }
            else{
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

char LIST_PAL(struct linked_list* ll){
    if(ll->head == NULL || ll->head->next == NULL){
        return 'Y';
    }
    struct Node* slow = ll->head;
    struct Node* fast = ll->head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* stack = NULL;
    struct Node* ptr = ll->head;
    while(ptr!=slow){
        struct Node* t = create_node(ptr->val);
        t->next = stack;
        stack = t;
        ptr = ptr->next;
    }
    if(fast){
        //FR THE ODD CASES
        slow = slow->next;
    }
    while(slow){
        if(stack == NULL || stack->val != slow->val){
            return 'N';
        }
        struct Node* extra = stack;
        stack = stack->next;
        slow = slow->next;
        free(extra);
    }
    return 'Y';
}

int main(){
    struct linked_list ll;
    ll.head = NULL;
    char choice;
    int key,idx;
    do{
        scanf("%c",&choice);
        if(choice == 'a'){
            scanf("%d",&key);
            LIST_INSERT(&ll,key);
        }
        else if(choice == 'r'){
            scanf("%d",&idx);
            LIST_DELETE(&ll,idx);
        }
        else if(choice == 'd'){
            remove_duplicates(&ll);
            LIST_DISPLAY(&ll);
        }
        else if(choice == 'p'){
            printf("%c\n",LIST_PAL(&ll));
        }
        else if(choice == 's'){
            LIST_DISPLAY(&ll);
        }
    }while(choice != 'e');
    return 1;
}
