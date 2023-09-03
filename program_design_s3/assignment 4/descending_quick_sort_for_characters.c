#include <stdio.h>

void print_array(char arr[],int n){
    for(int i=0;i<n;i++){
        printf("%c ",arr[i]);
    }printf("\n");
}

void swap(char arr[],int first,int second){
    char temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void push_median_to_left(char arr[],int left,int right){
    int centre = (left + right)/2;
    if(arr[centre] < arr[left]){
        swap(arr,left,centre);
    }
    if(arr[right] < arr[left]){
        swap(arr,left,right);
    }
    if(arr[centre] < arr[right]){
        swap(arr,left,centre);
    }
    else{
        swap(arr,left,right);
    }
}

void quick_sort(char arr[],int left,int right){
    if(left >= right){
        return;
    }
    push_median_to_left(arr,left,right);
    int pivot_idx = left;
    int left_ptr = left + 1; 
    int right_ptr = right;

    while(left_ptr <= right_ptr){
        while(left_ptr <= right && arr[left_ptr] >= arr[pivot_idx]){
            left_ptr++;
        }
        while(right_ptr >= pivot_idx && arr[right_ptr] < arr[pivot_idx]){
            right_ptr--;
        }
        if(left_ptr < right_ptr){
            swap(arr,left_ptr,right_ptr);
        }
    }
    swap(arr,pivot_idx,right_ptr);
    quick_sort(arr,left,right_ptr - 1);
    quick_sort(arr,right_ptr+1,right);

}

int main(){
    int n;
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    print_array(arr,n);
    return 0;
}