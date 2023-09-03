#include <stdio.h>

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}

void swap(int arr[],int first,int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void func(int arr[],int n,int energy){
    int current_min_idx,current_max_idx;
    int switch_flag = 0;
    for(int i=0;i<n-1;i++){
        if(energy <= 0){
            break;
        }
        current_min_idx = i;
        current_max_idx = i;
        for(int j=i+1;j<n;j++){
            current_min_idx = arr[current_min_idx] < arr[j] ? current_min_idx : j;
            current_max_idx = arr[current_max_idx] > arr[j] ? current_max_idx : j;
        }
        if(switch_flag == 0){
            swap(arr,i,current_min_idx);
            if(i!=current_min_idx && arr[i]!=arr[current_min_idx]){
                energy--;
            }
            switch_flag = 1;
        }
        else if(switch_flag == 1){
            swap(arr,i,current_max_idx);
            if(i!=current_max_idx && arr[i]!=arr[current_max_idx]){
                energy--;
            }
            switch_flag = 0;
        }
    }
}

int main(){
    int n,energy;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&energy);
    func(arr,n,energy);
    print_array(arr,n);
    return 0;
}