#include <stdio.h>
int num[1000005];
FILE *f;

long long god()
{
    int N=0;
    long long out=0;
    fscanf(f,"%d",&N);
    
    for(int i=0;i<N;i++)
    	fscanf(f,"%d",num+i);

    int prev=0;
    
    while(1)
    {	int max=num[prev];
   		int max_index=prev;
     
        for(int i=prev;i<N;i++)
        {	if(max<=num[i])
            {	max=num[i];
                max_index=i;
            }
        }
     	if(prev==max_index)
            break;

        for(int i=prev;i<max_index;i++)
            out+=max-num[i];

        prev = max_index+1;
        if(prev>=N)
            break;    
    }

    return out;
}

int main()
{
    f = fopen("input.txt","r");

    int N=0;
    fscanf(f,"%d",&N);
   
    for(int i=1;i<=N;i++)
    {
        printf("#%d %lld\n",i,god());
    }

    fclose(f);
    
     return 0;   
}