//FIND LARGEST ELEMENT IN AN ARRAY OF SIZE N
#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int max_val = arr[0];
	for(int i=1;i<n;i++){
		max_val = arr[i] > max_val ? arr[i] : max_val;
	}
	printf("%d",max_val);
	return 0;
}
