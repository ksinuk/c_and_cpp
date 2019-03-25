/*
#define FREOPEN
//#define DEBUG
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline void sort(int arr[] , int size) {
	int step = 1;
	int now = 0;

	while(step<size) {
		int *qu = new int[step*2];

		int index = 0 , a = now , b = now+step;
		int acut = a+step , bcut = (b+step<=size) ? b+step : size;

		while(a<acut && b<bcut) {
			if(arr[a]<arr[b]) qu[index++] = arr[a++];
			else qu[index++] = arr[b++];
		}

		while(a<acut) qu[index++] = arr[a++];
		while(b<bcut) qu[index++] = arr[b++];

		for(int i = 0; i<index; i++) {
			arr[now+i] = qu[i];
		}

		delete[] qu;

		now += step*2;
		if(now+step>=size) {
			now = 0;
			step *= 2;
		}
	}
}

inline int search(int arr[] , int size , int x , int f_or_e = -1) {
	if(size<=0) return -1;
	if(x<arr[0]&&f_or_e==0) return 0;
	if(x<arr[0]) return -1;
	if(arr[size-1]<x && f_or_e==1) return size-1;
	if(arr[size-1]<x) return -1;

	int start = 0 , end = size-1 , mid;

	while(start<=end) {
		mid = (start+end)/2;
		if(arr[mid]==x) return mid;
		if(arr[mid]<x) start = mid;
		else end = mid;

		if(start+1==end) break;
	}
	if(arr[start]==x) return start;
	if(arr[end]==x) return end;

	if(f_or_e) return start;
	else return end;

}


int main()
{
#ifdef FREOPEN
	freopen("µµ¾à.txt" , "r" , stdin);
#endif // FREOPEN

	int size; scanf("%d" , &size);
	int arr[200000];
	for(int i = 0; i<size; i++) scanf("%d" , arr+i);
	sort(arr , size);

	int out = 0;
	for(int start = 0; start<size-2; start++) {
		for(int mid = start+1; mid<size-1; mid++) {
			int d = arr[mid]-arr[start];
			int end_front = search(arr , size , arr[mid]+d , 0);
			int end_end = search(arr , size , arr[mid]+2*d , 1);
			if(end_front==-1||end_end==-1) continue;
			out += end_end-end_front+1;
		}
	}

	printf("%d" , out);

	return 0;
}
*/


