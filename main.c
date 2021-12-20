#include <stdio.h>
#include <string.h>
#include "libClass.h"

#define TXT 1024
#define WORD 30



int main(){
    char word[WORD], str[TXT], c;

    int i = 0;
    while(c != ' ' && c != '\n' && c != '\t') {
        c = getchar();
        word[i] = c;
        i++;
    }

    char wordCopy[strlen(word)];
    strcpy(wordCopy, word);

    i = 0;
    while(c != '~') {
        c = getchar();
        str[i] = c;
        i++;
    }

    printf("Gematria Sequences: ");
    gematria(word, str);

    printf("\nAtbash Sequences: ");
    atbash(str, wordCopy, strlen(wordCopy)-1, strlen(str));

    printf("\nAnagram Sequences: ");
    anagram(word, str);

}