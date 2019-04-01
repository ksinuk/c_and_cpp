#define FREOPEN
#include <iostream>

int cal_main(int gold, int size) {
	int table[31][7] ={0};
	for(int i=0; i<gold; i++) {
		int pay; scanf("%d" , &pay);
		for(int j=0; j<size; j++) {
			scanf("%d" , &table[pay][j]);
		}
	}
	//-------------------------------
	int arr[7]={0};
	int index=0;
	int max=0;
	int sum[8]={0};
	int out[8]={0};

	while(index>=0) {
		if(index==size-1) {
			arr[index] = gold-sum[index];
			out[index+1] = table[arr[index]][index] + out[index];
			max = (max>out[index+1]) ? max : out[index+1];

			arr[index--] = 0;
			arr[index]++;
			while(index>=0 && arr[index]>=gold-sum[index]) {
				arr[index--] = 0;
				if(index>=0) arr[index]++;
			}
			continue;
		}
		sum[index+1] = sum[index] + arr[index];
		out[index+1] = table[arr[index]][index]+out[index];
		index++;

	}

	return max;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("기업투자.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	
	for(int i = 0; i<N; i++) {
		int gold,company;
		scanf("%d %d" , &gold, &company);
		//cal_main(size);
		printf("%d\n" , cal_main(gold,company));
	}

	return 0;
}
