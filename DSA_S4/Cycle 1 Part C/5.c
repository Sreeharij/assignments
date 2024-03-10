#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define UPPER_LIMIT 1000

struct Node{
    int val;  
    struct Node* next;
};

struct Node* create_node(int x){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->val = x;
    t->next = NULL;
    return t;
}

void func(int arr[],int n,int k){
    int unique_count = 0;
    struct Node* hash_table[UPPER_LIMIT];
    for(int i=0;i<UPPER_LIMIT;i++){ 
        hash_table[i] = NULL;
    }
    for(int i=0;i<k;i++){
        struct Node* t = create_node(arr[i]); 
        if(hash_table[arr[i]%UPPER_LIMIT] == NULL){
            hash_table[arr[i]%UPPER_LIMIT] = t;
            unique_count++;
        }
        else{
            struct Node* ptr = hash_table[arr[i]%UPPER_LIMIT];
            struct Node* trail = NULL;
            while(ptr && arr[i] >= ptr->val){
                trail = ptr;
                ptr = ptr->next;
            }
            if(!trail){ //current element as first element
                t->next = hash_table[arr[i]%UPPER_LIMIT];
                hash_table[arr[i]%UPPER_LIMIT] = t;
            }
            else{
                if(trail->val != arr[i]){
                    unique_count++;
                }
                t->next = trail->next;
                trail->next = t;
            }
        }
    }
    printf("%d ",unique_count);
    int left = 0,right = k-1;
    while(right < n){
        struct Node* ptr = hash_table[arr[left]%UPPER_LIMIT];
        struct Node* trail = NULL;
        while(ptr && ptr->val != arr[left]){
            trail = ptr;
            ptr = ptr->next;
        }
        if(!trail){ //for first value
            hash_table[arr[left]%UPPER_LIMIT] = ptr->next;
        }
        else{
            trail->next = ptr->next;
        }
        if(!(ptr->next && ptr->val == ptr->next->val)){
            unique_count--;
        }
        free(ptr);
        left++;
        right++;
        if(right >= n) break;

        struct Node* t = create_node(arr[right]);
        if(hash_table[arr[right]%UPPER_LIMIT] == NULL){
            unique_count++;
            hash_table[arr[right]%UPPER_LIMIT] = t;
        }
        else{
            ptr = hash_table[arr[right]%UPPER_LIMIT];
            trail = NULL;
            while(ptr && arr[right] >= ptr->val){
                trail = ptr;
                ptr = ptr->next;
            }
            if(!trail){ //current element as first element
                t->next = hash_table[arr[right]%UPPER_LIMIT];
                hash_table[arr[right]%UPPER_LIMIT] = t;
            }
            else{
                if(trail->val != arr[right]){
                    unique_count++;
                }
                t->next = trail->next;
                trail->next = t;
            }
        }
        printf("%d ",unique_count);
    }
    printf("\n");
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(arr,n,k);
    return 0;
}
