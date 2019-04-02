/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int size , int colors) {
	int table[12][12] = {0};
	for(int i = 0; i<size; i++) {
		for(int j = 0; j<i+1; j++) {
			scanf("%d" , &table[j][i]);
			table[i][j] = table[j][i];
		}
	}
	//-----------------------------------

	int arr[12] = {0};
	int out[12] = {0};
	int ok = 0;
	for(int idx = 0; idx<=size && idx>=0;) {
		if(idx==size) {
			ok = 1;
			for(int j = 0; j<size; j++) out[j] = arr[j];
			break;
		}

		for(; arr[idx] <= idx; arr[idx]++) {
			int j = 0;
			for(; j<idx; j++) {
				if(arr[j]==arr[idx] && table[idx][j]) {
					break;
				}
			}
			if(j==idx) {
				break;
			}
		}

		if(idx>=0 && (arr[idx]>=colors || arr[idx]>idx)) {
			while(idx>=0 && (arr[idx]>=colors || arr[idx]>idx)) {
				arr[idx--] = 0;
				if(idx>=0) arr[idx]++;
			}
		}
		else {
			idx++;
		}
	}

	//--------------------------------------------
	if(ok) {
		for(int i = 0; i<size; i++) {
			printf("%d " , out[i]+1);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}


	return 0;
}


int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("�׷���_ĥ�ϱ�.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	//scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int node , color;
		scanf("%d %d" , &node , &color);
		cal_main(node , color);
	}

	return 0;
}

*/