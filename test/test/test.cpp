#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int func(int size , int now , int arr[],int type) {
	if(size==now) {
		for(int i = 0; i<size; i++) printf("%d " , arr[i]);
		printf("\n");
		return 0;
	}
	int start = 1;
	if(now!=0 && type==2) start = arr[now-1];
	for(int i = start; i<=6; i++) {
		arr[now] = i;

		if(type==3) {
			int j = 0;
			for(; j<now; j++) 
				if(arr[j]==i) 
					break;
			if(j!=now) continue;
		}


		func(size , now+1 , arr,type);
	}
	return 0;
}

int cal_main(const int size , const int cases) {
	int arr[5] = {0};
	func(size , 0 , arr,cases);

	return 0;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("주사위_던지기1.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	
	for(int i = 0; i<N; i++) {
		int size,cases;
		scanf("%d %d",&(size),&cases);
		cal_main(size,cases);
		//printf("%d\n", cal_main(size));
	}

	return 0;
}
