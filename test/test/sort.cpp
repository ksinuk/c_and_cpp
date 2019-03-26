/*
inline void marge_sort(int arr[] , int size) {
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
*/

/*
inline void swap(int &a , int &b) {
	int temp=a;
	a = b;
	b = temp;
}

void quick_sort(int arr[] , int size) {
	if(size<=1) return;
	if(size==2) {
		if(arr[0]>arr[1]) swap(arr[0] , arr[1]);
		return;
	}

	int front = 1 , end = size-1;
	swap(arr[(front+end)/2] , arr[0]);
	int pv = arr[0];

	while(front<=end) {
		while(arr[front]<=pv && front<=size-1) front++;
		while(arr[end]>=pv && end>=1) end--;
		if(front<end) swap(arr[front] , arr[end]);
	}

	swap(arr[end] , arr[0]);

	sort(arr , end);
	sort(arr+end+1 , size-end-1);
}

*/

