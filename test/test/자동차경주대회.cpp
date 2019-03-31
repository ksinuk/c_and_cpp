/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int search(int table[][52], int size, int now, int minout, int sum) {
	if(size-1==now) {
		return sum;
	}

	for(int i=now+1; i<size; i++) {
		if(table[now][i]>=0 && sum+table[now][i]<minout)
			minout = search(table , size , i , minout , sum+table[now][i]);
	}

	return minout;
}


int cal_main(int maxlen , int size) {
	int lens[52] ={0};
	int times[52] ={0};
	int table[52][52] = {0};
	int minout=0;
	int sum = 0;

	for(int i=1; i<size; i++) {
		scanf("%d" , lens+i);
		lens[i] += lens[i-1];
	}
	for(int i=1; i<size-1; i++) {
		scanf("%d" , times+i);
		minout += times[i];
	}

	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++) table[i][j] = -1;

	for(int i=0; i<size-1; i++) {
		int min = -1;
		for(int j=size-1; j>i; j--) {
			if(lens[j]-lens[i]>maxlen) continue;
			if(min<0 || times[j]<min)
			min = table[i][j] = times[j];
		}
	}

	//------------------------------------------------

	minout = search(table , size , 0 , minout , sum);

	return minout;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("자동차경주대회.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int maxlen,size;
		scanf("%d %d" , &(maxlen) , &(size));
		printf("%d\n" , cal_main(maxlen , size+2));
	}

	return 0;
}



*/