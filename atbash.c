#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define TXT 1024
#define WORD 30

static bool bol = false ;
static bool isFirst = true ;

void reverse(char word [], int lWord) {
    char meanWhile [lWord] ;
    int j = 0 ;
    for(int i = lWord-1; i >= 0;i-- ){
        meanWhile[j] =  word[i];
        j ++;
    }
    memcpy(word, meanWhile, lWord);
}
void createWord(char w[], int lWord){                 //////////////// only the real chars move on plus \0
    int i = 0;
    while (w[i]!= '\0') {
        if (w[i] < 65 || (w[i] > 90 && w[i] < 97) || w[i] > 122) {
            i++;
            continue;
        }
        if(w[i] < 97) {
            char mashlim = 155 - w[i];
            w[i] = mashlim;
        }
        else if(w[i] >= 97 ){
            char mashlim = 219 - w[i];
            w[i] = mashlim;
        }
        i++;
    }
}
char* downaLetter(char* q , int counter, int lWord) {
    if (counter== 1) {
        bol = true;
        return NULL;
    }
    char *strMinus1 = malloc((lWord) * sizeof(char));
    int i = 1;
    for(int j = 0 ; j < counter+1 ; j ++ ){
        strMinus1[i - 1] = q[i];
        i++;
    }
    return strMinus1;
}
void atbash(char text[] , char asciWord[], int lWord, int lText) {
    createWord(asciWord, lWord);
    char reverseAsciWorld[lWord];
    strcpy(reverseAsciWorld,asciWord);
    reverse(reverseAsciWorld, lWord);
    char *tempStart = malloc(lText * sizeof(char));
    char *tempEnd = tempStart;
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] != asciWord[0] && text[i] != asciWord[lWord - 1]) {
            i++;
            continue;
            ////// no i anymore;
        } else if (text[i] == asciWord[0]) {
            tempStart = &text[i];
            tempEnd = tempStart;
            int j = 1;
            bool flag = true;
            while (j < lWord) {
                tempEnd++;
                if (*tempEnd < 65 || (*tempEnd > 90 && *tempEnd < 97) || *tempEnd > 122) {
                    continue;    ///// no update j ;
                }
                if (*(tempEnd) != asciWord[j]) {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag == true) {
                if(isFirst){
                    isFirst = false;
                }
                else{
                    printf("~");
                }
                char *pointer = tempStart;
                while (pointer != tempEnd+1) {
                    printf("%c", *pointer);
                    pointer++;
                }
            }
        }
        if (text[i] == reverseAsciWorld[0]) {
            tempStart = &text[i];
            tempEnd = tempStart;
            int k = 1;
            bool flag2 = true;
            while (k < lWord) {
                tempEnd++;
                if (*tempEnd < 65 || (*tempEnd > 90 && *tempEnd < 97) || *tempEnd > 122) {
                    continue; ///// no update k ;
                }
                if (*(tempEnd) != reverseAsciWorld[k]) {
                    flag2 = false;
                    break;
                }
                k++;
            }
            if (flag2 == true) {
                if(isFirst){
                    isFirst = false;
                }
                else{
                    printf("~");
                }
                char *pointer2 = tempStart;
                while (pointer2 != tempEnd+1) {
                    printf("%c", *pointer2);
                    pointer2++;
                }

            }
        }
        i++;
    }
}