/*
#define FREOPEN
#include <iostream>

int search(int arr[],int size,int x) {
	int start = 0 , end = size-1;
	int mid;

	while(start<=end) {
		mid = (start+end)/2;
		if(arr[mid]==x) return mid;
		else if(arr[mid]>x) end = mid-1;
		else start = mid+1;
	}
	return -1;
}

int main()
{
#ifdef FREOPEN
	freopen("숫자 카운팅.txt" , "r" , stdin);
#endif // FREOPEN

	int size; scanf("%d" , &size);
	int arr[200000];
	for(int i = 0; i<size; i++) scanf("%d" , arr+i);
	int find_size; scanf("%d" , &find_size);

	for(int i = 0; i<find_size; i++) {
		int x; scanf("%d" , &x);
		int start = search(arr , size , x);
		int out = -1;

		for(int j = start; j<size; j++) {
			if(arr[j]==x) out++;
			else break;
		}
		for(int j = start; j>=0; j--) {
			if(arr[j]==x) out++;
			else break;
		}

		printf("%d " , out);
	}


	return 0;
}
*/