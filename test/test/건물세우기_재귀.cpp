/*

#define FREOPEN
//#define DEBUG
#include <iostream>

int map[10][10];
int arr[10];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int dfs(int size , int now , int sum , int min) {
	if(now==size) return (sum<min) ? sum : min;

	for(int i = now; i<size; i++) {
		swap(arr[now] , arr[i]);
		if(min>=sum+map[now][arr[now]]) {
			int temp = dfs(size , now+1 , sum+map[now][arr[now]] , min);
			min = (temp<min) ? temp : min;
		}

		swap(arr[now] , arr[i]);
	}

	return min;
}

int cal_main(int size) {
	for(int y = 0; y<size; y++)
		for(int x = 0; x<size; x++) scanf("%d" , &map[y][x]);

	int min = 0;
	for(int i = 0; i<size; i++) min += map[i][i];
	for(int i = 0; i<10; i++) arr[i] = i;

	return dfs(size , 0 , 0 , min);
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
