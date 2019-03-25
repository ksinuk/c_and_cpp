/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
#ifdef FREOPEN
	freopen("input.txt" , "r" , stdin);
#endif // FREOPEN

	int size; scanf("%d" , &size);
	int arr[5000];
	for(int i = 0; i<size; i++) scanf("%d" , arr+i);

	for(int i = 1; i<size; i++) {
		for(int j = i-1; j>=0; j--) {
			if(arr[j]<arr[j+1]) swap(arr[j+1] , arr[j]);
			else break;
		}
	}

	int out = 0;
	for(; size>1; size--) {
		arr[size-2] += arr[size-1];
		out += arr[size-2];
		for(int i = size-3; i>=0; i--) {
			if(arr[i]<arr[i+1]) swap(arr[i] , arr[i+1]);
			else break;
		}

	}

	printf("%d " , out);
}
*/

