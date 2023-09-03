#include <stdio.h>
#include <stdlib.h>

void print_array(double arr[],int n){
    for(int i=0;i<n;i++){
        printf("%.2lf ",arr[i]);
    }printf("\n");
}

struct Node{
    double val;
    struct Node* next;
};

void bucket_sort(double arr[],int n){
    struct Node* buckets[10];
    for(int i=0;i<10;i++){
        buckets[i] = NULL;
    }
    int required_idx;
    for(int i=0;i<n;i++){
        required_idx = 10*arr[i];
        struct Node* x = (struct Node*)malloc(sizeof(struct Node));
        x->val = arr[i];
        x->next = NULL;

        if(buckets[required_idx]==NULL){
            buckets[required_idx] = x;
        }
        else{
            struct Node* ptr = buckets[required_idx];
            struct Node* trail = NULL;
            while(ptr != NULL && ptr->val <= arr[i]){
                trail = ptr;
                ptr = ptr->next;
            }
            if(trail == NULL){
                x->next = ptr;
                buckets[required_idx] = x;
            }
            else{
                trail->next = x;
                x->next = ptr;
            }

        }
    }
    int idx=0;
    struct Node* ptr;
    struct Node* temp;
    for(int i=0;i<10;i++){
        ptr = buckets[i];   
        while(ptr != NULL){
            arr[idx++] = ptr->val;
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    double arr[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&arr[i]);
    }
    bucket_sort(arr,n);
    print_array(arr,n);
    return 0;
}