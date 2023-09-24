#include <stdio.h>

void swap(int *a,int *b);
void heapify(int arr[],int n,int i);
void heap_sort(int arr[],int n);
void print_array(int arr[],int size);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heap_sort(arr,n);
    print_array(arr,n);
    return 1;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right<n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);

        heapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);

        heapify(arr,i,0);
    }
}

void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}