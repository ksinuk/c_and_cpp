#include <string>
#include <vector>
#include <iostream>

using namespace std;

int len_num(int cnt) {
	if(cnt >= 1000) return 4;
	else if(cnt >= 100) return 3;
	else if(cnt >= 10) return 2;
	else if(cnt > 1) return 1;
	return 0;
}

int cal(string s , int n) {
	int out = 0;
	char now[1001] = {0};
	int cnt = 0 , len = 0;
	for(int i = 0; i < s.size( ); i += n) {
		char tmp[1001] = {0};
		int same = 1 , len_now = 0;
		for(int j = i; j < i + n; j++) {
			if(j == s.size( )) {
				same = 0;
				break;
			}
			len_now++;
			tmp[j - i] = s[j];
			if(tmp[j - i] != now[j - i]) same = 0;
		}
		if(same) cnt++;
		else {
			out += len_num(cnt) + len;
			for(int i = 0; i < len_now; i++) now[i] = tmp[i];
			len = len_now;
			now[len] = 0;
			cnt = 1;
		}
	}
	out += len_num(cnt) + len;
	return out;
}

int solution(string s) {
	int answer = 1000000;
	for(int i = 1; i <= s.size( ) / 2; i++) {
		int tmp = cal(s , i);
		cout << i << " , " << tmp << endl;
		answer = answer < tmp ? answer : tmp;
	}

	return answer;
}

int main( )
{
	string s = "aabbaccc";
	cout << solution(s) << endl;
}