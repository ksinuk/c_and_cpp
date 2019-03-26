/*
#define FREOPEN
#define DEBUG
#include <iostream>

int table[10][10];
int check[10];

int cal_main(int two, int size ,int now=0,int sum=0) {
	if(now==size) {
		return sum;
	}

	int min = 888888;
	for(int i = 0; i<size; i++) {
		if(sum+table[now][i]>=min) continue;
		if(two!=0||check[i]==0) {
			if(two==0) check[i] = 1;
			int temp = cal_main(two , size , now+1 , sum+table[now][i]);
			min = (temp<min) ? temp : min;
			check[i] = 0;
		}
	}


	return min;
}

int main(void)
{
	int N = 1;
#ifdef FREOPEN
	freopen("최소의_합.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {
		for(int i = 0; i<10; i++) check[i] = 0;

		int size; scanf("%d" , &size);
		for(int y = 0; y<size; y++)
			for(int x = 0; x<size; x++) scanf("%d" , &table[y][x]);
		int out1 = cal_main(1,size);
		int out2 = cal_main(0,size);

		printf("%d\n%d\n" , out1 , out2);
#ifdef FREOPEN
		printf("-----------------------\n");
#endif // FREOPEN
	}

	return 0;
}

*/