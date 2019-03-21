//#define DEBUG
#include <iostream>

const char *patterns_in[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
int patterns[10];
const char *table16[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

int string_equal(char a[], char b[], int size) {
	for (int i = 0; i < size; i++)	{
		if (a[i] != b[i]) return -1;
	}
	return 0;
}
int string_copy(char from[], char to[], int size) {
	for (int i = 0; i < size; i++) {
		to[i] = from[i];
	}
	return 0;
}
inline int index16(char c) {
	if (c >= 'A') return c - 'A' + 10;
	else return c - '0';
}
int search(char *table, int y, int xin, int xsize, char *password) {
	int len = 0;

	int cnt = 0;
	char pre = '0';

	for (int x = xin; x < xsize; x++) {
		for (int i = 0; i < 4; i++) {
			char c = table[y*xsize + x];
			char temp = table16[index16(c)][i];
			password[len++] = temp;
			if (pre != temp) {
				pre = temp;
				cnt++;
			}
		}
		if (cnt > 31) break;
	}
	password[len] = 0;
	return len;
}
int decoding(char *password, int len) {	
	while (password[len - 1] == '0') {
		password[len-1] = 0;
		len--;
	}
	int start = 0;
	for (; password[start] == '0'; start++);

	int other0 = (56-(len-start)%56)%56;
	int d = (len - start + other0)/56;
	int d56 = d * 56;
	int code[8] = { 0 };
	int now_i = len-1;

	for (int i = 0; i<8; i++) {
		int num = 0;
		for (int j = 0; j < 7; j++) {
			char c = '0';
			if (start <= now_i) { 
				c = password[now_i]; 
				now_i -= d;
			}
			num += (1 << j)*(c-'0');
		}
		for (int j = 0; j < 10; j++) {
			if (patterns[j] == num) {
				code[7 - i] = j;
				break;
			}
		}
	}

	int out = 0;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) out += 3 * code[i];
		else out += code[i];
		sum += code[i];}
	
	return (out%10==0) ? sum:0 ;
}



int cal(int ysize_in, int xsize) {
	char *table = new char[ysize_in*xsize];
	int ysize = 0;
	char *pre= new char[xsize+1];
	pre[0] = 0;

	for (int i = 0; i < ysize_in; i++) {
		char *now = new char[xsize+1];
		scanf("%s", now);

		if (string_equal(now, pre, xsize)) {
			string_copy(now, pre, xsize + 1);
			string_copy(now, table+ysize*xsize, xsize);
			ysize++;
		}

		delete[]now;
	}
	delete[] pre;

	int out = 0;
	for (int y = 0; y < ysize; y++) {
		for (int x = 0; x < xsize; x++) {
			if (table[y*xsize + x] != '0' && (y == 0 || table[(y - 1)*xsize + x] == '0')) {
				char *password=new char[xsize*4+1];
				int len = search(table, y, x, xsize, password);
				x += len/4 - 1;
				out += decoding(password, len);
				delete[] password;
			}
		}
	}

	delete[] table;
	return out;
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	for (int i = 0; i < 10; i++) {
		int out = 0;
		for (int j = 0; j < 7; j++) out += (patterns_in[i][j] - '0')*(1 << (6 - j));
		patterns[i] = out;
	}

	int T;
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++) {
		int ysize, xsize;
		scanf("%d", &ysize); scanf("%d", &xsize);
		printf("#%d %d\n", testcase, cal(ysize , xsize));
	}

	return 0;    
}
