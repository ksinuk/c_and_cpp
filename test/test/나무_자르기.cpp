/*
#define FREOPEN
//#define DEBUG
#include <iostream>

int arr[1000000];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline void sort(int size) {
	if (size <= 1) return;

	for(int i=0; i<size-1; i+=2) {
		if(arr[i]<arr[i+1]) swap(arr[i] , arr[i+1]);
	}

	int step = 2;
	int now = 0;

	while (step < size) {
		int a = now, b = now+step;
		int aa = a + step, bb = (b+step < size) ? b + step : size;
		int *qu = new int[step*2];
		int index = 0;

		while (a < aa && b < bb) {
			if (arr[a] > arr[b]) qu[index++] = arr[a++];
			else qu[index++] = arr[b++];
		}

		while(a<aa) qu[index++] = arr[a++];
		while(b<bb) qu[index++] = arr[b++];

		for(int i=0; i<index; i++) arr[now + i] = qu[i];

		now += step+step;
		if(now+step>=size) {
			step+=step;
			now=0;
		}

		delete[ ] qu;
	}
}

int cal_main(int size, int get) {
	for(int i=0; i<size; i++) scanf("%d", &arr[i]);
	sort(size);

	for(int i=1; i<size; i++) {
		int d = arr[i-1]-arr[i];
		if(get>d*i) {
			get-=d*i;
			continue;
		}

		int out = get/i , r = get%i;
		return (r>0) ? arr[i-1]-out-1 : arr[i-1]-out;

	}

	return 0;
}

int main(void)
{
	int N = 1;
#ifdef FREOPEN
	freopen("나무_자르기.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {
		int size , get;
		scanf("%d %d" , &size,&get);
		int out = cal_main(size,get);

		printf("%d\n" , out);
#ifdef FREOPEN
		printf("-----------------------\n");
#endif // FREOPEN
	}

	return 0;
}
*/