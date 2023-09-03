#include <stdio.h>

void reset_frequency_arr(int cumulative_frequency[]){
    for(int i=0;i<10;i++){
        cumulative_frequency[i] = 0;
    }
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}

void radix_sort(int arr[],int n){
    int max_val = arr[0];
    for(int i=1;i<n;i++){
        max_val = max_val > arr[i] ? max_val : arr[i]; 
    }
    int exponential = 1;

    int temp_arr[n];
    int cumulative_frequency[10];
    int required_idx;
    while(max_val/exponential > 0){
        reset_frequency_arr(cumulative_frequency);
        for(int i=0;i<n;i++){
            cumulative_frequency[(arr[i]/exponential)%10] += 1;
        }
        for(int i=1;i<10;i++){
            cumulative_frequency[i] += cumulative_frequency[i-1];
        }
        for(int i=n-1;i>=0;i--){
            required_idx = cumulative_frequency[(arr[i]/exponential)%10] - 1;
            temp_arr[required_idx] = arr[i];
            cumulative_frequency[(arr[i]/exponential)%10] -= 1;
        }
        for(int i=0;i<n;i++){
            arr[i] = temp_arr[i];
        }
        exponential *= 10;
    }
    print_array(arr,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radix_sort(arr,n);

    return 0;
}