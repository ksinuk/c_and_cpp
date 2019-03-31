/*
#define FREOPEN
#include <iostream>

struct Point {
	int z , y , x;
};

Point qu[1000005];
int apples[100][100][100];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(const int xsize, const int ysize, const int zsize) {
	int front=0 , end=0;

	for(int z=0; z<zsize; z++)
		for(int y=0; y<ysize; y++)
			for(int x=0; x<xsize; x++) {
				scanf("%d" , &apples[z][y][x]);
				if(apples[z][y][x]==1) {
					Point out ={z,y,x};
					qu[end++] = out;
				}
			}
	//------------------------------------------------

	int out =1;
	int dx[6] = {1 , -1 , 0 ,  0 , 0 ,  0};
	int dy[6] = {0 ,  0 , 1 , -1 , 0 ,  0};
	int dz[6] = {0 ,  0 , 0 ,  0 , 1 , -1};
	while(front<end) {
		Point now = qu[front++];

		for(int i=0; i<6; i++) {
			Point next ={now.z+dz[i],now.y+dy[i],now.x+dx[i]};
			if(next.z<0 || next.z>=zsize) continue;
			if(next.y<0 || next.y>=ysize) continue;
			if(next.x<0 || next.x>=xsize) continue;
			if(apples[next.z][next.y][next.x]==0){
				int temp = apples[next.z][next.y][next.x] = apples[now.z][now.y][now.x]+1;
				if(temp>out) out = temp;
				qu[end++] = next;
			}
		}
	}

	for(int z=0; z<zsize; z++)
		for(int y=0; y<ysize; y++)
			for(int x=0; x<xsize; x++) {
				if(apples[z][y][x]==0) return -1;
			}

	return out-1;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("Åä¸¶Åä.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int xsize,ysize,zsize;
		scanf("%d %d %d" , &(xsize) , &(ysize) , &(zsize));
		printf("%d\n" , cal_main(xsize , ysize , zsize));
	}

	return 0;
}



*/