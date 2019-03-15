#define DEBUG 
#include <iostream>
//using namespace std;

char str[1002];

int cal(bool *table) {
	int size, ys=0;
	scanf("%d",&size);
	bool xli[1001] = { 0 };
	bool yli[1001] = { 0 };


	for (int y = 0; y < size; y++) {
		scanf("%s", str);
		for (int x = 0; x < size; x++) {
			if (str[x] == 'B') {
				table[ys++] = 1;
				xli[x]^=1;
				yli[y] ^= 1;
			}
			else table[ys++] = 0;
		}
	}

	int out = 0;
	bool temp;
	ys = 0;
	for (int y = 0; y < size; y++) {
		int yy = yli[y];
		for (int x = 0; x < size; x++) {
			temp = yy ^ xli[x] ^ table[ys++];
			if (temp) out++;
		}
	}

	return out;
}


int main()
{
	int T;
#ifdef DEBUG
	freopen("sample_input.txt", "r", stdin);
#endif // DEBUG

	bool *table = new bool[1000001];
	
	
	scanf("%d",&T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		printf("#%d %d\n", test_case, cal(table));
	}

	delete[] table;
#ifdef DEBUG
	while (1) {}
#endif // DEBUG
	return 0;
}
