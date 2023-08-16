//FANCY STRING
#include <stdio.h>

int main()
{
    char sentence[1000];
    int freq_arr[52] = {0};
    scanf("%s",sentence);
    for(int i=0;i<1000;i++){
        if(sentence[i] == '\0'){
            break;
        }
        else{
            if(sentence[i]<=90){
                freq_arr[sentence[i] - 'A'] += (i+1);
            }
            else{
                freq_arr[sentence[i] - 'a' + 26] += (i+1);
            }
        }
    }
    int highest_freq = 0;
    for(int i=0;i<52;i++){
        highest_freq = freq_arr[i] > highest_freq ? freq_arr[i] : highest_freq;
    }
    for(int i=0;i<1000;i++){
        if(sentence[i] == '\0'){
            break;
        }
        else if((sentence[i] <= 90) && freq_arr[sentence[i] - 'A'] == highest_freq){
            printf("%c",sentence[i]);
            break;
        }
        else if(freq_arr[sentence[i] - 'a' + 26]==highest_freq){
            printf("%c",sentence[i]);
            break;
        }
        
    }

    return 0;
}
