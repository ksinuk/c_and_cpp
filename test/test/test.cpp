#define FREOPEN
#include <iostream>

struct Point {
	int y , x;
};

int cal_main(Point knight , Point pown , const Point size) {
	int table[100][100] = {0};
	Point qu[10005];
	int front=0, end = 0;





	return 0;
}




int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("장기.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {
		Point knight , pown , size;
		scanf("%d %d" , &(size.y) , &(size.x));
		scanf("%d %d" , &(knight.y) , &(knight.x));
		scanf("%d %d" , &(pown.y) , &(pown.x));
		printf("%d\n" , cal_main(knight , pown , size));
	}

	return 0;
}
