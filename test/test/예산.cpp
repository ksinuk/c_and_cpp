/*
#define FREOPEN
//#define DEBUG
#include <iostream>

inline void sort(int arr[] , int size) {
	int step = 1;
	int now = 0;

	while(step<size) {
		int *qu = new int[step*2];
		int index = 0;
		int a = now , acut = now+step;
		int b = now+step , bcut = acut+step;
		if(bcut>size) bcut = size;

		while(a<acut && b<bcut) {
			if(arr[a]>arr[b]) qu[index++] = arr[a++];
			else qu[index++] = arr[b++];
		}

		while(a<acut) qu[index++] = arr[a++];
		while(b<bcut) qu[index++] = arr[b++];

		for(int i = 0; i<index; i++) arr[now+i] = qu[i];

		now += step*2;
		if(now+step>size) {
			now = 0;
			step *= 2;

		}

		delete[] qu;
	}

}


int cal_main(int size) {
	int arr[10000];
	for(int i = 0; i<size; i++) scanf("%d" , arr+i);
	sort(arr , size);
	int cut; scanf("%d" , &cut);

	int avg = cut/size , avg_r = cut%size;
	int sum = 0; for(int i = 0; i<size; i++) sum += arr[i];
	if(sum<=cut) return arr[0];
	int over = sum-cut;

	if(avg<=arr[size-1]) return ((avg_r>0) ? avg+1 : avg);

	for(int i = 1; i<size; i++) {
		int d = arr[i-1]-arr[i];
		if(over<=d*i) {
			avg = over/i; avg_r = over%i;
			return ((avg_r>0) ? arr[i-1]-avg-1 : arr[i-1]-avg);
		}

		over -= d*i;
	}

	return 0;
}

int main()
{
#ifdef FREOPEN
	freopen("¿¹»ê.txt" , "r" , stdin);
#endif // FREOPEN
	int N = 2;
	for(int testcase = 0; testcase<N; testcase++) {
		int size; scanf("%d" , &size);
		printf("%d\n" , cal_main(size));
	}

	return 0;
}
*/