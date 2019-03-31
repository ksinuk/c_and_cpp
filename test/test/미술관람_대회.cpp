/*

#define FREOPEN
#include <iostream>

struct Point {
	int y , x;
};

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

inline int paint(int y , int x , int table[ ][60] , int size , int color) {
	Point stack[3605];
	stack[0] ={y,x};
	int index=1;
	int dy[4] = {0,0,1,-1};
	int dx[4] = {1,-1,0,0};

	while(index>0) {
		Point now = stack[--index];
		table[now.y][now.x] = 0;

		for(int i=0; i<4; i++) {
			Point next ={now.y+dy[i] , now.x+dx[i]};
			if(next.x<0 || next.y<0 || next.x>=size || next.y>=size) continue;
			if(table[next.y][next.x]==color) stack[index++] = next;
		}
	}
	return 0;
}


int cal_main(const int size) {
	int table[60][60] ={0};
	for(int y=0; y<size; y++) {
		for(int x=0; x<size; x++) {
			char temp='-';
			while(!(temp=='R' || temp=='G' || temp=='B'))
				scanf("%c" , &temp);
			if(temp=='R') table[y][x] = 1;
			else if(temp=='G') table[y][x] = 2;
			else table[y][x] = 3;
		}
	}
	int cnt_b=0;

	for(int y=0; y<size; y++) {
		for(int x=0; x<size; x++) {
			if(table[y][x]==3) {
				cnt_b++;
				paint(y , x , table , size , 3);
			}
		}
	}
	//----------------------------------------------------
	int cnt_rg=0;
	int rg[60][60];
	for(int y=0; y<size; y++)
		for(int x=0; x<size; x++)
			if(table[y][x]) rg[y][x] = 1;
			else rg[y][x] = 0;

	for(int y=0; y<size; y++) {
		for(int x=0; x<size; x++) {
			if(rg[y][x]!=0) {
				paint(y , x , rg , size , 1);
				cnt_rg++;
			}
		}
	}
	//----------------------------------------------------
	int cnt_rgb=0;
	for(int y=0; y<size; y++) {
		for(int x=0; x<size; x++) {
			if(table[y][x]!=0) {
				cnt_rgb++;
				paint(y , x , table , size , table[y][x]);
			}
		}
	}
	printf("%d %d\n" , cnt_b+cnt_rgb , cnt_b+cnt_rg);

	return 0;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("미술관람_대회.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		cal_main(size);
	}

	return 0;
}


*/