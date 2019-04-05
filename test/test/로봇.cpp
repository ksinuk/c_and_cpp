/*
#define FREOPEN
#include <iostream>

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

struct Robot {
	int y , x , arrow;
};
Robot qu[40005];
int map[4][100][100];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int ysize , int xsize) {
	for(int y = 0; y<ysize; y++) {
		for(int x = 0; x<xsize; x++) {
			scanf("%d" , &map[0][y][x]);
			if(map[0][y][x]==1) {
				map[0][y][x] = -1;
				map[1][y][x] = -1;
				map[2][y][x] = -1;
				map[3][y][x] = -1;
			}
			else {
				map[0][y][x] = 0;
				map[1][y][x] = 0;
				map[2][y][x] = 0;
				map[3][y][x] = 0;
			}
		}
	}
	Robot start; scanf("%d %d %d" , &start.y , &start.x , &start.arrow);
	Robot last; scanf("%d %d %d" , &last.y , &last.x , &last.arrow);
	start.y -= 1; start.x -= 1;
	if(start.arrow==1)start.arrow = 0;
	else if(start.arrow==2)start.arrow = 2;
	else if(start.arrow==3)start.arrow = 3;
	else if(start.arrow==4)start.arrow = 1;
	last.y -= 1; last.x -= 1;
	if(last.arrow==1)last.arrow = 0;
	else if(last.arrow==2)last.arrow = 2;
	else if(last.arrow==3)last.arrow = 3;
	else if(last.arrow==4)last.arrow = 1;

	qu[0] = start;
	map[start.arrow][start.y][start.x] = 1;
	int front=0 , end=1;

	while(end-front>0) {
		Robot now = qu[front++];

		if(now.x==last.x && now.y==last.y && now.arrow==last.arrow) {
			return map[now.arrow][now.y][now.x]-1;
		}
		else {
			for(int dist = 1; dist<=3; dist++) {
				Robot next = {now.y+dy[now.arrow]*dist , now.x+dx[now.arrow]*dist , now.arrow};
				if(next.x<0||next.y<0||next.y>=ysize||next.x>=xsize) break;
				if(map[next.arrow][next.y][next.x]==-1) break;

				int temp = map[now.arrow][now.y][now.x]+1;
				if(map[next.arrow][next.y][next.x]==0) {
					map[next.arrow][next.y][next.x] = temp;
					qu[end++] = next;
				}
			}

			Robot next1 = {now.y , now.x , (now.arrow+1)%4};
			if(map[next1.arrow][next1.y][next1.x]==0) {
				map[next1.arrow][next1.y][next1.x] = map[now.arrow][now.y][now.x]+1;
				qu[end++] = next1;
			}
			next1 = {now.y , now.x , (now.arrow+3)%4};
			if(map[next1.arrow][next1.y][next1.x]==0) {
				map[next1.arrow][next1.y][next1.x] = map[now.arrow][now.y][now.x]+1;
				qu[end++] = next1;
			}
		}

	}


	return 0;
}


int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("·Îº¿.txt" , "r" , stdin);
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