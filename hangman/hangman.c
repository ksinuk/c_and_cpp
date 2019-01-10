#include <stdio.h>
#include <string.h>
#define TEXT_LINE 20

int hangman(char *answer);
char* status(char answer[],char letters[],char out[]);

int main()
{
    FILE *f=fopen("hangman.txt","r");
    char answer[TEXT_LINE] = {0};
    fgets(answer,TEXT_LINE,f);

    for(int i=0;i<TEXT_LINE;i++)
    {
        if(isalpha(answer[i])==0)
        {
            answer[i]=0;
            break;
        }
    }

    fclose(f);

    hangman(answer);
    printf("good bye\n");
    scanf("%s",answer);

    return 0;
}

int hangman(char *answer)
{
    int life=8;
    char letters[TEXT_LINE] = {0};
    int letters_index=0;

    while(1)
    {
        printf("life : %d \n",life);
        printf("letters = ");
        for(int i=0;letters[i];i++) //out_letters=' '.join(letters)
            printf("%c ",letters[i]); //print(f'letters = {out_letters}')
        printf("\n");
        printf("status : ");
        char status_text[TEXT_LINE] = {0};
        status(answer,letters,status_text);
        for(int i=0;status_text[i];i++) //out_status_text=' '.join(status_text)
            printf("%c ",status_text[i]); //print(f'status : {out_status_text}')
        printf("\n");

        if(strcmp(status_text,answer)==0)
        {
            printf("----------------------------\n");
            printf("you win!\n");
            printf("----------------------------\n");
            return 0;
        }
        if(life==0)
        {
            printf("you lose!\n");
            printf("answer : %s\n",answer);
            return 0;           
        }     

        printf("Put the alphabet : ");
        char c=0;
        char temp_c[5] = {0};
        scanf("%s",temp_c);
        c=temp_c[0];

        if(strrchr(letters,c))
            printf("The alphabet already in letters\n");
        else if(isalpha(c)==0)
            printf("Just fill in the alphabet.\n");
        else
        {
            letters[letters_index++]=c;
//          letters.sort()
            if(strrchr(answer,c)==NULL)
                life--;        
        }

        printf("----------------------\n");
    }

    return 0;
}

char* status(char answer[],char letters[],char out[])
{
    for(int i=0;answer[i];i++)
    {
        if(strrchr(letters,answer[i]))
            out[i]=answer[i];
        else
            out[i]='_';
    }

    return out;
}       