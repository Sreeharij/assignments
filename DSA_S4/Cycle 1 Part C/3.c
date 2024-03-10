#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#define max(m,n) (m >= n ? m : n)
#define min(m,n) (m >= n ? n : m)

struct Node{
    char roll[10];
    char name[100];
    int age;
    struct Node* next;
};

struct Node* create_node(int age,char name[],char roll[]);
void insert(struct Node* ht[],struct Node* x);

int main(){
    struct Node* ht[4];

    for(int i=0;i<4;i++){
        ht[i]=NULL;
    }
    int n;
    scanf("%d",&n);
    int age;

    struct Node* temp=NULL;

    char name[100],rol[15];

    for(int i=0;i<n;i++){
        scanf("%s %s %d",name,rol,&age);
        temp=create_node(age,name,rol);
        insert(ht,temp);
    }
   
    int k,m;
    char letter[10];
    char choice[2] = "e";

    do{
        scanf("%s",choice);
        if(strcmp(choice,"c") == 0){
            scanf("%d",&k);
            
            int count=0;
            struct Node* ptr=ht[k];
            while(ptr!=NULL){
                count++;
                ptr=ptr->next;
            }
            printf("%d ",count);
            ptr=ht[k];
            while(ptr!=NULL){
                printf("%s ",ptr->name);
                ptr=ptr->next;
            }
            printf("\n");

        }
        else if(choice[0] < '5'){
            m = choice[0] -'0';
            scanf("%s",letter);
            

            struct Node* ptr=ht[m];
            bool flag=true;
            while(ptr!=NULL){
                if((ptr->roll[7]==tolower(letter[0])||ptr->roll[7]==toupper(letter[0]))&&(ptr->roll[8]==toupper(letter[1])||ptr->roll[8]==tolower(letter[1]))){
                    flag=false;
                    printf("%s ",ptr->name);
                }
                ptr=ptr->next;
            }
            if(flag){
                printf("-1");
            }
            printf("\n");

        }

    }while(strcmp(choice,"e") != 0);
    
    return 1;
}

struct Node* create_node(int age,char name[],char roll[]){
    struct Node* tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->age=age;
    strcpy(tmp->name,name);
    strcpy(tmp->roll,roll);
    tmp->next=NULL;
    return tmp;
   
}

void insert(struct Node* ht[],struct Node* x){
    int sum = x->age,i=0;
    while(x->name[i]!='\0'){
        sum = sum + x->name[i++];
    }
    int index = sum%4; 

    if(ht[index]==NULL){
        ht[index]=x;
    }
    else{
        struct Node* ptr=ht[index];
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=x;
    }
}
