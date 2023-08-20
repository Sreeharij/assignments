#include <stdio.h>

void sort_func(int arr[],int n,int k){
    int current_max_idx,temp;
    for(int i=0;i<n-1;i++){
        current_max_idx = i;
        for(int j=i+1;j<n;j++){
            current_max_idx = arr[current_max_idx] > arr[j] ? current_max_idx : j;
        }
        temp = arr[i];
        arr[i] = arr[current_max_idx];
        arr[current_max_idx] = temp;
    }
    for(int i=0;i<k;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort_func(arr,n,k);
    return 0;
}