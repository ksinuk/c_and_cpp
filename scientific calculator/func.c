#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TEXTLINE 256

int str_count(char *str , char c)
{
    int out=0 , i=0;

    while(*(str+i))
    {
        if(*(str+i)==c) out++;
        i++;
    }

    return out;
}

char* strcpy_mid(char *str , int start, int end)
{
    char out[TEXTLINE] = {0};

    int i=0;
    for(i=0;i<=end-start;i++) 
        out[i] = str[start+i];
    out[i] = 0;

    return out;
}