#define VS
#include <iostream>

int table[12][12] = {0};
int size_table = 0;

struct Point {
	int x, y;
};
void copypoint(Point &from , Point &to) {
	to.y = from.y;
	to.x = from.x;
}

int search(int start , int end , int arr[] , int size) {
	if(size==0) return table[start][end];
	else if(size==1) return table[start][arr[0]]+table[arr[0]][end];

	int min = 1<<29;

	for(int first=0; first<size; first++) {
		int df = table[start][arr[first]];
		for(int last = 0; last<size; last++) {
			if(first==last) continue;
			int dl = table[end][arr[last]];
			if(df+dl>min) continue;

			int *new_arr = new int[size-2];
			int outsize = 0;
			for(int i = 0; i<size; i++) {
				if(i!=first&&i!=last) new_arr[outsize++] = arr[i];
			}
				
			int mid = search(arr[first] , arr[last] , new_arr , size-2);
			mid += df+dl;
			min = (mid<min) ? mid : min;

			delete[] new_arr;
		}
	}

	return min;
}

int cal(int size) {
	Point start = { 0,0 };
	scanf("%d", &(start.x)); scanf("%d", &(start.y));
	Point home = { 0,0 };
	scanf("%d", &(home.x)); scanf("%d", &(home.y));

	Point *node = new Point[size+2];
	for (int i = 1; i < size+1; i++) {
		scanf("%d", &(node[i].x));
		scanf("%d", &(node[i].y));
	}
	copypoint(start , node[0]);
	copypoint(home , node[size+1]);
	size += 2;

	for(int i = 0; i<size; i++) {
		for(int j = 0; j<size; j++) {
			table[i][j] = abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y);
		}
	}

	int arr[12] = {0};
	for(int i = 0; i<size-2; i++) arr[i] = i+1;
	int out = search(0 , size-1 , arr , size-2);

	delete[] node;
	return out;
}


int main()
{
#ifdef VS
	freopen("input.txt", "r", stdin);
#endif // VS
	int T; scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++) {
		int size; scanf("%d", &size);
		printf("#%d %d\n", testcase, cal(size));
	}

	return 0;
}
