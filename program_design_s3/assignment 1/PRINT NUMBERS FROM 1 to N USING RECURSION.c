//PRINT NUMBERS FROM 1 to N USING RECURSION

#include <stdio.h>

void print_num(int current,int last){
    if(current == last){
        printf("%d",current);
        return;
    }
    printf("%d ",current);
    print_num(current+1,last);
}

int main()
{
    int n;
    scanf("%d",&n);
    print_num(1,n);

    return 0;
}
