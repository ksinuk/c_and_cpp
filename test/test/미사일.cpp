/*

#define FREOPEN
#include <iostream>

struct Ship {
	int y , x , hp;
};


inline void swap(Ship &a , Ship &b) {
	Ship temp = a;
	a = b;
	b = temp;
}

inline int cal_range(Ship a , Ship b) {
	int x = a.x-b.x , y = a.y-b.y;
	x = (x<0) ? -x : x;
	y = (y<0) ? -y : y;
	return x+y;
}

int cal_main(int size) {
	Ship ships[16];
	for(int i=0; i<size; i++) {
		scanf("%d %d %d" , &ships[i].y , &ships[i].x , &ships[i].hp);
	}
	int num , fire , range;
	scanf("%d %d %d" , &num , &fire , &range);
	//-----------------------------------------------------------
	int table[16][16]={0};
	for(int from=0; from<size; from++) {
		for(int to=0; to<size; to++) {
			if(cal_range(ships[from] , ships[to])<=range) table[from][to] = 1;
			else table[from][to] = 0;
		}
	}
	//------------------------------------------------------------
	int arr[4] ={0};
	int index = 0;
	Ship history[5][16];
	for(int i=0; i<size; i++) history[0][i] = ships[i];
	int min=100;

	while(index>=0) {
		if(index==num) {
			int out=size;
			for(int i=0; i<size; i++) {
				if(history[num][i].hp<=0) out--;
			}
			min = (min<out) ? min : out;

			index--;
			arr[index]++;
			while(index>=0 && arr[index]==size) {
				arr[index--] = 0;
				if(index>=0) arr[index]++;
			}
			continue;
		}

		if(history[index][arr[index]].hp<=0) {
			arr[index]++;
			while(index>=0 && arr[index]==size) {
				arr[index--] = 0;
				if(index>=0) arr[index]++;
			}
		}
		else {
			for(int i=0; i<size; i++) {
				history[index+1][i] = history[index][i];
				if(table[arr[index]][i]) history[index+1][i].hp -= fire;
			}

			index++;
		}
	}
	//------------------------------------------------------

	return min;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("¹Ì»çÀÏ.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN

	for(int i = 0; i<N; i++) {
		int size;
		scanf("%d" , &(size));
		//cal_main(size);
		printf("%d\n" , cal_main(size));
	}

	return 0;
}


*/