#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#define max(m,n) (m >= n ? m : n)
#define min(m,n) (m >= n ? n : m)

struct Node{
    int val;
    struct Node* next;
};

struct Node* insert_helper_func(struct Node* L,int x);
void insert(struct Node* ht[],int x,int n);
void search(struct Node* ht[],int x,int n);
void delete_func(struct Node* ht[],int x,int n);
bool check_presence(struct Node* ht[],int x,int n);
void update(struct Node* ht[],int x,int second,int n);

int main() {
    int n;
    scanf("%d",&n);
    struct Node* ht[n];
    
    for(int i=0;i<n;i++){
        ht[i]=NULL;
    }
   
    char choice[2] = "e";
    int first,second;
    do{
        scanf("%s",choice);
        if(strcmp(choice,"i") == 0){
            scanf("%d",&first);
            insert(ht, first, n);
        }
        else if(strcmp(choice,"d") == 0){
            scanf("%d",&first);
            delete_func(ht, first, n);
        }
        else if(strcmp(choice,"p") == 0){
            scanf("%d",&first);
            
            struct Node* ptr = ht[first];
	    if (!ptr){
		printf("-1\n");
        	continue;
    	    }
    	    while (ptr != NULL){
            	printf("%d ", ptr->val);
        	ptr = ptr->next;
    	    }	
    	    printf("\n");    
        }
        
        else if(strcmp(choice,"s") == 0){
            scanf("%d",&first);
            search(ht, first, n);
        }
        else if(strcmp(choice,"u") == 0){
            scanf("%d %d",&first,&second);
            update(ht, first, second, n);
        }
    }while(strcmp(choice,"e") != 0);
    return 1;
}

struct Node* insert_helper_func(struct Node* L,int x){
    struct Node* ptr=L;
    struct Node* prev=L;
    while(ptr!=NULL && ptr->val<x){
        prev=ptr;
        ptr=ptr->next;
    }
    if(ptr!=NULL&&ptr->val==x){
        printf("-1\n");
        return L;
    }
    
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->val = x;
    t->next = NULL;
    
    if(ptr==L){
        L=t;
        L->next=ptr;
        return L;
    }
    else{
        prev->next=t;
        prev->next->next=ptr;
        return L;
    }
}

void insert(struct Node* ht[],int x,int n){
    int in=x%n;
    if(ht[x%n]==NULL){
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->val = x;
        t->next = NULL;
        ht[x%n] = t;
        return;
    }
    else{
        ht[x%n]=insert_helper_func(ht[x%n],x);
    }
}

void search(struct Node* ht[],int x,int n){
    struct Node* ptr=ht[x%n];
    int count;
    if(ptr==NULL){
        printf("-1\n");
        return;
    }else{
        count=1;
        while(ptr!=NULL&&ptr->val!=x){
            ptr=ptr->next;
            count++;
        }
        if(ptr==NULL){
            printf("-1\n");
            return;
        }
        else{
            printf("%d %d\n",x%n,count);
        }
    }
}

void delete_func(struct Node* ht[],int x,int n){
    struct Node* ptr=ht[x%n];
    struct Node* prev=NULL;
    int count;
    if(ptr==NULL){
        printf("%d\n",-1);
        return;
    }
    else{
        count=1;
        while(ptr!=NULL&&ptr->val!=x){
            prev=ptr;
            ptr=ptr->next;
            count++;
        }
        if(ptr==NULL){
            printf("-1\n");
            return;
        }
        else{
            printf("%d %d\n",x%n,count);
            if(ptr==ht[x%n]){
                ht[x%n]=ht[x%n]->next;
                free(ptr);
                return;
            }else{
                prev->next=ptr->next;
                free(ptr);
            }
        }
    }
}


bool check_presence(struct Node* ht[],int x,int n){
    struct Node* ptr=ht[x%n];
    int count;
    if(ptr==NULL){
        return 1;
    }else{
        count=1;
        while(ptr!=NULL&&ptr->val!=x){
            ptr=ptr->next;
            count++;
        }
        if(ptr==NULL){
            return true;
        }
        else{
            return false;
        }
    }
}

void update(struct Node* ht[],int x,int second,int n){
    struct Node* ptr=ht[x%n];
    struct Node* prev=NULL;
    int count;
    if(check_presence(ht,x,n)||!check_presence(ht,second,n) || ptr == NULL){
        printf("-1\n");
        return;
    }
    else{
        count=1;
        while(ptr!=NULL&&ptr->val!=x){
            prev=ptr;
            ptr=ptr->next;
            count++;
        }
        if(ptr==NULL){
            printf("-1\n");
            return;
        }
        else if(ptr==ht[x%n]){
        	printf("%d %d\n",x%n,count);
                ht[x%n]=ht[x%n]->next;
                free(ptr);
                insert(ht,second,n);
                return;
        }
        else{
        	printf("%d %d\n",x%n,count);
        	prev->next=ptr->next;
                free(ptr);
                insert(ht,second,n);
                return;
        }
    }
}
