#define FREOPEN
//#define DEBUG
#include <iostream>

class Ham {
public:
	int l , w;
	int start , last;
	Ham(int inl = 0 , int inw = 0 , int instart = 0 , int inlast = 0) {
		l = inl , w = inw;
		start = instart , last = inlast;
	}

	bool operator>(Ham a) {
		if(l>=a.l && w>=a.w) return true;
		return false;
	}
	bool operator<(Ham a) {
		if(l<=a.l && w<=a.w) return true;
		return false;
	}
	Ham operator=(Ham a) {
		l = a.l , w = a.w , start = a.start , last = a.last;
		return *this;
	}
};
Ham hams[5000];

inline void swap(Ham &a , Ham &b) {
	Ham temp = a;
	a = b;
	b = temp;
}

int cal_main(int size_in) {
	int size = 0;
	for(int i = 0; i<size_in; i++) {
		int l , w;
		scanf("%d %d" , &l , &w);

		int ok = 1;
		for(int j = 0; j<size; j++) if(hams[j].l==l && hams[j].w==w) { ok = 0; break; }
		if(ok) hams[size++] = Ham(l , w , 0 , size_in-1);
	}
	for(int i = 0; i<size; i++) hams[i].last = size-1;
	for(int i = 0; i<size; i++)
		for(int j = 0; j<size; j++) {
			if(i==j) continue;
			else if(hams[i]<hams[j]) hams[i].last--;
			else if(hams[i]>hams[j]) hams[i].start++;
		}
	for(int i = 1; i<size; i++) {
		for(int j = i; j>0; j--) {
			if(hams[j].start<hams[j-1].start||hams[j].start==hams[j-1].start && hams[j].last<hams[j-1].last) swap(hams[j-1] , hams[j]);
		}
	}

	int cnt = 0;
	for(int i = 0; i<size; i++) {
		int now = i;
		if(hams[now].start<0) continue;
		cnt++;

		for(int j = now+1; j<size; j++) {
			if(hams[j]>hams[now]) {
				hams[j].start = -1;
				now = j;
			}
		}
	}

	return cnt;
}

int main(void) {
	int N = 1;
#ifdef FREOPEN
	freopen("소시지_공장.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &size);
		int out = cal_main(size);

		printf("%d\n" , out);
#ifdef FREOPEN
		printf("-----------------------\n");
#endif // FREOPEN
	}

	return 0;
}