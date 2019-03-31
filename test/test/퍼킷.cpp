/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int search(int size , int now , int s[ ] , int b[ ] , int minout , int sumb , double muls) {
	if(size==now) {
		if(sumb==0) return minout;
		int temp  = muls - sumb;
		temp = (temp<0) ? -temp : temp;
		return (minout<temp) ? minout : temp;
	}

	minout = search(size , now+1 , s , b , minout , sumb+b[now] , muls*s[now]);
	minout = search(size , now+1 , s , b , minout , sumb , muls);

	return minout;
}


int cal_main(int size) {
	int s[12] ={0};
	int b[12] ={0};
	double minout=0;

	for(int i=0; i<size; i++) {
		scanf("%d %d" , s+i , b+i);
	}

	int sumb=0;
	double muls = 1;
	for(int i=0; i<size; i++) {
		sumb += b[i];
		muls *= s[i];

	}
	double temp = muls - sumb;
	minout = (temp<0) ? -temp : temp;

	minout = search(size , 0 , s , b , minout , 0 , 1);

	return minout;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("ÆÛÅ¶.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		printf("%d\n" , cal_main(size));
	}

	return 0;
}


*/

