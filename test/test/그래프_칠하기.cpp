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

	int maxs[12] = {0};
	for(int i = 0; i<size; i++) {
		for(int j = 0; j<i; j++) {
			//if(table[i][j])
			{
				maxs[i] = i;
				break;
			}
		}
	}
	//-----------------------------------

	int arr[12] = {0};
	int out[12] = {0};
	int ok = 0;
	int color = 0;
	for(int idx = 0; idx<=size && idx>=0;) {
		if(idx==size) {
			ok = 1;
			colors = color;
			for(int j = 0; j<size; j++) out[j] = arr[j];

			for(int j = 0; j<size; j++) {
				if(arr[j]>=color) {
					idx = j;
					break;
				}
			}
			for(int j = idx+1; j<size; j++) {
				arr[j] = 0;
			}

			while(idx>=0 && (arr[idx]>=colors||arr[idx]>maxs[idx])) {
				arr[idx--] = 0;
				if(idx>=0)arr[idx]++;
			}

			color = 0;
			for(int j = 0; j<idx; j++) {
				if(color<arr[j]) color = arr[j];
			}

			continue;
		}

		for(; arr[idx]<=maxs[idx]; arr[idx]++) {
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

		if(idx>=0 && (arr[idx]>=colors || arr[idx]>maxs[idx])) {
			while(idx>=0 && (arr[idx]>=colors || arr[idx]>maxs[idx])) {
				arr[idx--] = 0;
				if(idx>=0) arr[idx]++;
			}
		}
		else {
			color = (arr[idx]>color) ? arr[idx] : color;
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
	freopen("그래프_칠하기.txt" , "r" , stdin);
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