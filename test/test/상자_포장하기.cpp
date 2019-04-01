/*
#define FREOPEN
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int search(int boxes[] , int size , int l , int r , int maxout , int sum , int visit[] , int pre_r , int pre_l) {
	int box_l[20] = {0} , l_out = 0;
	for(int i = 0; i<=l; i++) {
		if(visit[i]!=0||boxes[i]>=pre_l) continue;
		box_l[i] = boxes[i];
		int max = 0;
		for(int j = 0; j<i; j++)
			if(max<box_l[j]&&boxes[j]<boxes[i]) max = box_l[j];
		box_l[i] += max;
		if(l_out<box_l[i]) l_out = box_l[i];
	}

	int box_r[20] = {0} , r_out = 0;
	for(int i = size-1; i>=r; i--) {
		if(visit[i]!=0||boxes[i]>=pre_r) continue;
		box_r[i] = boxes[i];
		int max = 0;
		for(int j = i+1; j<size; j++)
			if(max<box_r[j]&&boxes[j]<boxes[i]) max = box_r[j];
		box_r[i] += max;
		if(r_out<box_r[i]) r_out = box_r[i];
	}

	int sum_temp = sum+r_out+l_out;
	if(l<r) return (maxout>sum_temp) ? maxout : sum_temp;
	if(sum_temp<=maxout) return maxout;
	//------------------------------------------------------
	if(size!=r&&visit[r]==0&&boxes[r]<pre_r) {
		visit[r] = 1;
		maxout = search(boxes , size , l , r+1 , maxout , sum+boxes[r] , visit , boxes[r] , pre_l);
		visit[r] = 0;
	}
	if(sum_temp<=maxout) return maxout;

	if(l!=-1&&visit[l]==0&&boxes[l]<pre_l) {
		visit[l] = 1;
		maxout = search(boxes , size , l-1 , r , maxout , sum+boxes[l] , visit , pre_r , boxes[l]);
		visit[l] = 0;
	}
	if(sum_temp<=maxout) return maxout;

	if(size!=r) maxout = search(boxes , size , l , r+1 , maxout , sum , visit , pre_r , pre_l);
	if(sum_temp<=maxout) return maxout;

	if(0<=l) maxout = search(boxes , size , l-1 , r , maxout , sum , visit , pre_r , pre_l);
	if(sum_temp<=maxout) return maxout;

	return maxout;
}

int cal_main(const int size) {
	int boxes[20];
	for(int i = 0; i<size; i++) {
		scanf("%d" , &boxes[i]);
	}
	//---------------------------------
	int maxout = 0;

	for(int i = 0; i<size; i++) {
			if(boxes[i]>maxout) maxout = boxes[i];
		}
	//---------------------------------
	int start_l = size-1;
	int start_r = 0;
	//----------------------------------------
	int visit[20] = {0};
	maxout = search(boxes , size , start_l , start_r , maxout , 0 , visit , maxout+1 , maxout+1);

	return maxout;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("상자_포장하기.txt" , "r" , stdin);
#endif // FREOPEN
	scanf("%d" , &N);
	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		//cal_main(size);
		printf("%d\n" , cal_main(size));
	}

	return 0;
}



*/