#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char * name;
    char * time;
    int priority;
    struct Node* next;
};

struct Node* create_node(char * name,char * time,int priority){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->name = (char *)malloc(sizeof(char) * 20);
    t->time = (char *)malloc(sizeof(char) * 10);
    
    strcpy(t->name,name);
    strcpy(t->time,time);
    
    t->priority = priority;
    t->next = NULL;
    
    return t;
}

struct priority_queue{
    struct Node* head; 
};

void insert(struct priority_queue* PQ,char * name,int priority,char * time){
    struct Node* t = create_node(name,time,priority);
    struct Node* ptr = PQ->head;
    struct Node* trail = NULL;
    while(ptr != NULL){
        if(t->priority > ptr->priority){
            break;
        }
        trail = ptr;
        ptr = ptr->next;
    }
    if(trail == NULL){
        t->next = PQ->head;
        PQ->head = t;
        return;
    }
    if(ptr == NULL){
        trail->next = t;
    }
    else{
        t->next = ptr;
        trail->next = t;
    }
}

void delete_max(struct priority_queue* PQ){
    if(PQ->head == NULL){
        printf("-1\n");
        return;
    }
    struct Node* ptr = PQ->head;
    
    printf("%s %d %s\n",ptr->name,ptr->priority,ptr->time);
    
    PQ->head = PQ->head->next;
    free(ptr);
}

void peek(struct priority_queue* PQ){
    if(PQ->head == NULL){
        printf("-1\n");
        return;
    }
    printf("%s %d %s\n",PQ->head->name,PQ->head->priority,PQ->head->time);
}

void delete(struct priority_queue* PQ,char* name,char* time){
    if(PQ->head == NULL){
        printf("-1\n");
        return;
    }
    struct Node* ptr = PQ->head;
    struct Node* trail = NULL;
    while(ptr){
        if(strcmp(ptr->name,name) == 0 && strcmp(ptr->time,time) == 0){
            break;
        }
        trail = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("-1\n");
    }
    else{
        trail->next = ptr->next;
        free(ptr);
    }
}

void display(struct priority_queue* PQ){
    struct Node* ptr = PQ->head;
    while(ptr){
        printf("%s %d %s\n",ptr->name,ptr->priority,ptr->time);
        ptr = ptr->next;
    }
}

void update(struct priority_queue* PQ,char* name,char* time,int new_priority){
    struct Node* ptr = PQ->head;
    struct Node* trail = NULL;
    if(PQ->head == NULL){
        printf("-1\n");
        return;
    }
    while(ptr){
        if(strcmp(ptr->name,name) == 0 && strcmp(ptr->time,time) == 0){
            break;
        }
        trail = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("-1\n");
    }
    else{
        trail->next = ptr->next;
    }
    free(ptr);
    insert(PQ,name,new_priority,time);
}

int main(){
    struct priority_queue PQ;
    PQ.head = NULL;
    
    char choice;
    char name[20];
    int priority;
    char time[10];

    do{ 
        scanf(" %c",&choice);
        if(choice == 'a'){
            scanf("%s",name);
            scanf(" %d",&priority);
            scanf(" %s",time);
            insert(&PQ,name,priority,time);
        }
        else if(choice == 't'){
            delete_max(&PQ);
        }
        else if(choice == 'c'){
            peek(&PQ);
        }
        else if(choice == 'd'){
            scanf("%s",name);
            scanf(" %s",time);
            delete(&PQ,name,time);
        }
        else if(choice == 'u'){
            scanf("%s",name);
            scanf(" %s",time);
            scanf(" %d",&priority);
            update(&PQ,name,time,priority);
        }
        else if(choice == 'p'){
            display(&PQ);
        }

    }while(choice != 'e');
    
    return 0;

}
