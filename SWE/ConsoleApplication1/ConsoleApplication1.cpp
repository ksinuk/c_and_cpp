#include <iostream>
using namespace std;

int cal_main() {
	int size_y , size_x;
	scanf("%d %d" , &size_y , &size_x);

	char map[20][21] = {0};
	for(int y=0; y<size_y; y++){
		scanf("%s" , map[y]);
	}

	int visit[30] = {0};
	int stack[405][3] = {0};
	int history[20][21]={0};
	int index = 0;
	int out = 0;

	while(index>=0){
		int y = stack[index][0] , x = stack[index][1] , cnt = stack[index][2];
		int c = map[y][x] - 'A';
		visit[c] = 1;
		int first_d = history[y][x];

		int dy[4] = {0,0,1,-1};
		int dx[4] = {1,-1,0,0};
		int ok = 0;
		for(int d=first_d; d<4; d++){
			history[y][x]++;

			int yy = y+dy[d];
			int xx = x+dx[d];
			if(yy<0 || xx<0 || yy>=size_y || xx>=size_x)continue;
			
			int next = map[yy][xx]-'A';
			if(visit[next]) continue;

			ok = 1;

			stack[++index][0] = yy;
			stack[index][1] = xx;
			stack[index][2] = cnt+1;

			break;
		}

		if(ok==0) { 
			out = (out>cnt) ? out : cnt;
			visit[c] = 0;
			history[y][x] = 0;
			index--;
		}
	}
	

	return out+1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int cnt = 0;
	scanf("%d", &cnt);

	for (int i = 1; i <= cnt; i++) {
		int out = cal_main();
		printf("#%d %d\n", i, out);
	}
}
