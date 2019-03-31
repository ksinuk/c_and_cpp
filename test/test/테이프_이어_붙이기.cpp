/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int size) {
	int tape[20] ={0};
	int minout=50000;
	int sum = 0;

	for(int i=0; i<size;i++) scanf("%d" , tape+i);
	for(int i=0; i<size; i++) sum += tape[i];
	//------------------------------------------------

	int arr[10] ={0};
	int index=0;
	while(index>=0) {
		if(index==size/2) {
			int out = 0;
			for(int i=0; i<index; i++) out += tape[arr[i]];
			out = 2*out-sum;
			out = (out<0) ? -out : out;
			minout = (out<minout) ? out : minout;

			index--;
			arr[index]++;
			while(index>=0 && arr[index]>size/2+index) {
				index--;
				if(index<0) break;
				arr[index]++;
				arr[index+1] = arr[index]+1;
			}
			if(index<0) break;
			continue;
		}

		if(index+1 != size/2)arr[index+1] = arr[index]+1;
		index++;
	}

	return minout;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("테이프_이어_붙이기.txt" , "r" , stdin);
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