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

inline int decoding(char input) {
	switch(input) {
	case '0':
		return 0;
	case '1':
		return 4+1;
	case '2':
		return 8+2;
	case '3':
		return 8+1;
	case '4':
		return 8+4;
	case '5':
		return 4+2;
	case '6':
		return 2+1;
	case '7':
		return 8+2+1;
	case '8':
		return 8+4+1;
	case '9':
		return 8+4+2;
	case 'A':
		return 4+2+1;
	case 'B':
		return 8+4+2+1;
	default:
		break;
	}

	return 0;
}

int cal_main(const int size, const Point start) {
	int table[10][10] ={0};
	for(int y=0; y<size; y++) {
		for(int x=0; x<size; x++) {
			char temp='-';
			while(!(temp>='0' && temp<='9' || temp=='A' || temp=='B'))
				scanf("%c" , &temp);
			table[y][x] = decoding(temp);
		}
	}

	Point stack[105];
	stack[0] = start;
	int index=1;
	int dy[4] ={0,-1,0,1};
	int dx[4] ={1,0,-1,0};

	while(index>0) {
		Point now = stack[--index];
		int from = table[now.y][now.x];

		for(int i=0; i<4; i++) {
			if( !(from&(1<<i)) ) continue;
			Point next ={now.y+dy[i],now.x+dx[i]};
			if(next.x<0 || next.y<0 || next.x>=size || next.y>=size) continue;

			int to = table[next.y][next.x];
			to =(to&3)*4 +(to>>2);

			if((to&(1<<i))) {
				stack[index++] = next;
			}
		}
		table[now.y][now.x]=0;
	}

	int cnt=0;
	for(int y=0; y<size; y++)
		for(int x=0; x<size; x++) {
			if(table[y][x]!=0) cnt++;
		}

	return cnt;
}

int main( ) {
	int N = 1;
#ifdef FREOPEN
	freopen("파이프_제거.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int size;
		Point start ={0,0};
		scanf("%d %d %d" , &(size) , &(start.x) , &(start.y));
		printf("%d\n" , cal_main(size , start));
	}

	return 0;
}



*/