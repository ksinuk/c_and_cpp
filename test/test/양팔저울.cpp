/*
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline void sort(int arr[] , int size) {
	for(int i = 1; i<size; i++) {
		for(int j = i; j>0; j--) {
			if(arr[j]<arr[j-1]) swap(arr[j] , arr[j-1]);
			else break;
		}
	}
}

int search(int x , int chu[] , int left , int right , int size , int now) {
	if(size==now) {
		if(left+x==right) return 1;
		else return 0;
	}

	int temp = search(x , chu , left+chu[now] , right , size , now+1);
	if(temp) return 1;
	temp = search(x , chu , left , right+chu[now] , size , now+1);
	if(temp) return 1;
	temp = search(x , chu , left , right , size , now+1);
	if(temp) return 1;

	return 0;
}

int cal_main(const int size) {
	int chu[12];
	for(int i = 0; i<size; i++) {
		scanf("%d" , &chu[i]);
	}
	//---------------------------------
	int num; scanf("%d" , &num);
	int x[12];
	for(int i = 0; i<num; i++) {
		scanf("%d" , &x[i]);
	}
	//---------------------------------
	for(int i = 0; i<num; i++) {
		if(search(x[i] , chu , 0 , 0 , size , 0)) printf("Y ");
		else printf("N ");
	}
	printf("\n");

	return 0;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("¾çÆÈÀú¿ï.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		cal_main(size);
		//printf("%d\n", cal_main(size));
	}

	return 0;
}


*/

