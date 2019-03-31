/*

#define FREOPEN
#include <iostream>

struct Point {
	int y , x;
};
Point qu[10005];

int cal_main(Point knight , Point pown , const Point size) {
	int table[100][100] = {0};
	table[knight.y][knight.x] = 1;

	qu[0] = knight;
	int front=0, end = 1;

	int dx[8] ={1,2,-1,-2, 1, 2,-1,-2};
	int dy[8] ={2,1, 2, 1,-2,-1,-2,-1};



	while(front<end) {
		Point now=qu[front++];

		if(now.x == pown.x && now.y == pown.y) return table[now.y][now.x]-1;

		for(int i=0; i<8; i++) {
			Point next = {now.y+dy[i],now.x+dx[i]};

			if(next.y<0 || next.x<0 || next.y>=size.y || next.x>=size.x) continue;
			if(table[next.y][next.x]!=0) continue;

			table[next.y][next.x] = table[now.y][now.x]+1;
			qu[end++] = next;
		}
	}


	return -1;
}




int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("¿Â±‚.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {
		Point knight={0,0} , pown={0,0} , size={0,0};
		scanf("%d %d" , &(size.y) , &(size.x));
		scanf("%d %d" , &(knight.y) , &(knight.x));
		scanf("%d %d" , &(pown.y) , &(pown.x));
		printf("%d\n" , cal_main(knight , pown , size));
	}

	return 0;
}


*/