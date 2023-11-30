#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct singly_linked_list{
    struct Node* head;
};

struct Node* CREATE_NODE(int k);
void LIST_INSERT_FRONT(struct singly_linked_list *L,int x);
void LIST_INSERT_TAIL(struct singly_linked_list *L,int x);
void LIST_INSERT_AFTER(struct singly_linked_list *L,int x,int y);
void LIST_INSERT_BEFORE(struct singly_linked_list *L,int x,int y);
struct Node* LIST_SEARCH(struct singly_linked_list *L,int k);
int LIST_DELETE(struct singly_linked_list *L,int x);
int LIST_DELETE_FIRST(struct singly_linked_list *L);
int LIST_DELETE_LAST(struct singly_linked_list *L);
void LIST_DISPLAY(struct singly_linked_list *L);
void LIST_REVERSE(struct singly_linked_list *L);
void LIST_REVERSE_EVEN(struct singly_linked_list *L);

int main(){

    struct singly_linked_list L;
    L.head = NULL;    //THIS INITIALIZATION IS IMPORTANT FOR ABOVE FUNCTIONS AND EDGE CASES WHICH CHECKS FOR L.head == NULL

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
        else if(strcmp(choice,"r") == 0){
            LIST_REVERSE(&L);
        }
        else if(strcmp(choice,"ds") == 0){
            LIST_DISPLAY(&L);
        }
        else if(strcmp(choice,"re") == 0){
            LIST_REVERSE_EVEN(&L);
        }

    }while(strcmp(choice,"e") != 0);    
    return 1;
}

struct Node* CREATE_NODE(int k){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = k;
    t->next = NULL;
    return t;
}

void LIST_INSERT_FRONT(struct singly_linked_list *L,int x){
    struct Node* t = CREATE_NODE(x);

    t->next = L->head; //WORKS EVEN IF HEAD IS NULLPOINTER
    L->head = t;
}

void LIST_INSERT_TAIL(struct singly_linked_list *L,int x){
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
    }
}

void LIST_INSERT_AFTER(struct singly_linked_list *L,int x,int y){
    struct Node* ptr = LIST_SEARCH(L,y);
    if(ptr == NULL){
        return;
    }
    struct Node* t = CREATE_NODE(x);
    t->next = ptr->next;
    ptr->next = t;
}

void LIST_INSERT_BEFORE(struct singly_linked_list *L,int x,int y){
    struct Node* ptr = LIST_SEARCH(L,y);
    if(ptr == NULL){
        return;
    }
    struct Node* trail = L->head;
    struct Node* t = CREATE_NODE(x);
    t->next = ptr;
    if(L->head == ptr){
        L->head = t;
    }
    else{
        while(trail->next != ptr){
            trail = trail->next;
        }
        trail->next = t;
    }
}

struct Node* LIST_SEARCH(struct singly_linked_list *L,int k){
    struct Node* ptr = L->head;

    while(ptr){
        if(ptr->data == k){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL; //ELEMENT NOT FOUND OR LIST IS EMPTY
}


int LIST_DELETE(struct singly_linked_list *L,int x){
    struct Node* ptr = LIST_SEARCH(L,x);
    if(ptr == NULL){
        return -1;  
                            
    }
    struct Node* trail = L->head;
    if(L->head == ptr){
        L->head = ptr->next;
    }
    else{
        while(trail->next != ptr){
            trail = trail->next;
        }
        trail->next = ptr->next;
    }
    int value = ptr->data;
    free(ptr);
    return value;
}

int LIST_DELETE_FIRST(struct singly_linked_list *L){
    struct Node* ptr = L->head;
    if(L->head == NULL){
        return -1;
    }
    L->head = L->head->next;
    int value = ptr->data;
    free(ptr);
    return value;
}

int LIST_DELETE_LAST(struct singly_linked_list *L){
    //HANDLES ALL CASES OF EMPTY LIST, SINGLETON LIST AND NORMAL LIST
    if(L->head == NULL){
        return -1;
    }
    struct Node* ptr = L->head;
    struct Node* trail = NULL;

    while(ptr->next != NULL){
        trail = ptr;
        ptr = ptr->next;
    }
    if(trail == NULL){
        L->head = NULL;
    }
    else{
        trail->next = NULL;
    }
    int value = ptr->data;
    free(ptr);
    return value;
}

void LIST_DISPLAY(struct singly_linked_list *L){
    struct Node* ptr = L->head;
    while(ptr){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }printf("\n");
}

void LIST_REVERSE(struct singly_linked_list *L){
    struct Node* ptr = L->head;
    struct Node* middle = NULL;
    struct Node* left = NULL;
    while(ptr){
        left = middle;
        middle = ptr;
        ptr = ptr->next;
        middle->next = left;
    }
    L->head = middle;
    LIST_DISPLAY(L);
}

void LIST_REVERSE_EVEN(struct singly_linked_list *L){
    struct singly_linked_list even_list;
    even_list.head = NULL;
    struct Node* ptr = NULL;
    struct Node* original = L->head;
    if(L->head == NULL || L->head->next == NULL || L->head->next->next == NULL){
        LIST_DISPLAY(L);
        return;
    }
    
    while(original){
        ptr = original->next;
        if(original->next){
            original->next = original->next->next;
        }
        original = original->next;
        if(ptr){
            ptr->next = even_list.head;
            even_list.head = ptr;
        }
    }
    
    original = L->head;
    ptr = even_list.head;
    struct Node* extra_odd = original->next;
    struct Node* extra_even = ptr->next;
    

    while(original){
        original->next = ptr;
        if(ptr){
            ptr->next = extra_odd;
        }
        original = extra_odd;
        ptr = extra_even;
        if(extra_odd){
            extra_odd = extra_odd->next;
        }
        if(extra_even){
            extra_even = extra_even->next;
        }
    }
    LIST_DISPLAY(L);

}