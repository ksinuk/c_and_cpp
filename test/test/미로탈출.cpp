/*

#define FREOPEN
#include <iostream>

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

struct Point {
	int y , x , bomb;
};
Point qu[1005];
int map[4][30][30];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int ysize , int xsize) {
	Point start , last;

	for(int y = 0; y<ysize; y++) {
		for(int x = 0; x<xsize; x++) {
			scanf("%d" , &map[3][y][x]);
			int temp = map[3][y][x];
			for(int i = 0; i<4; i++) map[i][y][x] = -temp;

			if(map[3][y][x]==-3) start = {y,x,3};
			else if(map[3][y][x]==-4) last = {y,x,-1};
		}
	}
	//--------------------------------------------
	int front=0 , end=1;
	qu[0] = start;
	map[start.bomb][start.y][start.x] = 1;

	while(front<end) {
		Point now = qu[front++];
		int dist = map[now.bomb][now.y][now.x];

		if(now.x==last.x && now.y==last.y) {
			return map[now.bomb][now.y][now.x]-1;
		}

		for(int i = 0; i<4; i++) {
			Point next = {now.y+dy[i] , now.x+dx[i] , now.bomb};
			if(map[next.bomb][next.y][next.x]==-1) continue;
			if(map[next.bomb][next.y][next.x]==-2) {
				if(next.bomb==0) continue;
				next.bomb--;
			}
			if(map[next.bomb][next.y][next.x]<=0) {
				map[next.bomb][next.y][next.x] = dist+1;
				qu[end++] = next;
			}

		}
	}


	//----------------------------------------------
	return -1;
}


int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("¹Ì·ÎÅ»Ãâ.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	//scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int ysize , xsize;
		scanf("%d %d" , &ysize , &xsize);
		int out = cal_main(ysize , xsize);
		printf("%d\n" , out);
	}

	return 0;
}
*/