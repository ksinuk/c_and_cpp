/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int search(int size , int now , int cows[ ] , int minout , int sum, int len) {
	if(minout<=sum) return minout;
	if(size==now) {
		return (len>sum) ? minout : sum;
	}

	minout = search(size , now+1 , cows , minout , sum+cows[now] , len);
	minout = search(size , now+1 , cows , minout , sum , len);

	return minout;
}


int cal_main(int size , int len) {
	int cows[22] ={0};
	int minout = -1;

	for(int i=0; i<size;i++) {
		int temp=0;
		scanf("%d" , &temp);
		if(temp==len) return 0;
		else if(temp>len) {
			minout = (minout>temp) ? temp : minout;
			size--;
		}
		else cows[i] = temp;
	}

	if(minout<0) {
		minout = 0;
		for(int i=0; i<size || minout<len; i++) {
			minout += cows[i];
		}
	}

	minout = search(size , 0 , cows , minout , 0 , len);

	return minout-len;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("Ã¥²ÈÀÌ.txt" , "r" , stdin);
#endif // FREOPEN
	scanf("%d" , &N);
	for(int i = 0; i<N; i++) {
		int cow_num , len;
		scanf("%d %d" , &(cow_num) , &(len));
		printf("%d\n" , cal_main(cow_num , len));
	}

	return 0;
}


*/