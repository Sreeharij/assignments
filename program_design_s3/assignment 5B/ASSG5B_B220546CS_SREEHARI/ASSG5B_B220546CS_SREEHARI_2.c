#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct doubly_linked_list{
    struct Node* head;
};

struct Node* CREATE_NODE(int k);
void LIST_INSERT_FRONT(struct doubly_linked_list *L,int x);
void LIST_INSERT_TAIL(struct doubly_linked_list *L,int x);
struct Node* LIST_SEARCH(struct doubly_linked_list *L,int k);
void LIST_INSERT_AFTER(struct doubly_linked_list *L,int x,int y);
void LIST_INSERT_BEFORE(struct doubly_linked_list *L,int x,int y);
int LIST_DELETE(struct doubly_linked_list *L,int x);
int LIST_DELETE_FIRST(struct doubly_linked_list *L);
int LIST_DELETE_LAST(struct doubly_linked_list *L);
void LIST_DISPLAY(struct doubly_linked_list *L);
void LIST_REVERSE_NEGATIVE(struct doubly_linked_list *L);

int main(){
    struct doubly_linked_list L;
    L.head = NULL;  

    int k,x,y;
    char choice[3];

    do{
        scanf("%s",choice);
        if(strcmp(choice,"f") == 0){
            scanf("%d",&k);
            LIST_INSERT_FRONT(&L,k);
        }
        else if(strcmp(choice,"t") == 0){
            scanf("%d",&k);
            LIST_INSERT_TAIL(&L,k);
        }
        else if(strcmp(choice,"a") == 0){
            scanf("%d%d",&x,&y);
            LIST_INSERT_AFTER(&L,x,y);
        }
        else if(strcmp(choice,"b") == 0){
            scanf("%d%d",&x,&y);
            LIST_INSERT_BEFORE(&L,x,y);
        }
        else if(strcmp(choice,"d") == 0){
            scanf("%d",&k);
            printf("%d\n",LIST_DELETE(&L,k));
        }
        else if(strcmp(choice,"i") == 0){
            printf("%d\n",LIST_DELETE_FIRST(&L));
        }
        else if(strcmp(choice,"l") == 0){
            printf("%d\n",LIST_DELETE_LAST(&L));
        }
        else if(strcmp(choice,"s") == 0){
            scanf("%d",&k);
            struct Node* result_ptr;
            result_ptr = LIST_SEARCH(&L,k);
            if(result_ptr){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }
        }
        else if(strcmp(choice,"ds") == 0){
            LIST_DISPLAY(&L);
        }
        else if(strcmp(choice,"rn") == 0){
            LIST_REVERSE_NEGATIVE(&L);
        }

    }while(strcmp(choice,"e") != 0);


    return 1;
}

struct Node* CREATE_NODE(int k){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = k;
    t->prev = NULL;
    t->next = NULL;
    return t;
}

void LIST_INSERT_FRONT(struct doubly_linked_list *L,int x){
    struct Node* t = CREATE_NODE(x);

    t->next = L->head;
    if(L->head){
        L->head->prev = t;
    }
    L->head = t;
}

void LIST_INSERT_TAIL(struct doubly_linked_list *L,int x){
    struct Node* t = CREATE_NODE(x);
    struct Node* ptr = L->head;
    if(L->head == NULL){
        L->head = t;
    }
    else{
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = t;
        t->prev = ptr;
    }
}

struct Node* LIST_SEARCH(struct doubly_linked_list *L,int k){
    struct Node* ptr = L->head;

    while(ptr){
        if(ptr->data == k){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void LIST_INSERT_AFTER(struct doubly_linked_list *L,int x,int y){
    struct Node* ptr = LIST_SEARCH(L,y);
    if(ptr == NULL){
        return;
    }
    struct Node* t = CREATE_NODE(x);
    t->next = ptr->next;
    if(ptr->next){
        ptr->next->prev = t;
    }
    
    ptr->next = t;
    t->prev = ptr;
}

void LIST_INSERT_BEFORE(struct doubly_linked_list *L,int x,int y){
    struct Node* ptr = LIST_SEARCH(L,y);
    if(ptr == NULL){
        return;
    }
    struct Node* t = CREATE_NODE(x);
    t->next = ptr;
    t->prev = ptr->prev;
    if(ptr->prev){
        ptr->prev->next = t;
    }
    else{
        L->head = t;
    }
    ptr->prev = t;    
}

int LIST_DELETE(struct doubly_linked_list *L,int x){
    struct Node* ptr = LIST_SEARCH(L,x);
    if(ptr == NULL){
        return -1;
    }
    if(L->head == ptr){
        L->head = ptr->next;
    }
    else{
        ptr->prev->next = ptr->next;
        if(ptr->next){
            ptr->next->prev = ptr->prev;
        }
    }
    int value = ptr->data;
    free(ptr);
    return value;
}

int LIST_DELETE_FIRST(struct doubly_linked_list *L){
    struct Node* ptr = L->head;
    if(L->head == NULL){
        return -1;
    }
    L->head = L->head->next;
    if(L->head){
        L->head->prev = NULL;
    }
    int value = ptr->data;
    free(ptr);
    return value;
}

int LIST_DELETE_LAST(struct doubly_linked_list *L){
    if(L->head == NULL){
        return -1;
    }
    struct Node* ptr = L->head;
    if(L->head->next == NULL){
        L->head = NULL;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
    }
    int value = ptr->data;
    free(ptr);
    return value;
}

void LIST_DISPLAY(struct doubly_linked_list *L){
    struct Node* ptr = L->head;
    while(ptr){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }printf("\n");
}


void LIST_REVERSE_NEGATIVE(struct doubly_linked_list *L){
    struct Node* left = L->head;
    struct Node* right = L->head;
    int temp;

    if(L->head == NULL || L->head->next == NULL){   
        LIST_DISPLAY(L);
        return;
    }

    while(right->next){
        right = right->next;
    }

    while(left != right){
        while(left->data >= 0 && left!=right){
            left = left->next;
        }
        while(right->data >=0 && left!=right){
            right = right->prev;
        }
        if(left == right){
            break;
        }
        if(left->data < 0){
            temp = left->data;
            left->data = right->data;
            right->data = temp;
            left = left->next;
            if(left != right){
                right = right->prev;
            }
        }
    }

    LIST_DISPLAY(L);
}