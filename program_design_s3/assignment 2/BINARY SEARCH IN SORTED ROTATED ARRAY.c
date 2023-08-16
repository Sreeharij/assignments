//BINARY SEARCH IN SORTED ROTATED ARRAY

#include <stdio.h>

int main(){
    int n,k;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    
    int left = 0,right = n-1,mid;
    int found_flag = 0;
    while(left<=right){
        mid = (left + right) / 2;
        if(arr[mid] == k){
            found_flag = 1;
            printf("%d",mid);
            break;
        }
        if(arr[left] <= arr[mid]){
            if((arr[left]<=k) && (k<=arr[mid])){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if((arr[mid] <= k) && (k<=arr[right])){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    if(!found_flag){
        printf("-1");
    }
    return 1;
}
