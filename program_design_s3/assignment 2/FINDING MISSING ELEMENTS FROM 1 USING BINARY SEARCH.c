//FINDING MISSING ELEMENTS FROM 1 USING BINARY SEARCH

#include <stdio.h>

int find_missing(int arr[],int n,int k){
    if((arr[n-1] - (n-1) - 1) < k){
        return -1;
    }
    int left = 0,right = n-1,mid = 0;
    int current_missing = 0;

    while(left<=right){
        mid = (left + right)/2;
        current_missing = arr[mid] - mid - 1;

        if(current_missing == k){
            break;
        }
        else if(current_missing < k){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    int answer = 0;
    if(mid > 0){
        answer = arr[mid-1] + (k - (arr[mid-1] - (mid-1 + 1)));
    }
    else{
        answer = k;
    }
    return answer;

}

int main(){
    int n,k;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    printf("%d",find_missing(arr,n,k));
    return 1;
}
