/*
#include <iostream>
using namespace std;

int cal_main() {
	int size;
	int in_list[101] = { 0 };
	int sum = 0 , min=200 , max = -1;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		int temp;
		scanf("%d", &temp);
		in_list[temp]++;
		sum += temp;
		if (min > temp) min = temp;
		else if (max < temp) max = temp;
	}
	//--------------------------------------
	int out = 1;
	int score_list[100005] = {1, 0 };
	int score_in[100005] ={0};
	int index = 0;
	int pre = 0;

	for (int score = min; score <= max; score++) {
		if(in_list[score]==0) continue;
		for(int i=1; i<=in_list[score]; i++){
			if(score_list[score*i]==0){
				score_list[score*i] = 1;
				out++;
				score_in[index++] = score*i;
			}
			for(int j=0; j<pre; j++){
				int temp = score_in[j]+score*i;
				if(score_list[temp]==0){
					score_list[temp] = 1;
					out++;
					score_in[index++] = temp;
				}
			}
		}
		pre = index;
	}

	return out;
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


*/