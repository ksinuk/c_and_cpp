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
		char temp;
		scanf("%c" , &temp);
		for(int x = 1; x<=xsize; x++) {
			scanf("%c" , &temp);
			map[y][x] = (temp-'0')*block;
		}
	}

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	Point stack[10000];
	copy_point(start , stack[0]);
	Point now;
	int front = 0 , last=1;
	int dist = 0;

	while(front<last) {
		copy_point(stack[front++] , now);

		map[now.y][now.x] = now.dist;

		if(equal_point(end , now)) {
			return dist-1;
		}
		
		int arrows[4] = {0} , cnt_arrow = 0;
		for(int i = 0; i<4; i++) 
			if(map[now.y+dy[i]][now.x+dx[i]]==0) {
				arrows[cnt_arrow++] = i;
			}
		
		if(cnt_arrow==0) {
			if(front<last) copy_point(stack[front++] , now);
			else return -1;
			dist = map[now.y][now.x];
			continue;
		}

		Point pre; copy_point(now , pre);

		for(int i = 0; i<cnt_arrow; i++) {
			copy_point(pre,now);
			dist = map[now.y][now.x];
			int arrow = arrows[i];

			while(1) {
				now.y += dy[arrow];
				now.x += dx[arrow];

				if(equal_point(end , now)) {
					int ok = 1;
					for(int j = front; j<last; j++) {
						if(equal_point(stack[j] , now)) {
							if(stack[j].dist>dist) stack[j].dist = dist+1;
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
					if(map[now.y+dy[i]][now.x+dx[i]]==0) {
						arrow = i;
						cnt++;
					}
				if(cnt==0) {
					break;
				}
				else if(cnt>1) {
					int ok = 1;
					for(int j = front; j<last; j++) {
						if(equal_point(stack[j] , now)) {
							if(stack[j].dist>dist) stack[j].dist = dist+1;
							ok = 0;
							break;
						}
					}
					if(ok) copy_point(now , stack[last++]);
					break;
				}

				if(map[now.y][now.x]==0||map[now.y][now.x]>dist) map[now.y][now.x] = ++dist;
			}
		}

		int min_i = front;
		if(front==last) return -1;
		int min = map[stack[front].y][stack[front].x];
		for(int i = front+1; i<last; i++) {
			if(min>map[stack[i].y][stack[i].x]) {
				min = map[stack[i].y][stack[i].x];
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
	freopen("미로.txt" , "r" , stdin);
#endif // FREOPEN
	int N = 3;
	for(int testcase = 0; testcase<N; testcase++) {
		int xsize; scanf("%d" , &xsize);
		int ysize; scanf("%d" , &ysize);
		printf("%d\n" , cal_main(xsize,ysize));
	}

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
