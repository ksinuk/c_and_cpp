#define MYHOME 1

#include <iostream>
using namespace std;
int nums[1000001][2];
long long muls[1000001];

int mul(int s , int e) {
	long long out1 = 1, out2 = 1;
	for(int i = s; i <= e; i++) {
		if(nums[i][1] == 0 || muls[i] == 0) return 0;
		if(nums[i][0] == nums[i][1]) continue;
		
	}


	if(s == 0) return muls[e];
	if(muls[s-1] == 0) return 0;
	return muls[e] / muls[s-1];
}

int main()
{
#ifdef MYHOME
	freopen("input.txt", "r", stdin);
#endif

	int size, M, K;
	scanf("%d %d %d", &size , &M , &K);
	
	for(int i = 0; i < size; i++) { 
		scanf("%d" , &nums[i][0]); 
		if(i!=0)muls[i] = muls[i-1]*nums[i][0];
		else muls[i] = nums[i][0];
		if(muls[i] == 0) muls[i] = 1;
		nums[i][1] = nums[i][0];
	}
	for(int i = 0; i < M + K; i++) {
		int type , a , b;
		scanf("%d %d %d" , &type , &a , &b);
		if(type == 1) {
			nums[a - 1][1] = b;
		}
		else {
			int y = mul(a-1 , b-1);
			printf("%d\n" , y);
		}
	}




	return 0;
}

