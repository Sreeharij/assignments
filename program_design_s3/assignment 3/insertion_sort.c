#include <stdio.h>

void sort_func(int arr[],int n){
    int current,j;
    for(int i=1;i<n;i++){
        current = arr[i];
        for(j=i-1;j>=0;j--){
            if(current < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
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
    sort_func(arr,n);
    return 0;
}