#define FREOPEN
#include <iostream>

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

struct Robot {
	int y , x , arrow;
};
Robot qu[40005];
int map[100][100];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int ysize , int xsize) {
	for(int y = 0; y<ysize; y++) {
		for(int x = 0; x<xsize; x++) {
			scanf("%d" , &map[y][x]);
		}
	}
	Robot start; scanf("%d %d %d" , &start.y , &start.x , &start.arrow);
	Robot last; scanf("%d %d %d" , &last.y , &last.x , &last.arrow);

	qu[0] = start;
	map[start.y][start.x] = 1;
	int front=0 , end=1;

	while(end-front>0) {
		Robot now = qu[front++];

		for(int arrow = 0; arrow<4; arrow++) {
			Robot next = {now.y+dy[arrow] , now.x+dx[arrow]};
			if(next.x<0||next.y<0||next.y>=ysize||next.x>=xsize) continue;
			if(map[next.y][next.x]!=0) continue;

			int commend = (arrow > now.arrow) ? arrow-now.arrow : now.arrow-arrow;
			if(commend==3) commend = 1;

			next.arrow = arrow;

		}
	}


	return 0;
}


int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("로봇.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	//scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int ysize , xsize;
		scanf("%d %d" , &ysize , &xsize);
		cal_main(ysize , xsize);
	}

	return 0;
}