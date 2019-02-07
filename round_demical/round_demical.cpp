#include<iostream>
#include <cstdio>
#define DEBUG
#define VSCODE
using namespace std;



int gcd(int a, int b)
{
    while(1)
    {
        if(b>a)
        {
            int temp = b;
            b=a;
            a=temp;
        }
        else if(a==b) return a;
        
        a=a%b;
        
        if(a==0) return b;
    }
    return 1;   
}

int cal(int a, int b)
{
    int gcdn = gcd(a,b);
    a = a/gcdn;
    b = b/gcdn;    
    
    printf("%d",int(a/b));
    a=a%b; 
    if(a)printf(".");
    else return 0;

    int ten=0;
    while(b%10==0) {b/=10;ten++;}
    while(b%2==0){a*=5;b/=2;ten++;}
    while(b%5==0){a*=2;b/=5;ten++;}

    if(a>=b)
    {
        int temp = int(a/b);
        int x=1 ,x10=10;
        while(temp>=1)
        {
            if(temp<x10)
                break;
            
         	x10*=10;
            x++;
        }
        for(int i=x;i<ten;i++) printf("0");
		printf("%d",int(a/b));
        a=a%b;
    }
    else
    	for(int i=0;i<ten;i++) printf("0");

    int num_i=0 , num_o=0;
    
    if(a>0) printf("(");
    else return 0;  
    
    while(a>0)
    {
        a*=10;
        int temp = int(a/b);
        a=a%b;
        
        if(num_i==0)
        {
            num_o = temp;
            num_i=a;
            printf("%d",temp);
        }
        else if(num_i==a && num_o==temp) break;
        else printf("%d",temp);
    }
    printf(")");
    
    return 0;
}

int main()
{
    int T=1;
#ifdef VSCODE
    freopen("round_demical_input.txt", "r", stdin);
#endif
#ifndef DEBUG
	cin>>T;
#endif

	for(int test_case = 1; test_case <= T; ++test_case)
	{
    #ifndef DEBUG  
		int a,b;
        cin>>a>>b;

        printf("#%d ",test_case);
        cal(a,b);
        printf("\n");
    #else
        for(int a=1;a<990;a++)
            for(int b=1;b<=990;b++)
            {
                    
            }



    #endif

        
        
	}
    



	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}