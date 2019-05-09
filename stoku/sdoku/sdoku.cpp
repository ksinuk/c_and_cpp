#include <iostream>



int cal_main() {
	int table[9][9] = {0};

	for(int y = 0; y<9; y++) {
		for(int x = 0; x<9; x++) {
			scanf("%1d" , &table[y][x]);
		}
	}

	int check_x[9][9] = {0};
	int check_y[9][9] = {0};
	int check_block[3][3][9] = {0};
	int check_num[9][9][9] = {0};

	for(int y = 0; y<9; y++) {
		for(int x = 0; x<9; x++) {
			if(table[y][x]) {
				if(check_y[y][table[y][x]] || check_x[x][table[y][x]]) return -1;
				if(check_block[y/3][x/3][table[y][x]])  return -1;
				if(check_num[y][x][table[y][x]])  return -1;
				check_y[y][table[y][x]] = check_x[x][table[y][x]] = 1;
				check_num[y][x][table[y][x]] = check_block[y/3][x/3][table[y][x]] = 1;
			}
		}
	}

	return 0;
}

int main()
{
	freopen("input.txt" , "r" , stdin); 

	int out = cal_main();
	return 0;
}
