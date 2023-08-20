//PEAK FINDING USING BINARY SEARCH

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int left = 0,right = n-1,mid;
    if(n==1){
        printf("%d",arr[0]);
    }
    else if(arr[0] > arr[1]){
        printf("%d",arr[0]);
    }
    else if(arr[n-1] > arr[n-2]){
        printf("%d",arr[n-1]);
    }
    else{
        while(left <= right){
            mid = (left + right)/2;
            if(mid == 0){
                left = mid + 1;
            }
            else if(mid == n-1){
                right = mid - 1;
            }
            else if(arr[mid] > arr[mid - 1]){
                if(arr[mid] > arr[mid + 1]){
                    printf("%d",arr[mid]);
                    break;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                right = mid - 1;
            }
        }
    }

    return 1;
}
