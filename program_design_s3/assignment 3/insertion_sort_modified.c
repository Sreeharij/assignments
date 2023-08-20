#include <stdio.h>

void insertion_sort_modified(double arr[],int n,int x,int d){
    int start = n-x;
    double current;
    int j;
    for(int i=start;i<start + d;i++){
        current = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j] > current){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }
    for(int i=0;i<n-1;i++){
        printf("%.2lf ",arr[i]);
    }
    printf("%.2lf",arr[n-1]);

}

int main(){
    int n,x,d;
    scanf("%d",&n);
    double arr[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&arr[i]);
    }
    scanf("%d",&x);
    scanf("%d",&d);
    insertion_sort_modified(arr,n,x,d);
    return 0;
}