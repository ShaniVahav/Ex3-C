#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0


int findAndRemove(char copy[], char c, int len){
    char* current = copy+1;
    for(int i=0; i<len; i++){
        if(*current == c){
            *current = '\0';
            return 1;
        }
        current++;
    }
    return 0;
}

void strcopy(char copy[], char w[]){
    for(int i=0; i<strlen(w)-1; i++){
        *(copy+1+i) = *(w+i);
    }
}

void anagram(char w[], char s[]){
    char copy[strlen(w)+1];
    strcopy(copy, w);

    char* start = s, *end = s;
    char c;
    int isFirst = TRUE;
    int find_remove;
    int len_W = strlen(w);
    int counter = len_W -1;

    while(*end != '\0'){
        c = *end;

        if(counter == 0) {
            if(isFirst == TRUE){
                isFirst = FALSE;
            }else{
                printf("~");
            }

            char* run = start;

            for(;run<end; run++){
                printf("%c", *run);
            }

            counter = len_W -1;
            start++;
            end = start;
            strcopy(copy, w);
            continue;
        }

        if (c == ' '){
            if (start == end){
                start++;
                end++;
            }
            else {
                if(findAndRemove(copy, c , len_W)) {
                    counter--;
                }
                end++;}
            continue;
        }

        find_remove = findAndRemove(copy, c, len_W);
        if(find_remove || c == ' '){
            end++;
            counter--;
        }
        else{
            start++;
            end = start;
            counter = len_W -1;
            strcopy(copy, w);
        }
    }
}