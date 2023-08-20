#include <stdio.h>

void selection_sort_func(int arr[],int n){
    int current_max_idx;
    int temp;
    for(int i=0;i<n-1;i++){ 
        current_max_idx = i;
        for(int j=i+1;j<n;j++){
            current_max_idx = arr[current_max_idx] > arr[j] ? current_max_idx : j;
        }
        temp = arr[i];
        arr[i] = arr[current_max_idx];
        arr[current_max_idx] = temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort_func(arr,n);
    return 0;
}