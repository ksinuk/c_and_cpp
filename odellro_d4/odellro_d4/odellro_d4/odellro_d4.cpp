#define DEBUG 
#include <iostream>
using namespace std;

int cal() {
	int size;
	cin >> size;
	char table[1001][1001];
	int xli[1001] = { 0 };
	int yli[1001] = { 0 };

	for (int y = 0; y < size; y++) {
		char str[1002];
		cin >> str;
		for (int x = 0; x < size; x++) {
			char c=str[x];
			if (c == 'B') {
				table[y][x] = 1;
				xli[x]++;
				yli[y]++;
			}
			else table[y][x] = 0;
		}
	}
		
	int out = 0;
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++) {
			int temp = yli[y] + xli[x] - table[y][x];
			if (temp % 2) out++;
		}

	return out;
}



int main()
{
	int T;
#ifdef DEBUG
	freopen("sample_input.txt", "r", stdin);
#endif // DEBUG

	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int out = cal();
		cout << '#' << test_case << ' ' << out << endl;
	}
#ifdef DEBUG
	while (1) {}
#endif // DEBUG
	return 0;
}
