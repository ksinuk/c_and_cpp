#define FREOPEN
//#define DEBUG
#include <iostream>

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int cal_main(int size) {
	int map[10][10] = {0};
	int stack[10] = {0};
	int history[10] = {0};
	int sum[10] = {0};
	

	for(int y = 0; y<size; y++)
		for(int x = 0; x<size; x++) scanf("%d" , &map[y][x]);

	int min = 0;
	for(int i = 0; i<size; i++) min += map[i][i];

	for(int i = 0; i<size; i++) {
		stack[i] = i;
		history[i] = i;
	}
	int index = 0;
	

	while(index>=0) {
		sum[index] = map[index][stack[index]]+((index==0) ? 0 : sum[index-1]);
		if(index==size-1) {
			min = (sum[index]<min) ? sum[index] : min;
		}

		if(index!=size-1&&sum[index]<=min) {
			index++;
		}
		else {
			while(index>=0&&history[index]==size-1) {
				swap(stack[index] , stack[history[index]]);
				history[index--] = index;
			}
			if(index<0) break;

			swap(stack[index] , stack[history[index]]);
			history[index]++;
			swap(stack[index] , stack[history[index]]);
		}
	}

	return min;
}

int main(void)
{
	int N = 1;
#ifdef FREOPEN
	freopen("건물세우기.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	for(int i = 0; i<N; i++) {

		int size; scanf("%d" , &size);
		int out = cal_main(size);

		printf("%d\n" , out);
#ifdef FREOPEN
		printf("-----------------------\n");
#endif // FREOPEN
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
