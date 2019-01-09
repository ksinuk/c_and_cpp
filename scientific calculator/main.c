#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TEXTLINE 256

char* calc(char strx[]);
int str_count(char *str , char c);
char* strcpy_mid(char *str , int start, int end);

int main()
{
    char str1[TEXTLINE] = '123+2-124';
    char str2[TEXTLINE] = '-12+12-7979+9191';
    char str3[TEXTLINE] = '+1-1+1-1+1-1+1-1';

    char* out=calc('str1');
    printf("%s : %s \n",str1,out);
    char* out=calc('str2');
    printf("%s : %s \n",str1,out);
    char* out=calc('str3');
    printf("%s : %s \n",str1,out);

    return 0;
}

char* calc(char strx_in[])
{
    char strx[TEXTLINE]={0};
    strcpy(strx,strx_in);
    char operator_list[5] = {'+','-','*','/',0};

//  # 오류 정리
    if(strlen(strx)>5 && strstr(strx,"error")) return strx;
    if(str_count(strx,'(') != str_count(strx,')')) return "error : strx.count(\'(\')!=strx.count(\')\')";

//  # 괄호 정리
    while(strchr(strx,')'))
    {
        int end = strchr(strx,')')-strx;
        int start = end;
        while(strx[start]!='(')
        {
            start--;
            if(start<0) return "error : don`t 1st \')\'";
        }   
        if(start>0 && str_count(operator_list,strx[start-1])==0)
        {            
            if(strx[start-1]!='(') return "error : double operator";
        }

        if(end<strlen(strx)-1 && str_count(operator_list,strx[end+1])==0)
        {
            if(strx[end+1]!=')') return "error : double operator";
        }

        char mid[] = calc(strcpy_mid(strx,start+1,end-1));
        if(strlen(mid)>5 && strstr(mid,"error")) return mid;

        char temp_str[TEXTLINE]=strcpy_mid(strx,end+1,strlen(strx)-1);
        strx[start]=0;
        strcat(strx,mid);
        strcat(strx,temp_str);
    }

//  # 초기화
    char operator_stack[TEXTLINE]={0};
    int operator_stack_index=0;
    float num_stack[TEXTLINE]={0};
    int num_stack_index=0;
 
    if(strx[0]=='-' || strx[0]=='+')
    {
        num_stack[num_stack_index++]=0;
        operator_stack[operator_stack_index++]=strx[0];

        for(int i=0;i<TEXTLINE-1;i++)
        {
            strx[i]=strx[i+1];
            if(strx[i]==0)
                break;
        }
    }
    else if(strx[0]=='*' || strx[0]=='/')
        return "error : 1st char is * or /";
    else if(isdigit(strx[0])==0)
        return "error : not number and not operator";

//  # make stack
    char temp[TEXTLINE]={0};
    int temp_index=0;

    for(int i=0;i<TEXTLINE;i++)
    {
        char c = strx[i];

        if(isdigit(c) || c=='.')
        {
            temp[temp_index++]=c;
        }
        else if(str_count(operator_list,c))
        {
//          if temp:
//              num_stack.append(float(temp))
//              temp=''
//              operator_stack.append(c)
//          else :
//              return 'error : double operator'
        }

//      else :
//          return 'error : not number and not op'
    }

//  if temp:
//      num_stack.append(float(temp))
//      temp=''

}


 
 
        
//     # cal mul,div
//     index=0
//     while '*' in operator_stack or '/' in operator_stack:
//         temp_op = operator_stack[index]
//         if temp_op == '*':
//             operator_stack.pop(index)
//             temp_num = num_stack.pop(index+1)
//             num_stack[index] *= temp_num
//         elif temp_op == '/':
//             operator_stack.pop(index)
//             temp_num = num_stack.pop(index+1)
//             num_stack[index] /= temp_num
//         else :
//             index+=1

//     # cal add , sub
//     out = num_stack.pop(0)
    
//     while operator_stack and num_stack:
//         num = num_stack.pop(0)
//         operator = operator_stack.pop(0)
        
//         if operator=='+':
//             out +=num
//         elif operator=='-':
//             out -=num
        
//     return str(out)