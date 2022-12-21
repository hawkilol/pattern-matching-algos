#include <stdio.h>
#include <string.h>

void bf(char* txt, int txtLen, char* pattern, int patternLen){
    //int M = strlen(pattern);
    int M = patternLen;
    //int N  = strlen(txt);
    int N = txtLen;
    int j = 0;
    for(int i = 0; i <= N - M; i++){
        for(j = 0; j < M; j++){
            if(txt[i + j] != pattern[j]){
                break;
            }
        }
        if(j == M){ // if pattern[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found starting at i = %d and ending at j = %d\n", i, i+j-1);

        }
    }
}

int main()
{
    char txt[] = "JAVAJAVAJAVJAVAJAVACJAVA";
    //char txt2[] = "According to the voices of my head, Java sucks and shouldn't be used except if Client has the requirement to do so, (warning) garbage collector can delete the Client upon execution";
    
    char pattern[] = "JAVA";
    //char pattern2[] = "Java sucks";
    
    int textsize = sizeof(txt)/sizeof(txt[0]);
    int patternsize = sizeof(pattern)/sizeof(pattern[0]); 

    bf(txt, textsize, pattern, patternsize);
    return 0;
}
