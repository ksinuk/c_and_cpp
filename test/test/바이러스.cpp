/*
#define FREOPEN
#include <iostream>

int cal_main(int size,int num) {
	int table[101][101] = {0};
	for(int i = 0; i<num; i++) {
		int a , b;
		scanf("%d %d" , &a , &b);
		table[a][b] = 1;
		table[b][a] = 1;
	}

	int visit[101] = {0};
	int out = 0;

	int stack[101] = {0};
	stack[0] = 1;
	visit[1] = 1;
	int index = 1;

	while(index>0) {
		int now = stack[--index];

		for(int i = 1; i<=size; i++) {
			if(table[now][i] && visit[i]==0) {
				table[now][i] = 0;
				table[i][now] = 0;

				visit[i] = 1;
				stack[index++] = i;
				out++;
			}
		}
	}

	return out;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("바이러스.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	//scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int size,num;
		scanf("%d %d" , &size , &num);
		//cal_main(size);
		printf("%d\n" , cal_main(size,num));
	}

	return 0;
}


*/