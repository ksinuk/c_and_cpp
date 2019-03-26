/*
#define FREOPEN
#define DEBUG
#include <iostream>

class Point {
public:
	int y , x;
	Point(int yin = -1 , int xin = -1) {
		y = yin;
		x = xin;
	}
};

int map[29][29];
int out[700];

inline void swap(int &a , int &b) {
	int temp=a;
	a = b;
	b = temp;
}

void sort(int arr[] , int size) {
	if(size<=1) return;
	if(size==2) {
		if(arr[0]>arr[1]) swap(arr[0] , arr[1]);
		return;
	}

	int front = 1 , end = size-1;
	swap(arr[(front+end)/2] , arr[0]);
	int pv = arr[0];

	while(front<=end) {
		while(arr[front]<=pv && front<=size-1) front++;
		while(arr[end]>=pv && end>=1) end--;
		if(front<end) swap(arr[front] , arr[end]);
	}

	swap(arr[end] , arr[0]);

	sort(arr , end);
	sort(arr+end+1 , size-end-1);
}

int apart(int y , int x , int size) {
	Point stack[650];
	stack[0] = Point(y , x);
	int index=1;
	int dy[4] = {0,0,1,-1};
	int dx[4] = {1,-1,0,0};

	int cnt = 1;
	map[y][x] = 0;

	while(index>0) {
		Point now = stack[--index];

		for(int i = 0; i<4; i++) {
			Point next(now.y+dy[i] , now.x+dx[i]);
			if(0>now.x||now.x>=size||0>now.y||now.y>=size) continue;
			if(map[next.y][next.x]!=1) continue;

			stack[index++] = next;
			map[next.y][next.x] = 0;
			cnt++;
		}
	}

	return cnt;
}

int cal_main(int size) {
	for(int y = 0; y<size; y++)
		for(int x = 0; x<size; x++) scanf("%1d" , &map[y][x]);

	int cnt = 0;
	for(int y = 0; y<size; y++)
		for(int x = 0; x<size; x++)
			if(map[y][x]!=0) out[cnt++] = apart(y , x, size);

#ifdef DEBUG
	cnt = 20;
	for(int i = 0; i<cnt; i++) out[i] = ((i+1)*651651+2319)%16;
	for(int i = 0; i<cnt; i++) printf("%d " , out[i]);
	printf("\n");
#endif // DEBUG


	sort(out,cnt);


	printf("%d\n" , cnt);
	for(int i = 0; i<cnt; i++) {
		printf("%d\n" , out[i]);
	}

	return 0;
}

int main()
{
	int N = 1;
#ifdef FREOPEN
	freopen("단지_번호붙이기.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int testcase = 0; testcase<N; testcase++) {
		int x; scanf("%d" , &x);
		cal_main(x);
#ifdef FREOPEN
		printf("---------------\n");
#endif // FREOPEN


	}

	return 0;
}
*/