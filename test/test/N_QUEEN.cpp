/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline int check(int stack[] , int index, const int size) {
	if(stack[index]>=size) return -1;

	int nowy = index , nowx = stack[index];
	for(int i=0; i<index; i++) {
		int y = i , x = stack[i];
		if(y==nowy || x==nowx) return -1;
		y = (y<nowy) ? nowy-y : y-nowy;
		x = (x<nowx) ? nowx-x : x-nowx;
		if(y==x) return -1;
	}

	return 0;
}

inline int next(int stack[ ] , int index , const int size) {
	for(int i=index; i>=0;i--) {
		for(int j=stack[i]; j<size; j++) {
			if(check(stack , i , size)==0) return i;
			else stack[i]++;
		}
		if(i>0) stack[i-1]++;
	}

	return -1;
}

int cal_main(const int size) {
	if(size==1) return 1;

	int cnt = 0;
	//------------------------------------------------
	int stack[10]={0};
	int index=0;

	while(index>=0) {
		if(index==size-1) {
			cnt++;
			index--;
			stack[index]++;
			index = next(stack , index , size);
			continue;
		}

		stack[++index] = 0;
		index = next(stack , index , size);
	}

	return cnt;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("N_QUEEN.txt" , "r" , stdin);
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