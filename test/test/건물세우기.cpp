/*
#define FREOPEN
//#define DEBUG
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int size) {
	int map[10][10];
	for(int y = 0; y<size; y++)
		for(int x = 0; x<size; x++) scanf("%d" , &map[y][x]);

#ifdef DEBUG
	int min = 200000;
#else
	int min = 0;
	for(int i = 0; i<size; i++) min += map[i][i];
#endif // DEBUG

	int stack[10] = {0};
	int history[10] = {0};
	for(int i = 0; i<size; i++) {
		stack[i] = i;
		history[i] = i;
	}
	int index = 0;
	int sum[10] = {0};

	while(index>=0) {
#ifdef DEBUG
		if(index==size-1 && size<6) {
			for(int i = 0; i<=index; i++)printf("%d " , history[i]);
			printf("\n");
		}
#endif // DEBUG


		sum[index] = map[index][stack[index]]+((index==0) ? 0 : sum[index-1]);
		if(index==size-1) {
			min = (sum[index]<min) ? sum[index] : min;
		}

		if(index!=size-1 && sum[index]<=min) {
			index++;
		}
		else {
			while(index>=0 &&history[index]==size-1) {
				swap(stack[index] , stack[history[index]]);
				history[index--] = index;
			}
			if(index<0) break;

			swap(stack[index] , stack[history[index]]);
			history[index]++;
			swap(stack[index] , stack[history[index]]);
		}
	}

	return min;
}

int main(void)
{
	int N = 1;
#ifdef FREOPEN
	freopen("건물세우기.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {

		int size; scanf("%d" , &size);
		int out = cal_main(size);

		printf("%d\n" , out);
#ifdef FREOPEN
		printf("-----------------------\n");
#endif // FREOPEN
	}

	return 0;
}

*/