#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int pick_and_sum(char *text);

int main()
{
    int out = pick_and_sum("The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog");
    printf("%d\n",out);

    return 0;
}

// def pick_and_sum(text):
int pick_and_sum(char *text)
{
    int i=0;
    for(i=0;*(text+i);i++){}
//  out = 0  
    int out = 0;
//  num_str = ''
    char *num_str = (char*) malloc (sizeof(char)*i);
    int char_index=0;
//  for temp in text:

    for(i=0;*(text+i);i++)
    {
//      if temp.isdecimal():
        if(isdigit(*(text+i)))
        {
//          num_str+=temp            
            num_str[char_index++]=*(text+i);
            num_str[char_index]=0;
        }
//      elif num_str:
        else if(char_index!=0)
        {
//          out+=int(num_str)
            out +=atoi(num_str);
//          num_str = ''
            char_index=0;
        }
    }
//  if text[-1].isdecimal():
    if(char_index)
    {
//      out+=int(num_str)
        out +=atoi(num_str);
        char_index=0;
    }

    free(num_str);
//  return out
    return out;
}

