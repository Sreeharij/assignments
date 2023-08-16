//OPTIMISING USING BINARY SEARCH

#include <stdio.h>

int check_feasibility(int arr[],int n,int m,int middle_time){
    int feasibility_flag = 0;
    int current_time=0;
    int days_required = 1;
    for(int i=0;i<m;i++){
        if(current_time + arr[i] > middle_time){
            days_required++;
            current_time=0;
        }
        current_time += arr[i];
    }
    feasibility_flag = days_required <= n ? 1 : 0;
    return feasibility_flag;
}

int func(int arr[],int n,int m){
    int answer=0;
    int max_val = arr[0];
    int sum_arr = 0;
    for(int i=0;i<m;i++){
        max_val = max_val > arr[i] ? max_val : arr[i];
        sum_arr += arr[i];
    }
    int left = max_val,right = sum_arr;
    int middle_time;
    while(left<=right){
        middle_time = (left+right)/2;        

        if(check_feasibility(arr,n,m,middle_time)){
            answer = middle_time;
            right = middle_time - 1;
        }
        else{
            left = middle_time + 1;
        }
    }
    return answer;

}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[m];
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",func(arr,n,m));

    return 1;
}
