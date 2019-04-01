/*
#define FREOPEN
#include <iostream>

struct Point {
	int y , x;
};

inline void swap(Point &a , Point &b) {
	Point temp = a;
	a = b;
	b = temp;
}

inline void sort(Point arr[] , int size) {
	for(int i = 1; i<size; i++) {
		for(int j = i; j>0; j--) {
			if(arr[j].y<arr[j-1].y) swap(arr[j] , arr[j-1]);
			else if(arr[j].y==arr[j-1].y && arr[j].x<arr[j-1].x) swap(arr[j] , arr[j-1]);
			else break;
		}
	}
}

int search(Point robots[], Point cookies[], int size, int now, int min, int sum) {
	if(size==now) return sum;

	for(int i = now; i<size; i++) {
		swap(cookies[now] , cookies[i]);
		int temp_y = robots[now].y-cookies[now].y;
		int temp = (temp_y<0) ? -temp_y : temp_y;
		int temp_x = robots[now].x-cookies[now].x;
		temp += (temp_x<0) ? -temp_x : temp_x;

		if(sum+temp<min) {
			min = search(robots , cookies , size , now+1 , min , sum+temp);
		}

		swap(cookies[now] , cookies[i]);
	}

	return min;
}

int cal_main(const int size) {
	Point robots[10];
	Point cookies[10];

	for(int i = 0; i<size; i++) {
		int y , x;
		scanf("%d %d" , &y , &x);
		robots[i] = {y,x};
	}
	for(int i = 0; i<size; i++) {
		int y , x;
		scanf("%d %d" , &y , &x);
		cookies[i] = {y,x};
	}
	//---------------------------------
	sort(robots , size);
	sort(cookies , size);
	//----------------------------------
	int min = 100000;

	min = search(robots , cookies , size , 0 , min , 0);



	return min;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("·Îº¿_°úÀÚ_¸Ô±â.txt" , "r" , stdin);
#endif // FREOPEN
	scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		printf("%d\n", cal_main(size));
	}

	return 0;
}


*/