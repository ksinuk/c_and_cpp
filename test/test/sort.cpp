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