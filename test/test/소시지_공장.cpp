/*
#define FREOPEN
//#define DEBUG
#include <iostream>

class Ham {
public:
	int l , w;
	int check;
	Ham(int inl = 0 , int inw = 0 , int incheck = 0) {
		l = inl , w = inw;
		check = incheck;
	}

	Ham operator=(Ham a) {
		l = a.l , w = a.w , check = a.check;
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
		if(ok) hams[size++] = Ham(l , w);
	}
	for(int i = 1; i<size; i++) {
		for(int j = i; j>0; j--) {
			if(hams[j].l<hams[j-1].l) swap(hams[j-1] , hams[j]);
		}
	}

	int cnt = 0;
	for(int i = 0; i<size; i++) {
		int now = i;
		if(hams[now].check<0) continue;
		cnt++;

		for(int j = now+1; j<size; j++) {
			if(hams[j].w >= hams[now].w && hams[j].check==0) {
				hams[j].check = -1;
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
		//printf("-----------------------\n");
#endif // FREOPEN
	}

	return 0;
}

*/

