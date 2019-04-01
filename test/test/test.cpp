#define FREOPEN
#include <iostream>

struct Point {
	int y , x;
};


inline void swap(Point &a , Point &b) {
	Point temp = a;
	a = b;
	b = temp;
}

inline int cal_range(Point a , Point b) {
	int x = a.x-b.x , y = a.y-b.y;
	x = (x<0) ? -x : x;
	y = (y<0) ? -y : y;
	return x+y;
}

int cal_main(int size, int cut) {
	Point houses[40] = {0};
	int h_i = 0;
	Point chikens[13] = {0};
	int c_i = 0;

	for(int i = 0; i<size; i++) {
		for(int j = 0; j<size; j++) {
			int temp;
			scanf("%d" , &temp);
			if(temp==1) houses[h_i++] = {i,j};
			else if(temp==2) chikens[c_i++] = {i,j};
		}
	}
	//--------------------------------------
	int table[40][13] = {0};
	for(int h = 0; h<h_i; h++) {
		for(int c = 0; c<c_i; c++) {
			table[h][c] = cal_range(houses[h] , chikens[c]);
		}
	}

	//----------------------------------------
	int arr[12] = {0};
	int idx = 0;

	int minout = 2*size*2*size+1;
	while(idx>=0) {
		if(idx==cut-1) {
			int out = 0;
			for(int h = 0; h<h_i; h++) {
				int temp = minout;
				for(int i = 0; i<cut; i++) {
					if(table[h][arr[i]]<temp) temp = table[h][arr[i]];
				}
				out += temp;
			}

			minout = (minout<out) ? minout : out;

			arr[idx]++;
			while(idx>=0 && arr[idx]==c_i+idx-cut+1) {
				idx--;
				if(idx<0) break;
				arr[idx]++;
			}
			continue;
		}

		idx++;
		arr[idx] = arr[idx-1]+1;
	}

	return minout;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("치킨배달2.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	
	for(int i = 0; i<N; i++) {
		int size,cut;
		scanf("%d %d" , &(size), &cut);
		//cal_main(size);
		printf("%d\n" , cal_main(size,cut));
	}

	return 0;
}
