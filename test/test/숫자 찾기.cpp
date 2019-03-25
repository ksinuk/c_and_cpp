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
	freopen("숫자 찾기.txt" , "r" , stdin);
#endif // FREOPEN

	int size; scanf("%d" , &size);
	int arr[50000];
	for(int i = 0; i<size; i++) scanf("%d" , arr+i);
	int find_size; scanf("%d" , &find_size);
	int find_table[10000];
	for(int i = 0; i<find_size; i++) scanf("%d" , find_table+i);

	for(int i = 0; i<find_size; i++) {
		printf("%d\n" , search(arr , size , find_table[i])+1);
	}

	return 0;
}*/