/*
#define FREOPEN
//#define DEBUG
#include <iostream>

struct Point {
	int x , y , dist;
};

inline void copy_point(Point &from , Point &to) {
	to.y = from.y;
	to.x = from.x;
	to.dist = from.dist;
}

bool equal_point(Point a , Point b) {
	if(a.x==b.x && a.y==b.y) return true;
	return false;
}

int cal_main(int xsize,int ysize) {
	Point start = {0,0,1}; scanf("%d" , &(start.x)); scanf("%d" , &(start.y));
	Point end = {0,0,1}; scanf("%d" , &(end.x)); scanf("%d" , &(end.y));

	int map[102][102];
	const int block = 1;
	for(int y = 0; y<ysize+2; y++) {
		map[y][0] = block;
		map[y][xsize+1] = block;
	}
	for(int x = 0; x<xsize+2; x++) {
		map[0][x] = block;
		map[ysize+1][x] = block;
	}

	for(int y = 1; y<=ysize; y++) {
		for(int x = 1; x<=xsize; x++) {
			char temp = '-';
			while(temp!='0' && temp!='1') scanf("%c" , &temp);
			map[y][x] = (temp-'0')*block;
		}
	}

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	Point stack[10000];
	copy_point(start , stack[0]);
	Point now;
	int front = 0 , last=1;

	while(1) {
		copy_point(stack[front++] , now);

		map[now.y][now.x] = now.dist;

		if(equal_point(end , now)) {
			return now.dist-1;
		}

		int arrows[4] = {0} , cnt_arrow = 0;
		for(int i = 0; i<4; i++)
			if(map[now.y+dy[i]][now.x+dx[i]]<=0) {
				arrows[cnt_arrow++] = i;
			}

		if(cnt_arrow==0) {
			if(front>=last) return -1;
			continue;
		}

		Point pre; copy_point(now , pre);

		for(int i = 0; i<cnt_arrow; i++) {
			copy_point(pre,now);
			int arrow = arrows[i];

			while(1) {
				now.y += dy[arrow];
				now.x += dx[arrow];
				now.dist++;

				if(equal_point(end , now) || map[now.y][now.x]<0) {
					int ok = 1;
					for(int j = front; j<last; j++) {
						if(equal_point(stack[j] , now)) {
							if(stack[j].dist> now.dist) stack[j].dist = now.dist;
							ok = 0;
							break;
						}
					}
					if(ok) copy_point(now , stack[last++]);
					break;
				}

				arrow = 0;
				int cnt = 0;
				for(int i = 0; i<4; i++)
					if(map[now.y+dy[i]][now.x+dx[i]]<=0) {
						arrow = i;
						cnt++;
					}
				if(cnt==0) {
					map[now.y][now.x] = now.dist;
					break;
				}
				else if(cnt>1) {
					int ok = 1;
					map[now.y][now.x] = -1;
					for(int j = front; j<last; j++) {
						if(equal_point(stack[j] , now)) {
							if(stack[j].dist>now.dist) stack[j].dist = now.dist;
							ok = 0;
							break;
						}
					}
					if(ok) copy_point(now , stack[last++]);
					break;
				}

				map[now.y][now.x] = now.dist;
			}
		}

		int min_i = front;
		if (front >= last) {
			return -1;
		}
		int min = stack[front].dist;
		for(int i = front+1; i<last; i++) {
			if(min> stack[i].dist) {
				min = stack[i].dist;
				min_i = i;
			}
		}

		Point temp;
		copy_point(stack[min_i] , temp);
		copy_point(stack[front],stack[min_i]);
		copy_point(temp,stack[front]);
	}

	return -1;
}

int main()
{
#ifdef FREOPEN
	freopen("¹Ì·Î.txt" , "r" , stdin);
#endif // FREOPEN
	int N = 4;
	for(int testcase = 0; testcase<N; testcase++) {
		int xsize; scanf("%d" , &xsize);
		int ysize; scanf("%d" , &ysize);
		printf("%d\n" , cal_main(xsize,ysize));
	}

	return 0;
}
*/