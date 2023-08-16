//TAYLOR EXPANSION OF SIN X

#include <stdio.h>

int main()
{
    double x;
    int n;
    scanf("%lf",&x);
    scanf("%d",&n);
    n = n%2==0 ? n-1:n;
    x *= 3.1415/180;
    double temp_value = x;
    double result = x;
    int i=3;
    while(i<=n){
        temp_value = (-temp_value)*x*x/i/(i-1);
        result += temp_value;
        i = i+2;
    }
    printf("%.4lf",result);
    return 0;
}
