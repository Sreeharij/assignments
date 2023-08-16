//FIND FREQUENCY OF CHARACTER IN STRING
#include <ctype.h>
#include <stdio.h>

int main()
{
    char sentence[1000];
    fgets(sentence,1000,stdin);
    char x;
    scanf("%c",&x);
    x = tolower(x);
    int i=0;
    int counter = 0;
    while(sentence[i]!='\0'){
        if(tolower(sentence[i]) == x){
            counter++;
        }
        i+= 1;
    }
    printf("%d",counter);
    return 0;
}
