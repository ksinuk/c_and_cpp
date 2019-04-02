/*
#define FREOPEN
#include <iostream>

char table[501][501];

inline void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

char game(int k1 , int k2 , int ball[] , char player) {
	if(k1<k2) swap(k1 , k2);
	char other = (player=='A') ? 'B' : 'A';

	if(table[k1][k2]==1) return player;
	else if(table[k1][k2]==2) return other;

	if(k1==k2) {
		table[k1][k2] = 2;
		return other;
	}

	for(int i = 0; i<3; i++) {
		if(k1-ball[i]==k2) {
			table[k1][k2] = 1;
			return player;
		}
	}

	for(int i = 0; i<3; i++) {
		if(k1>=ball[i]) {
			char result = game(k1-ball[i] , k2 , ball , other);
			if(result==player) {
				table[k1][k2] = 1;
				return player;
			}
		}
	}
	for(int i = 0; i<3; i++) {
		if(k2>=ball[i]) {
			char result = game(k1 , k2-ball[i] , ball , other);
			if(result==player) {
				table[k1][k2] = 1;
				return player;
			}
		}
	}

	table[k1][k2] = 2;
	return other;
}

int main() {
	int N = 1;
#ifdef FREOPEN
	freopen("구슬게임.txt" , "r" , stdin);
	scanf("%d" , &N);
#endif // FREOPEN
	//scanf("%d" , &N);

	for(int i = 0; i<N; i++) {
		int ball[3] = {0};
		scanf("%d %d %d" , ball , ball+1 , ball+2);
		for(int j = 0; j<5; j++) {
			int k[2] = {0};
			scanf("%d %d" , k , k+1);
			if(k[0]<k[1]) swap(k[0] , k[1]);

			for(int i = 0; i<=k[0]; i++) {
				for(int j = 0; j<=k[0]; j++) {
					table[i][j] = 0;
				}
			}

			printf("%c\n" , game(k[0] , k[1] , ball , 'A'));
		}
	}

	return 0;
}

*/