/*
#include <iostream>

int arr[10];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

bool dfs(int arr[] ,int size , int out , int sum , int now) {
	if(now==size) {
		if(out==sum) return true;
		else return false;
	}

	bool result = dfs(arr , size , out , sum+arr[now] , now+1);
	if(result) return true;
	result = dfs(arr , size , out , sum , now+1);
	if(result) return true;
	return false;
}

bool cal_main(int size , int out) {
	for(int i = 0; i<size; i++) scanf("%d" , &arr[i]);

	return dfs(arr,size , out , 0 , 0);
}


int main(void){
#ifdef FREOPEN
	freopen("´õÇÏ±â.txt" , "r" , stdin);
#endif // FREOPEN
	int N; scanf("%d" , &N);
	for(int i = 0; i<N; i++) {
		int size , out;
		scanf("%d %d" , &size , &out);
		if(cal_main(size , out)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

*/