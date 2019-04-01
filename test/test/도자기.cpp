/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline void sort(int arr[] , int size) {
	for(int i = 1; i<size; i++) {
		for(int j = i; j>0; j--) {
			if(arr[j]<arr[j-1]) swap(arr[j] , arr[j-1]);
			else break;
		}
	}
}

int search(int soil[] , int size_oil , int now_oil , int size_out , int now_out , int cnt,int out[]) {
	if(size_out==now_out) {
		return cnt+1;
	}

	for(int i = now_oil; i<size_oil-(size_out-1-now_out); i++) {
		if(i==now_oil||soil[i]!=soil[i-1]) {
			out[now_out] = soil[i];
			cnt = search(soil , size_oil , i+1 , size_out , now_out+1 , cnt,out);
		}
	}

	return cnt;
}

int cal_main(int size_oil, const int size_out) {
	int soil[12];

	int two = 0;
	for(int i = 0; i<size_oil; i++) {
		scanf("%d" , &soil[i]);

		if(soil[i]==soil[i-1]&&two==size_out) {
			i--; size_oil--;
		}
		else if(soil[i]==soil[i-1]){
			two++;
		}
		else {
			two = 1;
			for(int j = i; j>0; j--) {
				if(soil[j]<soil[j-1]) swap(soil[j] , soil[j-1]);
				else break;
			}
		}
	}
	//---------------------------------
	int cnt = 0;
	int out[12];
	cnt = search(soil, size_oil, 0, size_out, 0, cnt,out);

	return cnt;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("µµÀÚ±â.txt" , "r" , stdin);
#endif // FREOPEN
	scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int size,num;
		scanf("%d %d",&num , &(size));
		printf("%d\n", cal_main(num,size));
	}

	return 0;
}
*/