/*
#define FREOPEN
#include <iostream>

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

struct Point {
	int y , x;
};
int map[15][15];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}


int search(int ysize , int xsize , int now , Point red , Point blue , Point goal , int out) {
	if(now==10 || now>=out) return out;

	for(int i = 0; i<4; i++) {
		Point redn = {red.y+dy[i] , red.x+dx[i]};
		Point bluen = {blue.y+dy[i] , blue.x+dx[i]};
		if(map[redn.y][redn.x]==1) redn = {red.y , red.x};
		if(map[bluen.y][bluen.x]==1) bluen = {blue.y , blue.x};

		if(bluen.x==goal.x && bluen.y==goal.y) continue;
		if(bluen.x==redn.x && bluen.y==redn.y) continue;
		if(goal.x==redn.x && goal.y==redn.y) return now+1;

		out = search(ysize , xsize , now+1 , redn , bluen , goal , out);
	}

	return out;
}

int cal_main(int ysize , int xsize) {
	Point red,blue,goal;

	for(int y = 0; y<ysize; y++) {
		char temp[20];
		scanf("%s" , temp);
		for(int x = 0; x<xsize; x++) {
			map[y][x] = 0;
			if(temp[x]=='R') red = {y,x};
			else if(temp[x]=='B') blue = {y,x};
			else if(temp[x]=='#') map[y][x] = 1;
			else if(temp[x]=='H') goal = {y,x};
		}
	}
	//--------------------------------------------
	int now = 0;
	int out = 1<<30;
	out = search(ysize,xsize,now,red,blue,goal,out);
	//----------------------------------------------
	if(out>10) return -1;
	return out;
}


int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("구슬_집어넣기_게임.txt" , "r" , stdin);
	//scanf("%d" , &N);
#endif // FREOPEN
	scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int ysize , xsize;
		scanf("%d %d" , &ysize , &xsize);
		int out = cal_main(ysize , xsize);
		printf("%d\n" , out);
	}

	return 0;
}

*/