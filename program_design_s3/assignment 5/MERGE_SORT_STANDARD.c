#include <stdio.h>

void print_array(int arr[],int size);
void merge(int arr[],int left,int mid,int right);
void merge_sort(int arr[],int left,int right);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    print_array(arr,n);
    return 1;
}

void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}

void merge(int arr[],int left,int mid,int right){
    int left_arr_length = mid - left + 1;
    int right_arr_length = right - mid;

    int left_arr[left_arr_length];
    int right_arr[right_arr_length];

    for(int i=0;i<left_arr_length;i++){
        left_arr[i] = arr[left + i];
    }
    for(int j=0;j<right_arr_length;j++){
        right_arr[j] = arr[mid + 1 + j];
    }

    int i=0,j=0,k=left;

    while(i < left_arr_length && j < right_arr_length){
        if(left_arr[i]<=right_arr[j]){
            arr[k++] = left_arr[i++];
        }
        else{
            arr[k++] = right_arr[j++];
        }
    }
    while(i < left_arr_length){
        arr[k++] = left_arr[i++];
    }
    while(j < right_arr_length){
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[],int left,int right){
    if(left >= right){
        return;
    }

    int mid = (left + right)/2;

    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}