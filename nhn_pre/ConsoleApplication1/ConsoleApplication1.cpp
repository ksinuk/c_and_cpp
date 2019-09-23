#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main( ) {
	freopen("input.txt" , "r" , stdin);
	int size , turn;
	cin >> size >> turn;
	string table[100][100];
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cin >> table[i][j];

	for(int i = 0; i < size / 2; i++) {
		vector<string> list;
		int turn_size = size - 2 * i - 1;

		int turn_cnt = turn < 0 ? -turn : turn;
		turn_cnt = turn_cnt % (4 * turn_size);
		if(turn_cnt == 0) {
			turn *= -1;
			continue;
		}

		if(turn > 0) {
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[i][i + idx]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[i + idx][size - 1 - i]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[size - 1 - i][size - 1 - i - idx]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[size - 1 - i - idx][i]);
		}
		else {
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[i + idx][i]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[size - 1 - i][i + idx]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[size - 1 - i - idx][size - 1 - i]);
			for(int idx = 0; idx < turn_size; idx++)
				list.push_back(table[i][size - 1 - i - idx]);
		}

		vector<string> other;
		for(int idx = 0; idx < turn_cnt; idx++) {
			other.push_back(list.back( ));
			list.pop_back( );
		}
		reverse(list.begin( ) , list.end( ));
		reverse(other.begin( ) , other.end( ));
		while(other.size( )) {
			list.push_back(other.back( ));
			other.pop_back( );
		}

		if(turn > 0) {
			for(int idx = 0; idx < turn_size; idx++) {
				table[i][i + idx] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[i + idx][size - 1 - i] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[size - 1 - i][size - 1 - i - idx] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[size - 1 - i - idx][i] = list.back( );
				list.pop_back( );
			}
		}
		else {
			for(int idx = 0; idx < turn_size; idx++) {
				table[i + idx][i] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[size - 1 - i][i + idx] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[size - 1 - i - idx][size - 1 - i] = list.back( );
				list.pop_back( );
			}
			for(int idx = 0; idx < turn_size; idx++) {
				table[i][size - 1 - i - idx] = list.back( );
				list.pop_back( );
			}
		}

		turn *= -1;
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size - 1; j++) {
			cout << table[i][j] << ' ';
		}
		cout << table[i][size - 1] << endl;
	}




	return 0;
}