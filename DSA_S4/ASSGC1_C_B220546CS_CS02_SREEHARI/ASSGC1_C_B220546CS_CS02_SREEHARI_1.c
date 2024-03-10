#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#define max(m,n) (m >= n ? m : n)
#define min(m,n) (m >= n ? n : m)

void union_func(int a[], int b[], int m, int n);
void intersection_func(int a[], int b[], int m, int n);
void difference_func(int a[], int b[], int m, int n);

int main(){
    int m = 7, n = 7;
    scanf("%d %d", &m, &n);
    int A[m], B[n];
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    char choice[2] = "e";
    char choice1,choice2;
    do{
        scanf("%s",choice);
        if(strcmp(choice,"i") == 0){
            scanf(" %c %c", &choice1, &choice2);
            if(choice1 == 'A'){
                intersection_func(B, A, n, m);
            }
            else{
                intersection_func(A, B, m, n);
            }
        }
        
        else if(strcmp(choice,"u") == 0){
            scanf(" %c %c", &choice1, &choice2);
            if(choice1 == 'A'){
                union_func(A, B, m, n);
            }
            else{
                union_func(B,A,n,m);
            }
        }
        else if(strcmp(choice,"s") == 0){
            scanf(" %c %c", &choice1, &choice2);
            if(choice1 == 'A'){
                difference_func(B, A, n, m);
            }
            else{
                difference_func(A,B, m, n);
            }
        }
    }while(strcmp(choice,"e") != 0);
    return 1;
}

void union_func(int a[], int b[], int m, int n){   
    int hash_map_length = 2*max(m,n);
    int index1,index2;
    int hash[hash_map_length];
    for (int i = 0; i < hash_map_length; i++){
        hash[i] = -1;
    }

    for (int i = 0; i < m; i++){
        if (hash[a[i] % hash_map_length] == -1){
            hash[a[i] % hash_map_length] = a[i];
            printf("%d ", a[i]);
        }
        else{
            if (hash[a[i] % hash_map_length] == a[i]){
                continue;
            }
            for (int j = 0; j < hash_map_length; j++){
                index1 = ((a[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index1] == -1){
                    hash[index1] = a[i];
                    printf("%d ", a[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (hash[b[i] % hash_map_length] == -1){
            hash[b[i] % hash_map_length] = b[i];
            printf("%d ", b[i]);
        }
        else{
            if (hash[b[i] % hash_map_length] == b[i]){
                continue;
            }
            for (int j = 0; j < hash_map_length; j++){
                index2 = ((b[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index2] == -1){
                    hash[index2] = b[i];
                    printf("%d ", b[i]);
                    break;
                }
            }
        }
    }
    printf("\n"); 
}

void intersection_func(int a[], int b[], int m, int n){
    bool flag=true;
    int hash_map_length = 2*max(m,n);
    int index1,index2;
    int hash[hash_map_length];
    int ht[hash_map_length];
    for (int i = 0; i < hash_map_length; i++)
    {
        hash[i] = -1;
        ht[i] = -1;
    }

    for (int i = 0; i < m; i++){
        if (hash[a[i] % hash_map_length] == -1){
            hash[a[i] % hash_map_length] = a[i];
        }
        else{
            if (hash[a[i] % hash_map_length] == a[i]){
                continue;
            }
            for (int j = 0; j < hash_map_length; j++){
                index1 = ((a[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index1] == -1){
                    hash[index1] = a[i];
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if (hash[b[i] % hash_map_length] == -1){
            hash[b[i] % hash_map_length] = b[i];
            ht[b[i] % hash_map_length] = b[i];
        }
        else{
            if (hash[b[i] % hash_map_length] == b[i] && ht[b[i] % hash_map_length] != b[i]){
                flag=false;
                printf("%d ", b[i]);
                ht[b[i] % hash_map_length] = b[i];
                continue;
            }

            for (int j = 0; j < hash_map_length; j++){
                index2 = ((b[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index2] == -1){
                    hash[index2] = b[i];
                    ht[index2] = b[i];
                    break;
                }
            }
        }
    }
    if(flag){
        printf("-1\n");
    }
    else{
	printf("\n");
    }
}

void difference_func(int a[], int b[], int m, int n){
    bool flag=true;
    int hash_map_length = 2*max(m,n);
    int index1;
    int hash[hash_map_length];

    for (int i = 0; i < hash_map_length; i++){
        hash[i] = -1;
    }

    for (int i = 0; i < m; i++){
        if (hash[a[i] % hash_map_length] == -1){
            hash[a[i] % hash_map_length] = a[i];
        }
        else{
            if (hash[a[i] % hash_map_length] == a[i]){
                continue;
            }

            for (int j = 0; j < hash_map_length; j++){
                index1 = ((a[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index1] == -1){
                    hash[index1] = a[i];
                    break;
                }
            }
        }
    }
    int index2;
    for (int i = 0; i < n; i++){
        if (hash[b[i] % hash_map_length] == -1){
            flag=false;
            hash[b[i] % hash_map_length] = b[i];
            printf("%d ", b[i]);
        }
        else{
            if(hash[b[i] % hash_map_length] == b[i]){
                continue;
            }
            for (int j = 0; j < hash_map_length; j++){
                index2 = ((b[i] % hash_map_length) + j) % hash_map_length;
                if (hash[index2] == -1){
                    flag=false;
                    hash[index2] = b[i];
                    printf("%d ", b[i]);
                    break;
                }
            }
        }
    }
    if(flag){
        printf("-1\n");
    }
    else{
    	printf("\n");
    }
}
