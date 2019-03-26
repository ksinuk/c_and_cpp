/*
#define FREOPEN
#define DEBUG
#include <iostream>


int cal_main(const int size , const int out) {
	int dice[8] = {1};
	int index = 0;

	int sum[8] = {1};
	while(index>=0) {
		if(index==size-2 && sum[index]<out && sum[index]+6>=out) {
			for(int i = 0; i<size-1; i++) printf("%d " , dice[i]);
			printf("%d\n" , out-sum[index]);
		}

		if(sum[index]>=out || index==size-1) {
			dice[index] = 0;
			sum[index--] = 0;
			while(dice[index]>=6 &&index>=0) {
				sum[index--] = 0;
			}
			if(index<0) break;
			dice[index]++;
			sum[index]++;
		}
		else {
			dice[++index] = 1;
			sum[index] = sum[index-1]+1;
		}
	}

	return 0;
}

int main()
{
	int N = 1;
#ifdef FREOPEN
	freopen("주사위_던지기2.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int testcase = 0; testcase<N; testcase++) {
		int num,out; scanf("%d %d" , &num,&out);
		cal_main(num,out);
#ifdef FREOPEN
		printf("---------------\n");
#endif // FREOPEN


	}

	return 0;
}
*/