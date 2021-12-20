#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0

// Calculate the gematria sum of the word

int sumOf(char* w){
    char* current = w;
    int sum = 0;
    char c;
    while (*current != '\0')
    {
        c = *current;
        if('a' <= c && c <= 'z'){
            sum += c - 96;
        }else {
            if ('A' <= c && c <= 'Z') {
                sum += c - 64;
            }
        }
        current++;
    }
    return sum;
}

int ascii(char c){
    if('a' <= c && c <= 'z'){
        return c - 96;
    }
    else
    if ('A' <= c && c <= 'Z') {
        return c - 64;
    }

    return 0;
}


void gematria(char w[], char s[]){
    int targetSum = sumOf(w); // the gematria sum of the word

    char* start = s, *end = s;
    char c;
    int isFirst = TRUE;
    int cSum, currentSum = 0;

    while(*end != '\0'){
        c = *end;

        cSum = ascii(c);
        if (cSum == 0){
            if (start == end){
                start++;
                end++;
            }
            else {end++;}
            continue;
        }


        end++;
        currentSum += cSum;

        if(currentSum < targetSum){
            continue;
        }

        if(currentSum > targetSum){

            if(cSum > targetSum){
                start = end;
                currentSum = 0;
                continue;
            }
            if(cSum == targetSum){
                if(isFirst == TRUE){
                    isFirst = FALSE;
                }else{
                    printf("~");
                }
                printf("%c", c);
                currentSum = 0;
                start = end;
                continue;
            }
            if(cSum < targetSum){
                while(start < end && currentSum > targetSum){
                    currentSum -= ascii(*start);
                    start++;
                }
            }
        }

        if (currentSum == targetSum){
            if(isFirst == TRUE){
                isFirst = FALSE;
            }else{
                printf("~");
            }

            char* run = start;
            while(ascii(*run) == 0 && run<end){
                run++;
            }

            for(;run<end; run++){
                printf("%c", *run);
            }

            currentSum -= ascii(*start);
            start++;
        }

    }

}